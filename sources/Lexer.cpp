#include "Lexer.hpp"
Lexer::Lexer() : input(std::cin){
	
}
Lexer::Lexer(std::istream & input) : input(input){
	
}
Lexer::~Lexer(){}

void Lexer::makeLexems(std::deque<Lexem*> &lexems){
	std::string line;
	std::string parseLine(std::string("(assert|push)[ \f\r\t\v]+([a-z]+[0-9]*)\\((")
				+ INTEGERVALUE + "|" + FRACTIONVALUE + ")\\)");//todo comments and ";;" - exit
	std::smatch tokensInLine;

	for (size_t i = 0; std::getline(input, line).eof() != true; i++) {
		std::cout << i << " line == |" << line << "|" << std::endl;
		if (std::regex_match(line, tokensInLine, std::regex(parseLine.c_str()))) {
			for (size_t i = 1; i < tokensInLine.size(); i++) {
				lexems.push_back(new Lexem(static_cast<eLexemType>(i), tokensInLine[i].str())); //todo [Х] leaks
			}
		}
		//else error
	}
}

// std::string validOp[11] = {"push", "pop", "dump", "assert", "add",
//							"sub", "mull", "div", "mod", "print", "exit"};

// 	std::string validTypes[5] = {"int8", "int16", "int32", "float", "double"};