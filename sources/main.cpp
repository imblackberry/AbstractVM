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

	Operand<int8_t> *a = new Operand<int8_t>("8");
	IOperand *b = new Operand<int16_t>("25");
	IOperand const *c = *a - *b; //= -92,7
	// 100,8 - 8 = 92,7
	// c = sum<double>(a, b);
	// c = *a + *b;

	std::cout << a->toString() << std::endl; 
	std::cout << b->toString() << std::endl; 
	std::cout << c->toString() << std::endl;
	std::cout << a->getPrecision() << std::endl; 
	std::cout << b->getPrecision() << std::endl; 
	std::cout << c->getPrecision() << std::endl;

}
