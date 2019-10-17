#include <stdlib.h>
#include "AbstractVM.hpp"
#include "Exception.hpp"

int main(int ac, char **av) {
{
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
	//system("leaks avm");
	return 0;
}
