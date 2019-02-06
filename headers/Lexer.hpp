#ifndef LEXER_HPP
#define LEXER_HPP

enum eOperation{
	Pop,
	Dump,
	Assert,
	Add,
	Sub,
	Mul,
	Div,
	Mod,
	Print,
	Exit
};

struct LexemDefinition{
	string INTEGER = "[-]?[0..9]+";
	string FRACTION = "[-]?[0..9]+.[0..9]+";
	string WHITESPACES = " \t\r";
}

class Lexer{
	Lexer();
	Lexer(const Lexer & other);
	Lexer const & operator=(Lexer const & other);
	~Lexer(){}
	LexemDefinition definition;
};

#endif