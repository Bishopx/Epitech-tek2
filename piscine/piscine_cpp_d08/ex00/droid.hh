#ifndef _DROID_H_
# define _DROID_H_

# include <ostream>
# include <string>

class  Droid {
	private:
		std::string	Id;
		size_t		Energy;
		size_t const Attack;
		size_t const Toughness;
		std::string	*Status;	
	public:
		Droid();
		Droid(std::string);
		Droid(std::string, size_t);
		Droid(Droid const &);					
		Droid & operator=(Droid const &);
		~Droid();
	public:
		std::string const &getId() const;
		size_t const &getEnergy() const;
		size_t const &getAttack() const;
		size_t const &getToughness() const;
		std::string const &getStatus() const;

		void		setId(std::string Id);
		void		setEnergy(size_t Energy);
		void		setStatus(std::string *Status);
		Droid		&operator<<(size_t &);
};

std::ostream &operator<<(std::ostream &, Droid const &); 
bool		operator==(Droid const &, Droid const &);
bool		operator!=(Droid const &, Droid const &);

#endif /* ! _DROID_H_ */
