#ifndef _FEDERATION_H_
# define _FEDERATION_H_

#include "Warpsystem.hh"
#include "Destination.hh"

namespace Borg {
	class Ship;
};

namespace Federation {
	namespace Starfleet {
		class 		Captain
		{
			std::string _name;
			int		_age;

		public:
			Captain(std::string name);
			std::string 	getName();
			int				getAge();
			void			setAge(int);
		};
		
		class 		Ship {
			int		_length;
			int		_width;
			int		_shield;
			int		_photonTorpedo;
			std::string	_name;
			short	_maxWarp;
			WarpSystem::Core 	*_core;
			Captain				*_captain;
			Destination			_location;
			Destination 		_home;

		public:			
			Ship();
			Ship(int length, int width, std::string name, short maxWrap, int torpedo);
			void	getName();
			void	setupCore(WarpSystem::Core *);
			void	checkCore();
			void	promote(Captain *);
			bool	move(int warp, Destination d);
			bool	move(int warp);
			bool	move(Destination d);
			bool	move();
			int 	getShield();
			void 	setShield(int);
			int 	getTorpedo();
			void 	setTorpedo(int);
			void 	fire(Borg::Ship *ship);
			void 	fire(int torpedoes, Borg::Ship *ship);
		};

		class 		Ensign {
			std::string _name;
		public:
			explicit Ensign(std::string name);
		};
	};

	class  Ship {
			int		_length;
			int		_width;
			std::string	_name;
			short	_maxWarp;
			WarpSystem::Core 	*_core;
			Destination			_location;
			Destination 		_home;
		public:
			Ship(int length, int width, std::string name);
			void	getName();
			void	setupCore(WarpSystem::Core *);
			void	checkCore();
			bool	move(int warp, Destination d);
			bool	move(int warp);
			bool	move(Destination d);
			bool	move();
			WarpSystem::Core *getCore();						
	};
};

#include "Borg.hh"

#endif /* ! _FEDERATION_H_ */
