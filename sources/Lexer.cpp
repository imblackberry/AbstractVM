#include "Lexer.hpp"
Lexer::Lexer() : _input(std::cin), _isStandardInput(true) {}

Lexer::Lexer(std::istream & input) : _input(input){}
Lexer::~Lexer(){}

void	Lexer::makeLexems(){
	std::string line;
	std::string allLexemTypesParse(std::string("([a-z]+)[ \f\r\t\v]+([a-z]+[0-9]*)\\((")
				+ INTEGER_VALUE + "|" + FRACTION_VALUE + ")\\)[ \f\r\t\v]*(.*)");
	std::string OnlyOpLexemParse("([a-z]+)[ \f\r\t\v]*(.*)");
	eLexemType allLexemTypes[4] = {Operation, eOperandType, Value, NN};
	eLexemType OnlyOpLexemTypes[2] = {Operation, NN};

	for (size_t i = 0; std::getline(_input, line).eof() != true; i++) {
		std::cout << i << " line == |" << line << "|" << std::endl;
		if (std::regex_match(line, tokensInLine, std::regex(parseLine.c_str()))) {
			checkAndAddLexems(tokensInLine, allLexemTypes);
		}
		else if (std::match(line, tokensInLine, std::regex(parseLineOnlyOp.c_str()))) {
			checkAndAddLexems(tokensInLine, OnlyOpLexemTypes);
		}
		//todo else exception
	}
}

bool checkAndAddLexems(std::smatch & tokensInLine, eLexemType * lineTokenTypes)
{
	for (size_t i = 1; i < tokensInLine.size(); i++) {
		std::cout << i << "		token == |" << tokensInLine[i].str() << "|" << std::endl;
		if (!addLexem(lineTokenTypes[i - 1], tokensInLine[i].str()))
			return ;
	}
}

bool	Lexer::addLexem(size_t iType, std::string token){
	std::string exitOperaton = ";;";
	eLexemType lexemType = static_cast<eLexemType>(iType);

	if (iType == NN)
	{ //todo NORM FUNCTION
		if (token.empty()) //no comment
			return true;
		else if (_isStandardInput && token == exitOperaton) //end reading from standard input //todo: maybe add exit lexem
			return false;
		else if (token[0] == ';') // is comment
			return true;
		else
			return false; //todo exception
	}
	if (lexemType < NN)
		_lexems.push_back(new Lexem(lexemType, token)); //todo [Х] leaks
	return true;
	// std::cout << "[" << i << "]" << tokensInLine[i].str() << std::endl;
}

// std::string validOp[11] = {"push", "pop", "dump", "assert", "add",
//							"sub", "mull", "div", "mod", "print", "exit"};

// 	std::string validTypes[5] = {"int8", "int16", "int32", "float", "double"};
