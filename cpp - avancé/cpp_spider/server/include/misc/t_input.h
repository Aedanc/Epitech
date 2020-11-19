//
// Created by baldas on 10/6/17.
//

#ifndef     CPP_SPIDER_T_INPUT_H
# define    CPP_SPIDER_T_INPUT_H

# include   <stdint.h>

struct      s_input
{
    char		process[32];
    int64_t		timestamp;
    int16_t		posX;
    int16_t		posY;
    uint8_t		inputCode;
    uint8_t		specialKey;
};

using   t_input = s_input;

#endif      // !CPP_SPIDER_T_INPUT_H
