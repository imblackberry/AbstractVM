#include "Lexer.hpp"
Lexer::Lexer() : _input(std::cin), _isStandardInput(true) {}

Lexer::Lexer(std::istream & input) : _input(input){}
Lexer::~Lexer(){}

void	Lexer::makeLexems(){ // vars to class, all + only?
	std::string line;
	std::string allLexemTypesParse(std::string("([a-z]+)[ \f\r\t\v]+([a-z]+[0-9]*)\\((")
				+ INTEGER_VALUE + "|" + FRACTION_VALUE + ")\\)[ \f\r\t\v]*(.*)");
	std::string onlyOpLexemParse("([a-z]+)[ \f\r\t\v]*(.*)");
	eLexemType allLexemTypes[4] = {Operation, eOperandType, Value, NN};
	eLexemType onlyOpLexemTypes[2] = {Operation, NN};
	std::smatch tokensInLine;

	for (size_t i = 0; std::getline(_input, line).eof() != true; i++) {
		std::cout << i << " line == |" << line << "|" << std::endl;
		if (std::regex_match(line, tokensInLine, std::regex(allLexemTypesParse.c_str()))) {
			if (!checkAndAddLexems(tokensInLine, allLexemTypes))
				return ;
		}
		else if (std::regex_match(line, tokensInLine, std::regex(onlyOpLexemParse.c_str()))) {
			if (!checkAndAddLexems(tokensInLine, onlyOpLexemTypes))
				return ;
		}
		//todo else exception i + 1 line
	}
}


bool	Lexer::addLexem(eLexemType lexemType, std::string token){
	std::string exitOperaton = ";;";
	// eLexemType lexemType = static_cast<eLexemType>(iType);

	if (lexemType == NN)
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

bool Lexer::checkAndAddLexems(std::smatch & tokensInLine, eLexemType * lineTokenTypes)
{
	for (size_t i = 1; i < tokensInLine.size(); i++) {
		std::cout << i << "		token == |" << tokensInLine[i].str() << "|" << std::endl;
		if (!addLexem(lineTokenTypes[i - 1], tokensInLine[i].str()))
			return false;
	}
	return true;
}
// std::string validOp[11] = {"push", "pop", "dump", "assert", "add",
//							"sub", "mull", "div", "mod", "print", "exit"};

// 	std::string validTypes[5] = {"int8", "int16", "int32", "float", "double"};
