#include "Operand.hpp"
int main(){
	IOperand *p = new Operand<int>(45);
	std::cout << p->toString() << std::endl; 
	delete p;
}