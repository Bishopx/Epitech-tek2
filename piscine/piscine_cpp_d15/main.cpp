#include "ex00.hpp"
#include <iostream>
#include <string>

int main() {
 int a = 2;
 int b = 3;

 ::swap(a, b);
 std::cout << "a = " << a << ", b = " << b << std::endl;
 std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
 std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
 std::cout << "add(a, b) = " << ::add(a, b) << std::endl;

 std::string c = "chaine1";
 std::string d = "chaine2";

 ::swap(c, d);
 std::cout << "c = " << c << ", d = " << d << std::endl;
 std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
 std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
 std::cout << "add(c, d) = " << ::add(c, d) << std::endl;
	return 0;
}

#include "ex01.hpp"
#include <iostream>
#include <string>

 class toto
 {
 private:
 toto &operator=(const toto&) {return *this;}
 toto(const toto &){}

 public: 	
 bool operator==(const toto&) const {return true;}
 bool operator>(const toto&) const {return false;}
 bool operator<(const toto&) const {return false;}
 toto(){}
 };

 
int main() {
 toto a, b;
 std::cout << "Compare Toto : " << compare(a, b) << std::endl;
 std::cout << "Compare 1 et 2 : " << compare(1, 2) << std::endl;
 std::cout << "Compare const char * : " << compare<const char*>("chaineZ", "chaineA42") << std::endl;
 const char *s1 = "42", *s2 = "lulz";
 std::cout << "Compare const char * : " <<  compare(s1, s2) << std::endl;

}

#include "ex02.hpp"

int main() {
int tab[2] = {3, 0};
 int minimum = templateMin(tab, 2);
 std::cout << "templateMin(tab, 2) = " << minimum << std::endl;
 minimum = nonTemplateMin(tab, 2);
 std::cout << "nonTemplateMin(tab, 2) = " << minimum << std::endl;
return 0;
}

#include "ex03.hpp"
#include <iostream>
#include <string>

int main(void) {
 int tab[] = { 11, 3, 89, 42 };
 int b  = 4;
 foreach(tab, print<int>, 4);
 std::string tab2[] = { "j’", "aime", "les", "templates", "!" };
 foreach(tab2, print, 5);
 return 0;
 }

 #include "ex06.hpp"

int main() {
	Tuple<int> t;

	t.a = 42;
	t.b = 21;

	std::cout << t.toString() << std::endl;

 Tuple<float, char> test;
 test.a = 1.1f;
 test.b = 'x';
 std::cout << test.toString() << std::endl;	
  Tuple<int, std::string> test1;
 test1.a = 42;
 test1.b = std::string("Boeuf aux oignons");
 std::cout << test1.toString() << std::endl;
	return 0;
}