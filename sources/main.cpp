#include <stdlib.h>
#include "AbstractVM.hpp"
#include "Exception.hpp"
void foo(int ac, char **av){

	AbstractVM vm;
	try {
		if (ac == NO_ARGS)
			vm.run();
		else
		{
			for (int i = 1; i < ac; i++)
				vm.run(av[i]);
		}
	} catch (const std::exception &e) {
		std::cout << RED_BOLD << "Error" << END_STYLE << ": " << e.what() << std::endl;
	} 
}
int main(int ac, char **av){

	foo(ac, av);
	system("leaks avm");
	return 0;
}
