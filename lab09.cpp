/*
 * Prosze napisac klasy wskaznikow (Pointer i UniquePointer). 
 * Prosze zauwazyc ze klasa Pointer nie jest czysto wirtualna.
 *
 * Kompilowac z opcjami -Wall -g -pedantic
 *
 * Klasa AClass jest trywialnie prosta i jest pokazana ponizej.
 * 
 *
class AClass {
public:
  AClass(const std::string& name) : m_name(name) {}
  ~AClass() { 
    std::cout << ".. uswam " << name() << std::endl;
  }
  const std::string& name() const { return m_name; }
private:
  std::string m_name;
};

 */

#include <iostream>

#include "AClass.h"

#include "Pointer.h"
#include "UniquePointer.h"
//#include "RefCountingPointer.h"



using namespace std;
void dumpb(const smart::Pointer sptr ) {
  cout << sptr.type() << endl;
  cout << "czy wskaznik wazny " << bool(sptr) << endl;
  if ( sptr ) {
    cout << sptr->name() << endl;
    cout << typeid(smart::Pointer::value_type).name() << endl;
  }  
}


void dump(const smart::Pointer& sptr) {
  cout << sptr.type() << endl;
  dumpb(sptr);
}


int main() {

  smart::UniquePointer uptr1( new AClass("A1") );
  dump(uptr1);

  std::cout << "-----------------------------" << std::endl;
  smart::UniquePointer uptr2 (uptr1);
  dump(uptr1);
  dump(uptr2);

  std::cout << "-----------------------------" << std::endl;
  smart::UniquePointer uptr3 (0);
  uptr3 = uptr1 = uptr2;
  dump(uptr1);
  dump(uptr2);
  dump(uptr3);
  
  smart::Pointer normalptr( new AClass("A2") );
  delete (normalptr.operator->());


}
/* wynik
smart::UniquePointer
smart::Pointer
czy wskaznik wazny 1
A1
6AClass
-----------------------------
smart::UniquePointer
smart::Pointer
czy wskaznik wazny 0
smart::UniquePointer
smart::Pointer
czy wskaznik wazny 1
A1
6AClass
-----------------------------
smart::UniquePointer
smart::Pointer
czy wskaznik wazny 0
smart::UniquePointer
smart::Pointer
czy wskaznik wazny 0
smart::UniquePointer
smart::Pointer
czy wskaznik wazny 1
A1
6AClass
.. uswam A2
.. uswam A1

 */
