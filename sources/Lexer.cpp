#include "Lexer.hpp"
Lexer::Lexer() : _input(std::cin){

}
Lexer::Lexer(std::istream & input) : _input(input){

}
Lexer::~Lexer(){}

void	Lexer::makeLexems(){
	std::string line;
	std::string parseLine(std::string("([a-z]+)[ \f\r\t\v]+([a-z]+[0-9]*)\\((")
				+ INTEGER_VALUE + "|" + FRACTION_VALUE + ")\\)[ \f\r\t\v]*(.*)");
	std::smatch tokensInLine;

	for (size_t i = 0; std::getline(_input, line).eof() != true; i++) {
		std::cout << i << " line == |" << line << "|" << std::endl;
		if (std::regex_match(line, tokensInLine, std::regex(parseLine.c_str()))) {
			for (size_t i = 1; i < tokensInLine.size(); i++) {
				if (!addLexem(i - 1, tokensInLine[i].str()))
					return ;
			}
		}
		//todo else exception
	}
}

bool	Lexer::addLexem(size_t iType, std::string token){
	std::string exitOperaton = ";;";
	eLexemType lexemType = static_cast<eLexemType>(iType);

	if (iType == NN)
	{ //todo NORM FUNCTION
		if (token.empty())
			return true;
		else if (token[0] == ';')
		{
			if (token[1] && token[1] == ';')
				return false; //end ;;
			else
				return true;
		}
		else
			return false;
	}
	if (lexemType < NN) //todo exception
		_lexems.push_back(new Lexem(lexemType, token)); //todo [Х] leaks
	return true;
	// std::cout << "[" << i << "]" << tokensInLine[i].str() << std::endl;
}

// std::string validOp[11] = {"push", "pop", "dump", "assert", "add",
//							"sub", "mull", "div", "mod", "print", "exit"};

// 	std::string validTypes[5] = {"int8", "int16", "int32", "float", "double"};
