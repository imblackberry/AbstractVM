#ifndef LEXER_HPP
#define LEXER_HPP
#include <iostream>
#include <fstream>
#include <list>
#include <regex>
#define NOARGS 1
#define INTEGER_VALUE "[-]?[0-9]+"
#define FRACTION_VALUE "[-]?[0-9]+.[0-9]+"
#define COMMENT ";"

enum eLexemType{
	Operation, //0
	eOperandType, //1
	Value, //2
	NN //3
};

struct Lexem
{
	Lexem(eLexemType type, std::string const str) : type(type), capacity(str) {
		std::cout << "type = " << type << " capacity = " << capacity << std::endl;
	}
	eLexemType		type;
	std::string		capacity;
};

class Lexer{
	public:
		Lexer();
		Lexer(std::istream & input);
		Lexer(const Lexer & other);
		Lexer const & operator=(Lexer const & other);
		~Lexer();
		void	makeLexems();

	private:
		Lexem * makeOperation(std::string & str);
		bool addLexem(eLexemType lexemType, std::string token);
		bool checkAndAddLexems(std::smatch & tokensInLine, eLexemType * lineTokenTypes);
		std::istream & _input;
		std::list<Lexem*> _lexems;
		bool _isStandardInput = false;
};

#endif