#ifndef _BORG_H_
# define _BORG_H_

#include "Warpsystem.hh"

namespace Borg {
	class  Ship {
			int		_side;
			short	_maxWrap;
			WarpSystem::Core 	*_core;

		public:
			Ship();
			void	setupCore(WarpSystem::Core *);
			void	checkCore();				
	};
};

#endif /* ! _BORG_H_ */
