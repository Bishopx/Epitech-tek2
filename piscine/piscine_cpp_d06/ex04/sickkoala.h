#ifndef _SICKKOALA_H_
# define _SICKKOALA_H_

class SickKoala {
  std::string name;

public:
  SickKoala(std::string);
  ~SickKoala();
  void poke();
  bool takeDrug(std::string drug);
  void overDrive(std::string drive);
  std::string getName();
};

#endif /* ! _SICKKOALA_H */
