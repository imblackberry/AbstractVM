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

	Operand<int_fast16_t> *a = new Operand<int_fast16_t>("45");
	Operand<int_fast16_t> *b = new Operand<int_fast16_t>("1");
	IOperand const *c = *a + *b;
	// c = sum<double>(a, b);
	// c = *a + *b;
	std::cout << a->toString() << std::endl; 
	std::cout << b->toString() << std::endl; 
	std::cout << c->toString() << std::endl; 
}
