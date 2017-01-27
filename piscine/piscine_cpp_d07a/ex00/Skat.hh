#ifndef _SKAT_H_
# define _SKAT_H_

class  Skat {
	private:
		int	_stimPaks;
		std::string _name;
	public:
		Skat(std::string const &name = "bob", int stimPaks = 15);
		~Skat();
	public:
		int	&stimPaks();
		std::string const &name() const;
	public:
		void shareStimPaks(int number, int &stock);
		void addStimPaks(unsigned int number);
		void useStimPaks();		
	public:
		void status();					
};

#endif /* ! _SKAT_H_ */
