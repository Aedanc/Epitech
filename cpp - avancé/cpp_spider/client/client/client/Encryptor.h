//
//	Created by sylvain.chaugny@epitech.eu on 03/10/17
//

#ifndef		ENCRYPTOR_H
# define	ENCRYPTOR_H

namespace spider
{
	namespace client
	{
		class		Encryptor {
		public:
			bool	init();
			void	encrypt();
			void	decrypt();

		private:
		};
	};
};

#endif		/* !ENCRYPTOR_H */