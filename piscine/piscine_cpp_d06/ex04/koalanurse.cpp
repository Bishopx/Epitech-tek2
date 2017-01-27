#include <iostream>
#include <fstream>
#include <string>
#include "sickkoala.h"
#include "koalanurse.h"

KoalaNurse::KoalaNurse(int Id) {
  this->Id = Id;
  this->statut = false;
}

KoalaNurse::~KoalaNurse() {
  std::cout << "Nurse "<< this->Id<< ": Enfin un peu de repos !" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *koala) {
  koala->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string name) {
  std::string filename, str;
    std::ifstream file;
    std::string drugname;
    char c;
    size_t pos;

    if ((pos = name.find(".report")) != std::string::npos)
      str = name.substr(0, pos);
    file.open(name.c_str(), std::ios::in);
    if (file.is_open()) {
       while (file.get(c)) {
         if (c != '\n')
          drugname += c;
       }
         file.close();
         std::cout << "Nurse " << this->Id << ": Kreog ! Il faut donner un " << drugname << " a Mr." << str <<" !" << std::endl;
       }
       return (drugname);
}

void KoalaNurse::timeCheck() {
  if (this->statut == true) {
      this->statut = false;
      std::cout << "Nurse " << this->Id << ": Je rentre dans ma foret d'eucalyptus !" << std::endl;
  } else {
      this->statut = true;
      std::cout << "Nurse " << this->Id << ": Je commence le travail !" << std::endl;
  }
}
