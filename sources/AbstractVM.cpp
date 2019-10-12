#include "AbstractVM.hpp"
AbstractVM::AbstractVM() {};
AbstractVM::~AbstractVM() {};

AbstractVM::AbstractVM(const AbstractVM & other){ *this = other; };

AbstractVM const & AbstractVM::operator=(AbstractVM const & other) {
	if (this != &other) {
        //_lexer = std::move(other._lexer);//should nullptr???
        //_parser = std::move(other._parser);//should nullptr???
        _operands = other._operands;
	}
	return *this;
}
void AbstractVM::run(std::string fileName)
{
    if (fileName != "")
    {
        std::ifstream file(fileName);
        _lexer = std::make_unique<Lexer>(file);
    }
    else
        _lexer = std::make_unique<Lexer>(std::cin);
    _lexer->makeLexems();
    _parser = std::make_unique<Parser>(_lexer->getLexems());
    _parser->run();
}