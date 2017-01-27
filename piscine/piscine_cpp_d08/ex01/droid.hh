#ifndef _DROID_H_
# define _DROID_H_

# include <iostream>
# include <string>
# include "droidmemory.hh"

class  Droid {
	private:
		std::string	Id;
		size_t		Energy;
		size_t const Attack;
		size_t const Toughness;
		std::string	*Status;
		DroidMemory *BattleData;

	public:
		Droid(std::string, DroidMemory *);
		Droid(Droid const &);					
		Droid & operator=(Droid const &);
		~Droid();
	public:
		std::string const &getId() const;
		size_t const &getEnergy() const;
		size_t const &getAttack() const;
		size_t const &getToughness() const;
		std::string const &getStatus() const;
		DroidMemory const &getBattleData() const;

		void		setId(std::string Id);
		void		setEnergy(size_t Energy);
		void		setStatus(std::string *Status);
		void		setBattleData(DroidMemory *BattleData);

		Droid		&operator<<(size_t &);
};

std::ostream &operator<<(std::ostream &, Droid const &); 
bool		operator==(Droid const &, Droid const &);
bool		operator!=(Droid const &, Droid const &);

#endif /* ! _DROID_H_ */
