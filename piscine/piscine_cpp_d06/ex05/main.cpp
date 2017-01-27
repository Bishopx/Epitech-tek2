#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "sickkoala.h"
#include "koalanurse.h"
#include "koaladoctor.h"

int main() {
  KoalaDoctor doctor("Chris");
  SickKoala koala("Thomas");
  KoalaNurse nurse(9);

  std::cout << doctor.getName() << std::endl;
  std::cout << nurse.getId() << std::endl;
  doctor.timeCheck();
  srandom(time(NULL));
  doctor.diagnose(&koala);
  nurse.readReport("Thomas");
  doctor.timeCheck();
  return 0;
}
