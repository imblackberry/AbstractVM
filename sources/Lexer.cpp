#include "Lexer.hpp"
Lexer::Lexer() : _input(std::cin){

	// const std::string allLexemTypesParse(std::string("([a-z]+)[ \f\r\t\v]+([a-z]+[0-9]*)\\((")
	// 			+ INTEGER_VALUE + "|" + FRACTION_VALUE + ")\\)[ \f\r\t\v]*(.*)");
	// std::vector<eLexemType> allLexemTypes = {Operation, eOperandType, Value, NN};
	// fullLine = {allLexemTypesParse, allLexemTypes};
	// const std::string onlyOpLexemParse("([a-z]+)[ \f\r\t\v]*(.*)");
	// std::vector<eLexemType> onlyOpLexemTypes = {Operation, NN};
	// onlyOpLine = {onlyOpLexemParse, onlyOpLexemTypes};
	// _isStandardInput = true;
}

Lexer::Lexer(std::istream & input) : _input(input){
	const std::string allLexemTypesParse(std::string("([a-z]+)[ \f\r\t\v]+([a-z]+[0-9]*)\\((")
				+ INTEGER_VALUE + "|" + FRACTION_VALUE + ")\\)[ \f\r\t\v]*(.*)");
	std::vector<eLexemType> allLexemTypes = {Operation, eOperandType, Value, NN};
	fullLine = {allLexemTypesParse, allLexemTypes};
	const std::string onlyOpLexemParse("([a-z]+)[ \f\r\t\v]*(.*)");
	std::vector<eLexemType> onlyOpLexemTypes = {Operation, NN};
	onlyOpLine = {onlyOpLexemParse, onlyOpLexemTypes};
	_isStandardInput = true;
}
Lexer::~Lexer(){}

void	Lexer::makeLexems(){
	std::string line;
	std::smatch tokensInLine;

	for (size_t i = 0; std::getline(_input, line).eof() != true; i++) {
		std::cout << i << " line == |" << line << "|" << std::endl;
		if (std::regex_match(line, tokensInLine, std::regex(fullLine.expression.c_str()))) {
			if (!checkAndAddLexems(tokensInLine, fullLine.lexemTypes))
				return ;
		}
		else if (std::regex_match(line, tokensInLine, std::regex(onlyOpLine.expression.c_str()))) {
			if (!checkAndAddLexems(tokensInLine, onlyOpLine.lexemTypes))
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

bool Lexer::checkAndAddLexems(std::smatch & tokensInLine, std::vector<eLexemType> & lineTokenTypes)
{
	for (size_t i = 1; i < tokensInLine.size(); i++) {
		std::cout << i << "		token == |" << tokensInLine[i].str() << "|" << std::endl;
		if (!addLexem(lineTokenTypes[i - 1], tokensInLine[i].str()))
			return false;
	}
	return true;
}
