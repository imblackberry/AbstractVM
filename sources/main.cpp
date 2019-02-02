// #include "Operand.hpp"
#include "OperandFactory.hpp"

int main(){

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
 
//  Operand<double> const *d = new Operand<double>("4");
//  double n = 4.0;
// 	std::cout << "typeToString() = " << d->DoubleToString(n) << std::endl;

}
