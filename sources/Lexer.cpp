#include "Lexer.hpp"
Lexer::Lexer() : _input(std::cin){
	init();
	_isStandardInput = true;
}

Lexer::~Lexer(){}

Lexer::Lexer(std::istream & input) : _input(input){
	init();
	_isStandardInput = false;
}

Lexer::Lexer(const Lexer & other) : _input(other._input){
	*this = other;
}

Lexer const & Lexer::operator=(Lexer const & other) {
	if (this != &other) {
		//_input = std::move(other._input);
		_fullLine = other._fullLine;
		_onlyOpLine = other._onlyOpLine;
		_lexems = other._lexems;
		_isStandardInput = other._isStandardInput;
	}
	return *this;
}

void	Lexer::makeLexems(){
	std::string line;
	std::smatch tokensInLine;

	for (size_t i = 0; std::getline(_input, line).eof() != true; i++) {
		std::cout << i << " line == |" << line << "|" << std::endl;
		if (std::regex_match(line, tokensInLine, std::regex(_fullLine.expression.c_str()))) {
			if (!checkAndAddLexems(tokensInLine, _fullLine.lexemTypes))
				return ;
		}
		else if (std::regex_match(line, tokensInLine, std::regex(_onlyOpLine.expression.c_str()))) {
			if (!checkAndAddLexems(tokensInLine, _onlyOpLine.lexemTypes))
				return ;
		}
		//todo else exception i + 1 line
	}
}

std::vector<Lexem*> & Lexer::getLexems() { return _lexems; }

bool	Lexer::addLexem(eLexemType lexemType, std::string token){
	std::string exitOperaton = ";;";
	// eLexemType lexemType = static_cast<eLexemType>(iType);

	if (lexemType == Comment)
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
	if (isEnd(lexemType, token))
		return false;
	if (lexemType < NN)
		_lexems.push_back(new Lexem(lexemType, token)); //todo [Х] leaks
	return true;
	// std::cout << "[" << i << "]" << tokensInLine[i].str() << std::endl;
}

void Lexer::init() {
	const std::string allLexemTypesParse(std::string("([a-z;;]+)[ \f\r\t\v]+([a-z]+[0-9]*)\\((")
				+ INTEGER_VALUE + "|" + FRACTION_VALUE + ")\\)[ \f\r\t\v]*(.*)");
	std::vector<eLexemType> allLexemTypes = {Operation, eOperandType, Value, NN};
	_fullLine = {allLexemTypesParse, allLexemTypes};
	const std::string onlyOpLexemParse("([a-z;;]+)[ \f\r\t\v]*(.*)");
	std::vector<eLexemType> onlyOpLexemTypes = {Operation, NN};
	_onlyOpLine = {onlyOpLexemParse, onlyOpLexemTypes};
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

bool Lexer::isEnd(eLexemType type, std::string const str) {
	if (type == Operation)
	{
		if (_isStandardInput && str == ";;")
			return true;
		if (str == "exit") // maybe not cause EOF
			return true;
	}
	return false;
}

Lexer::Parse const & Lexer::Parse::operator=(Parse const & other) {
	if (this != &other) {
		expression = other.expression;
		lexemTypes = other.lexemTypes;
	}
	return *this;
}