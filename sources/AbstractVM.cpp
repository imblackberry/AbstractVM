#include "AbstractVM.hpp"

void AbstractVM::launch(std::string fileName)
{
    lexer.makeLexems();
	(void)fileName;
}