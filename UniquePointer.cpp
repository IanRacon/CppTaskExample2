#include "UniquePointer.h"
namespace smart{

const std::string
UniquePointer::type() const{
	return "smart::UniquePointer";
}

UniquePointer::UniquePointer(UniquePointer& that) : Pointer(that){
	that._pointer = NULL;
}
UniquePointer::UniquePointer(int that) : Pointer(that){
}

UniquePointer&
UniquePointer::operator=(UniquePointer& other){
	_pointer = other._pointer;
	other._pointer = NULL;
	return *this;
}
};

