#include "Pointer.h"


namespace smart{
const std::string
Pointer::type() const{
	return "smart::Pointer";
}

Pointer::operator bool() const{
	if(_pointer) return true;
   	return false;	
}

AClass*
Pointer::operator->() const{
	return _pointer;
}
};
//std::string
//Pointer::name(){
//	return _pointer->name();
//
//}
//};
