#ifndef _BORG_H_
# define _BORG_H_

#include "Warpsystem.hh"
#include "Destination.hh"
#include "Federation.hh"

namespace Borg {
	class  Ship {
			int		_side;
			short	_maxWarp;
			int		_shield;
			int		_weaponFrequency;
			short	_repair;
			WarpSystem::Core 	*_core;
			Destination			_location;
			Destination 		_home;

		public:
			Ship(int weapon);
			Ship(int weapon, int _repair);
			void	setupCore(WarpSystem::Core *);
			void	checkCore();
			bool	move(int warp, Destination d);
			bool	move(int warp);
			bool	move(Destination d);
			bool	move();	
			int getShield();
			void setShield(int);
			int getWeaponFrequency();
			void setWeaponFrequency(int);
			short getRepair();
			void setRepair(short);
			void	fire(Federation::Starfleet::Ship *ship);
			void	fire(Federation::Ship *ship);
			void	repair();
	};
};

#endif /* ! _BORG_H_ */
