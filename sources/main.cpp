#include <stdlib.h>
#include "AbstractVM.hpp"
void foo(){

	// OperandFactory factory;
	// IOperand const *a = factory.createOperand(Int8, "35");
	// IOperand const *b = factory.createOperand(Double, "100.5");
	// IOperand const *c = *a + *b;
	// std::cout << "toString() = " << a->toString() << std::endl;
	// std::cout << "toString() = " << b->toString() << std::endl;
	// std::cout << "toString() = " << c->toString() << std::endl;

	// std::cout << "getType() = " << a->getType() << std::endl;
	// std::cout << "getType() = " << b->getType() << std::endl;
	// std::cout << "getType() = " << c->getType() << std::endl;
}
int main(int ac, char **av){
	AbstractVM vm;

	if (ac == NO_ARGS)
		vm.run();
	else
	{
		for (int i = 0; i < ac; i++)
			vm.run(av[i]);
	}
	system("leaks avm");
	return 0;
}
