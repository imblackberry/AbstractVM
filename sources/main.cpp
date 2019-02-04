#include "OperandFactory.hpp"
#include <stdlib.h>
void foo(){

	OperandFactory factory;
	IOperand const *a = factory.createOperand(Int8, "35");
	IOperand const *b = factory.createOperand(Double, "100.5");
	IOperand const *c = *a + *b;
	std::cout << "toString() = " << a->toString() << std::endl; 
	std::cout << "toString() = " << b->toString() << std::endl; 
	std::cout << "toString() = " << c->toString() << std::endl;

	std::cout << "getType() = " << a->getType() << std::endl; 
	std::cout << "getType() = " << b->getType() << std::endl; 
	std::cout << "getType() = " << c->getType() << std::endl;
}
int main(){


	foo();
}
