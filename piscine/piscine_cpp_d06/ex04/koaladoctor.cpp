#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "sickkoala.h"
#include "koalanurse.h"
#include "koaladoctor.h"

KoalaDoctor::KoalaDoctor(std::string name) {
  this->name = name;
  this->statut = false;
  std::cout << "Dr. "<< this->name<< ": Je suis le Dr." << this->name << "! Comment Kreoggez-vous ?" << std::endl;
}

KoalaDoctor::~KoalaDoctor() {
}

void KoalaDoctor::timeCheck() {
  if (this->statut == true) {
      this->statut = false;
      std::cout << "Dr. " << this->name << ": Je rentre dans ma foret d'eucalyptus !" << std::endl;
  } else {
      this->statut = true;
      std::cout << "Dr. " << this->name << ": Je commence le travail !" << std::endl;
  }
}

void KoalaDoctor::diagnose(SickKoala *koala) {
  std::string filename, drug;
  std::string drugs[ ] = {"mars", "Buronzand", "Viagra", "Extasy", "Feuille d'eucalyptus"};
  int i;
  std::ofstream file;

  std::cout << "Dr. "<< this->name<< ": Alors qu'est-ce qui vous goerk Mr." << koala->getName() << std::endl;
  koala->poke();
  filename = koala->getName();
  filename += ".report";
  i =random() % 5;
  drug = drugs[i];
  file.open(filename.c_str(), std::ios::out | std::ios::trunc);
  if (file.is_open())
    file << drug;
}
