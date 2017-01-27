#ifndef _KOALADOCTOR_H_
# define _KOALADOCTOR_H_

class KoalaDoctor{
  std::string name;
  bool statut;

public:
  KoalaDoctor(std::string name);
  ~KoalaDoctor();
  void diagnose(SickKoala *koala);
  void timeCheck();
};

#endif /* ! _KOALADOCTOR_H_H */
