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
		Lexer(std::istream & input = std::cin);
		Lexer(const Lexer & other);
		Lexer const & operator=(Lexer const & other);
		~Lexer();
		void	makeLexems();

	private:
		struct Parse{
			std::string expression;
			std::vector<eLexemType> lexemTypes;//vector?
		};
		Lexem * makeOperation(std::string & str);
		bool addLexem(eLexemType lexemType, std::string token);
		bool checkAndAddLexems(std::smatch & tokensInLine, std::vector<eLexemType> & lineTokenTypes);
		std::istream & _input;
		Parse fullLine;
		Parse onlyOpLine;
		std::list<Lexem*> _lexems;
		bool _isStandardInput = false;
};

#endif