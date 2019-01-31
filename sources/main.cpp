#include "Operand.hpp"
template< class T>
Operand<T> * sum(Operand<T> * a, Operand<T> *b){
	Operand<T> * c = new Operand<T>("7");
	a + b;
	(void)a;
	(void)b;

	return c;
}
int main(){

	Operand<double> *a = new Operand<double>("45.65600001");
	Operand<double> *b = new Operand<double>("1");
	IOperand const *c = *a + *b;

	// c = sum<double>(a, b);
	// c = *a + *b;
	std::cout << a->toString() << std::endl; 
	std::cout << b->toString() << std::endl; 
	std::cout << c->toString() << std::endl; 
}