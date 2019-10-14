#ifndef LEXER_HPP
#define LEXER_HPP
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include "Exception.hpp"
#define NOARGS 1
#define INTEGER_VALUE "[-]?[0-9]+"
#define FRACTION_VALUE "[-]?[0-9]+.[0-9]+"

enum eLexemType{
	Operation, //0
	eOperandType, //1
	Value, //2
	NN, //3
	Comment = NN
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
		~Lexer();
		Lexer(std::istream & input);// ?
		Lexer(const Lexer & other);
		Lexer const & operator=(Lexer const & other);
		void	makeLexems();
		std::vector<Lexem*> & getLexems();

	private:
		struct Parse{
			std::string expression;
			std::vector<eLexemType> lexemTypes;//vector?
			Parse const & operator=(Parse const & other);
		};
		void init();
		Lexem * makeOperation(std::string & str);
		bool addLexem(eLexemType lexemType, std::string token);
		bool checkAndAddLexems(std::smatch & tokensInLine, std::vector<eLexemType> & lineTokenTypes);
		bool isEnd(const std::string token);
		bool isCommentOrEmty(const std::string token);

		std::istream & _input;
		Parse _fullLine;
		Parse _onlyOpLine;
		std::vector<Lexem*> _lexems;
		bool _isStandardInput;
};

#endif