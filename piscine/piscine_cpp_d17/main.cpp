#include "do_find.hpp"

#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector

int main () {
  // using std::find with array and pointer:
  int myints[] = { 10, 20, 30, 40, 10 };
  int * p;

  p = std::find (myints, myints+4, 30);
  if (p != myints+4)
    std::cout << "Element found in myints: " << *p << '\n';
  else
    std::cout << "Element not found in myints\n";

  // using std::find with vector and iterator:
  std::vector<int> myvector (myints,myints+4);
  std::vector<int>::iterator it;

  it = do_find(myvector, 10);
  if (it != myvector.end())
    std::cout << "Element found in myvector: " << *it << '\n';
  else
    std::cout << "Element not found in myvector\n";

  return 0;
}


#include "MyAlgorithms.hpp"

#include <vector>
#include <iostream>
#include <iomanip>

static bool isGreaterThan(int a, int b)
{
  return a > b;
}

static void showMe(int i)
{
  std::cout << std::setw(4) << i << ", ";
}

static void mult2(int& i)
{
  i *= 2;
}

int main()
{
  int tab[] = { 4, 9, 1, 1, 99, 8, 42, 42, 42, -1, 3 };
  int tab2[] = { 99, 1, -42, 21, 12, 21, 99, -7, 42, 42};

  std::vector<int> v1(tab, tab + sizeof(tab) / sizeof(*tab));
  std::vector<int> v2(tab2, tab2 + sizeof(tab2) / sizeof(*tab2));
  std::vector<int>::iterator it;

  std::cout << "============ Step 01 ==========" << std::endl;
  vPrint(v1, &showMe);
  vPrint(v2, &showMe);

std::cout << "============ Step 02 ==========" << std::endl;
  std::cout << vHowMany(v1, 42) << std::endl;
  std::cout << vHowMany(v2, 421) << std::endl;

  std::cout << "============ Step 03 ==========" << std::endl;
  std::cout << std::boolalpha << vIsSimilar(v1, tab) << std::endl;
  std::cout << std::boolalpha << vIsSimilar(v1, tab2) << std::endl;
  std::cout << std::boolalpha << vIsSimilar(v2, tab) << std::endl;
  std::cout << std::boolalpha << vIsSimilar(v2, tab2) << std::endl;

  std::cout << "============ Step 04 ==========" << std::endl;
  vPrint(v1, &showMe);
  vAssign(v1.begin() + 3, v1.begin() + 5, -421);
  vPrint(v1, &showMe);

  std::cout << "============ Step 05 ==========" << std::endl;
  vPrint(v1, &showMe);
  vApply(v1.begin() + 1, v1.begin() + 10, &mult2);
  vPrint(v1, &showMe);

  std::cout << "============ Step 06 ==========" << std::endl;
  vPrint(v1, &showMe);
  it = vGiveMeTheFirst(v1, 84);
  if (it != v1.end())
    v1.erase(it, it + 3);
  vPrint(v1, &showMe);

std::cout << "============ Step 07 ==========" << std::endl;
  vPrint(v2, &showMe);
  vFlip(v2);
  vPrint(v2, &showMe);

  std::cout << "============ Step 08 ==========" << std::endl;
  vPrint(v2, &showMe);
  std::vector<int>::iterator newEnd = vRemoveDuplicate(v2);
  v2.resize(newEnd - v2.begin());
  vPrint(v2, &showMe);

  std::cout << "============ Step 09 ==========" << std::endl;
  vPrint(v1, &showMe);
  vToAscOrder(v1);
  vPrint(v1, &showMe);

  std::cout << "============ Step 10 ==========" << std::endl;
  vPrint(v2, &showMe);
  vToSpecificOrder(v2, &isGreaterThan);
  vPrint(v2, &showMe);

  std::cout << "============ Step 11 ==========" << std::endl;
  vPrint(v2, &showMe);
  vShift(v2, 3);
  vPrint(v2, &showMe);
  vShift(v2, 7);
  vPrint(v2, &showMe);

  std::cout << "============ Step 12 ==========" << std::endl;
  vPrint(v2, &showMe);
  vFindAndModify(v2, 21, 777);
  vPrint(v2, &showMe);

std::cout << "============ Step 13 ==========" << std::endl;
  vPrint(v2, &showMe);
  newEnd = vFindAndKill(v2, 777);
  v2.resize(newEnd - v2.begin());
  vPrint(v2, &showMe);

  std::cout << "============ Step 14 ==========" << std::endl;
  std::vector<int> v3(v1.size() + v2.size());

  vToAscOrder(v1);
  vToAscOrder(v2);
  vPrint(v1, &showMe);
  vPrint(v2, &showMe);
  vPrint(v3, &showMe);
  vFusionOrderedLists(v1, v2, v3);
  vPrint(v3, &showMe);

  return 0;
}


#include "Cesar.h"
#include "OneTime.h"
 #include <string>
 #include <iostream>

 static void encryptString(IEncryptionMethod& encryptionMethod,
 std::string const& toEncrypt)
 {
 size_t len = toEncrypt.size();

 encryptionMethod.reset();
 for (size_t i = 0; i < len; ++i)
 {
 encryptionMethod.encryptChar(toEncrypt[i]);
 }
 std::cout << std::endl;
 }

 static void decryptString(IEncryptionMethod& encryptionMethod,
 std::string const& toDecrypt)
 {
 size_t len = toDecrypt.size();

 encryptionMethod.reset();
 for (size_t i = 0; i < len; ++i)
 {
 encryptionMethod.decryptChar(toDecrypt[i]);
 }
 std::cout << std::endl;
 }

 int main()
 {
 Cesar c;

 OneTime o("DedeATraversLesBrumes");
 OneTime t("TheCakeIsALie");

 encryptString(c, "Je clair Luc, ne pas ? Ze woudrai un kekos !");
 decryptString(c, "Mi isirb Xhq, ew jvo ? Zf zszjyir fz ytafk !");
 encryptString(c, "KIKOO");
 encryptString(c, "LULZ XD");
 decryptString(c, "Ziqivun ea Ndcsg.Wji !");

 encryptString(t, "Prend garde Lion, ne te trompes pas de voie !");
 encryptString(o, "De la musique et du bruit !");
 encryptString(t, "Kion li faras? Li studas kaj programas!");

 decryptString(t, "Iyipd kijdp Pbvr, xi le bvhttgs tik om ovmg !");
 decryptString(o, "Gi pa dunmhmp wu xg tuylx !");
 decryptString(t, "Dpsp vm xaciw? Pk cxcvad otq rrykzsmla!");
 return 0;
 }


 #include "Encryption.h"
 #include "Cesar.h"
 #include "OneTime.h"
 #include <string>
 #include <iostream>

 static void encryptString(IEncryptionMethod& encryptionMethod, std::string const& toEncrypt)
 {
 Encryption e(encryptionMethod, &IEncryptionMethod::encryptChar);

 encryptionMethod.reset();
 size_t len = toEncrypt.size();
 for (size_t i = 0; i < len; ++i)
 {
 e(toEncrypt[i]);
 }
 std::cout << std::endl;
 
}

 static void decryptString(IEncryptionMethod& encryptionMethod, std::string const& toDecrypt)
 {
 Encryption e(encryptionMethod, &IEncryptionMethod::decryptChar);

 encryptionMethod.reset();
 size_t len = toDecrypt.size();
  for (size_t i = 0; i < len; ++i)
   {
   e(toDecrypt[i]);
  }
 std::cout << std::endl;
 }

 int main()
 {
 Cesar c;
 OneTime o("DedeATraversLesBrumes");
 OneTime t("TheCakeIsALie");

 encryptString(c, "Je clair Luc, ne pas ? Ze woudrai un kekos !");
 decryptString(c, "Mi isirb Xhq, ew jvo ? Zf zszjyir fz ytafk !");
 encryptString(c, "KIKOO");
 encryptString(c, "LULZ XD");
 decryptString(c, "Ziqivun ea Ndcsg.Wji !");

 encryptString(t, "Prend garde Lion, ne te trompes pas de voie !");
 encryptString(o, "De la musique et du bruit !");
 encryptString(t, "Kion li faras? Li studas kaj programas!");
 decryptString(t, "Iyipd kijdp Pbvr, xi le bvhttgs tik om ovmg !");
 decryptString(o, "Gi pa dunmhmp wu xg tuylx !");
 decryptString(t, "Dpsp vm xaciw? Pk cxcvad otq rrykzsmla!");

 return 0;
 } 