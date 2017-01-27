#include <iostream>
#include <fstream>
#include <string>

int main (int ac, char **av) {
  std::string line;
  std::ifstream myfile;
  int	i = 1;
  char c;

  if (ac == 1) {
  	std::cout << "my_cat: Usage : ./my_cat file [...]" << std::endl;
  	return (1);
 }
  while (av[i]) {
  	myfile.open(av[i], std::ios::in);
  	if (myfile.is_open()) {
       while (myfile.get(c))
         std::cout << c;
         myfile.close();
  	} else
  		std::cerr << "my_cat: <" << av[i] << ">: No such file or directory" << std::endl;
  	i++;
}

  return 0;
}
