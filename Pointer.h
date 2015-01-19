#ifndef _POINTER_H_
#define _POINTER_H_
#include "AClass.h"
#include <typeinfo>
#include <string>
namespace smart{
class Pointer{
	protected:
		AClass *_pointer;
	public:
		typedef AClass value_type;
		Pointer(AClass *pointer) : _pointer(pointer) {}
		Pointer(const Pointer& other) : _pointer(other._pointer) {}
		Pointer(int that) { 
			if(!that) _pointer = NULL;
		}
		virtual const std::string type() const;
		operator bool() const;	
		Pointer& operator=(Pointer& other);
		AClass* operator->() const;
		AClass* getPointer() const { return _pointer; }
		//std::string name() const;

};
};





#endif
