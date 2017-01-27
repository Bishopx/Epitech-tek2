#ifndef _BORG_H_
# define _BORG_H_

#include "Warpsystem.hh"
#include "Destination.hh"
#include "Federation.hh"

namespace Borg {
	class Ship {

	};
};

namespace Starfleet {
	class Admiral
	{
		std::string _name;
	public:
		Admiral(std::string name);
		~Admiral();
		void fire(Federation::Starfleet::Ship *, Borg::Ship *);
		bool move(Federation::Starfleet::Ship*, Destination);

	};
};

#endif /* ! _BORG_H_ */
