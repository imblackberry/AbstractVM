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

void Lexer::init() {
	const std::string allLexemTypesParse(std::string("([a-z]+)[ \f\r\t\v]+([a-z]+[0-9]*)\\((")
				+ INTEGER_VALUE + "|" + FRACTION_VALUE + ")\\)[ \f\r\t\v]*(.*)");
	std::vector<eLexemType> allLexemTypes = {Operation, OperandType, Value, Comment};
	_fullLine = {allLexemTypesParse, allLexemTypes};
	const std::string onlyOpLexemParse("([a-z]+)[ \f\r\t\v]*(.*)");
	std::vector<eLexemType> onlyOpLexemTypes = {Operation, Comment};
	_onlyOpLine = {onlyOpLexemParse, onlyOpLexemTypes};
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

	bool endFile;
	do {
		endFile = std::getline(_input, line).eof();
		int i = 0;//del
		std::cout << i++ << " line == |" << line << "|" << std::endl;//del
		if (std::regex_match(line, tokensInLine, std::regex(_fullLine.expression.c_str()))) {
			if (!checkAndAddLexems(tokensInLine, _fullLine.lexemTypes))
				return ;
		}
		else if (std::regex_match(line, tokensInLine, std::regex(_onlyOpLine.expression.c_str()))) {
			if (!checkAndAddLexems(tokensInLine, _onlyOpLine.lexemTypes))
				return ;
		}
		else if (!isCommentOrEmty(line))
			throw Exception("lexical");
	} while (!endFile && !isEnd(line));
}

std::vector<Lexem> & Lexer::getLexems() { return _lexems; }

bool	Lexer::addLexem(eLexemType lexemType, std::string token){
	if (lexemType == Comment)
	{
		if (isCommentOrEmty(token))
			return true;
		else
			throw Exception("lexical");
	}
	if (lexemType < NN)
		_lexems.push_back({lexemType, token});
	return true;
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

bool Lexer::isEnd(const std::string token) {
	if (_isStandardInput && token == ";;")
		return true;
	return false;
}

bool Lexer::isCommentOrEmty(const std::string token) {
	if (token.empty() || token[0] == ';')
		return true;
	return false;
}

Lexer::Parse const & Lexer::Parse::operator=(Parse const & other) {
	if (this != &other) {
		expression = other.expression;
		lexemTypes = other.lexemTypes;
	}
	return *this;
}