#include "Operand.hpp"
int main(){
	
	Operand<double> a("45.65600001");
	// Operand<int32_t> b(8);
	// Operand<int32_t> c;

	// c = a + b;
	std::cout << a.getValue() << std::endl; 
	// std::cout << b.toString() << std::endl; 
	// std::cout << c.toString() << std::endl; 
}