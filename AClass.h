#ifndef _ACLASS_H_
#define _ACLASS_H_
#include <string>
#include <iostream>
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



#endif
