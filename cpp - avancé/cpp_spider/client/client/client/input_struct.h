//
//	Created by hugo.baladssin@epitech.eu on 27/09/17
//

#ifndef			INPUT_STRUCT_H_
# define		INPUT_STRUCT_H_

# include		<stdint.h>

struct			s_input
{
	char		process[32];
	int64_t		timestamp;
	int16_t		posX;
	int16_t		posY;
	uint8_t		inputCode;
	uint8_t		specialKey;
};

using t_input = s_input;

#endif			/* !INPUT_STRUCT */