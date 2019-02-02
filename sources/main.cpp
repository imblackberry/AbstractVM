// #include "Operand.hpp"
#include "OperandFactory.hpp"

int main(){

	// Operand<int8_t> *a = new Operand<int8_t>("8");
	// IOperand *b = new Operand<int16_t>("25");
	// IOperand const *c = *a - *b; //= -92,7


	OperandFactory factory;
	IOperand const *a = factory.createOperand(Int8, "35");
	IOperand const *b = factory.createOperand(Double, "100.5");
	IOperand const *c = *a % *b;
	std::cout << "toString() = " << a->toString() << std::endl; 
	std::cout << "toString() = " << b->toString() << std::endl; 
	std::cout << "toString() = " << c->toString() << std::endl;
	std::cout << "getType() = " << a->getType() << std::endl; 
	std::cout << "getType() = " << b->getType() << std::endl; 
	std::cout << "getType() = " << c->getType() << std::endl;

}
