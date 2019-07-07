#include "AbstractVM.hpp"

void AbstractVM::launch(std::string fileName)
{
    lexer.makeLexems(lexems);
	(void)fileName;
}