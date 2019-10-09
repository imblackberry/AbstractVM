#include "AbstractVM.hpp"

void AbstractVM::run(std::string fileName)
{
    lexer.makeLexems();
	(void)fileName;
}