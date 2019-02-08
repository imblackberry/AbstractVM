#ifndef LEXER_HPP
#define LEXER_HPP
#include <iostream>
#include <fstream>
#include <list>
#include <regex>
#define NOARGS 1
#define INTEGERVALUE "[-]?[0-9]+"
#define FRACTIONVALUE "[-]?[0-9]+.[0-9]+"
#define COMMENT ";"

enum eLexemType{
	Operation,
	eOperandType,
	Value
};

struct Lexem
{
	Lexem(eLexemType type, std::string const & str) : type(type), capacity(str) {
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
		Lexem * makeOperandType(std::string & str);
		Lexem * makeValue(std::string & str);
		void	checkEndOfStr(std::string & str);
		std::istream & input;
		std::list<Lexem*> lexems;
};

#endif