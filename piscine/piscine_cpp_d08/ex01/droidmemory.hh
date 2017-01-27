#ifndef _DROIDMEMORY_H_
# define _DROIDMEMORY_H_

# include <ostream>
# include <string>

class DroidMemory
{
private:
	size_t	FingerPrint;
	size_t	Exp;
public:
	DroidMemory();
	DroidMemory(DroidMemory const &);					
	DroidMemory & operator=(DroidMemory const &);	
	~DroidMemory();
public:
	size_t const &getFingerPrint() const;
	size_t const &getExp() const;

	void	setFingerPrint(size_t);
	void	setExp(size_t);

	DroidMemory &operator<<(DroidMemory const &);
	DroidMemory &operator>>(DroidMemory &);
	DroidMemory &operator+=(DroidMemory const &);
	DroidMemory &operator+=(size_t const &);
	DroidMemory &operator+(DroidMemory const &);
	DroidMemory &operator+(size_t const &);
};

std::ostream &operator<<(std::ostream &, DroidMemory const &);
#endif /* ! _DROIDMEMORY_H_ */
