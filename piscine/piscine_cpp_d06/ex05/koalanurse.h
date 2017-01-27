#ifndef _KOALANURSE_H_
# define _KOALANURSE_H_

class KoalaNurse{
  int Id;
  bool statut;

public:
  KoalaNurse(int Id);
  ~KoalaNurse();
  void giveDrug(std::string drug, SickKoala *koala);
  void timeCheck();
  std::string readReport(std::string drug);
  int getId();
};

#endif /* ! _KOALANURSE_H */
