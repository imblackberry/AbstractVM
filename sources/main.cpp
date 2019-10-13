#include <stdlib.h>
#include "AbstractVM.hpp"
void foo(int ac, char **av){

	AbstractVM vm;
	try {
		if (ac == NO_ARGS)
			vm.run();
		else
		{
			for (int i = 0; i < ac; i++)
				vm.run(av[i]);
		}
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
int main(int ac, char **av){

	foo(ac, av);
	system("leaks avm");
	return 0;
}
