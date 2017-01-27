#ifndef _FEDERATION_H_
# define _FEDERATION_H_

#include "Warpsystem.hh"

namespace Federation {
	namespace Starfleet {
		class 		Ship {
			int		_length;
			int		_width;
			std::string	_name;
			short	_maxWrap;
			WarpSystem::Core 	*_core;

		public:
			Ship(int length, int width, std::string name, short maxWrap);
			void	getName();
			void	setupCore(WarpSystem::Core *);
			void	checkCore();

		};
	};

	class  Ship {
			int		_length;
			int		_width;
			std::string	_name;
			short	_maxWrap;
			WarpSystem::Core 	*_core;

		public:
			Ship(int length, int width, std::string name);
			void	getName();
			void	setupCore(WarpSystem::Core *);
			void	checkCore();		
	};
};

#endif /* ! _FEDERATION_H_ */
