#include "Parser.hpp"

Parser::Parser(std::list<Lexem*> & lexems):
		_lexems(std::move(lexems))
{
	// actions[Push] = Parser::push;
	// actions[Pop] = Parser::pop;
	// actions[Dump] = Parser::dump;
	// actions[Assert] = Parser::assert;
	// actions[Add] = Parser::add;
	// actions[Sub] = Parser::sub;
	// actions[Mul] = Parser::mul;
	// actions[Div] = Parser::div;
	// actions[Mod] = Parser::mod;
	// actions[Print] = Parser::print;
	// actions[Exit] = Parser::exit;
}