#ifndef _BORG_H_
# define _BORG_H_

#include "Warpsystem.hh"
#include "Destination.hh"

namespace Borg {
	class  Ship {
			int		_side;
			short	_maxWarp;
			WarpSystem::Core 	*_core;
			Destination			_location;
			Destination 		_home;

		public:
			Ship();
			void	setupCore(WarpSystem::Core *);
			void	checkCore();
			bool	move(int warp, Destination d);
			bool	move(int warp);
			bool	move(Destination d);
			bool	move();							
	};
};

#endif /* ! _BORG_H_ */
