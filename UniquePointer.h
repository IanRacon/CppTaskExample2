#ifndef _UNIQ_PTR_H
#define _UNIQ_PTR_H
#include "Pointer.h"
namespace smart{
class UniquePointer : public Pointer{
	private:
	public:
		UniquePointer(AClass *pointer) : Pointer(pointer) {}
		UniquePointer(UniquePointer& that);
		UniquePointer(int that);
		virtual const std::string type() const;
		UniquePointer& operator=(UniquePointer& other);
		~UniquePointer() { delete _pointer;}
};
};


#endif
