#include "Lexer.hpp"
Lexer::Lexer() : input(std::cin){
	
}
Lexer::Lexer(std::istream & input) : input(input){
	
}
Lexer::~Lexer(){}

void Lexer::makeLexems(std::deque<Lexem*> &lexems){
	std::string str;
	Lexem *tmp;

	// for (size_t i = 1; std::getline(input, str).eof() != true; i++){
	// 	std::cout << i << " str == " << str << std::endl;
	// 	tmp = makeOperation(str);
	// 	lexems.push_back(tmp);
	// 	if (tmp->capacity == "push" || tmp->capacity == "pop"){
	// 		makeOperandType(str);
	// 		makeValue(str);
	// 	}
	// 	checkEndOfStr(str);
	// }
}

// Lexem * Lexer::makeOperation(std::string & str){
	// std::string validOp[11] = {"push", "pop", "dump", "assert", "add",
	// 							"sub", "mull", "div", "mod", "print", "exit"};
	// size_t OpIndex = 0;
	// std::string regexStr;
	// std::regex operation;
	// for (OpIndex = 0; OpIndex < 11; OpIndex++){
	// 	regexStr = "[ \f\r\t\v]*" + validOp[OpIndex] + ".*";
	// 	operation = regexStr.c_str();
	// 	if (std::regex_match(str, operation) == true){
	// 		str.erase(0, str.find(validOp[OpIndex]) + validOp[OpIndex].size());
	// 		return new Lexem(Operation, validOp[OpIndex]);
	// 	}
	// }
	// return nullptr;
// }

// Lexem * Lexer::makeOperandType(std::string & str){
// 	std::string validType[5] = {"int8", "int16", "int32", "float", "double"};
// 	size_t OpIndex = 0;
// 	std::string regexStr;
// 	std::regex operation;
// 	for (OpIndex = 0; OpIndex < 5; OpIndex++){
// 		regexStr = "[ \f\r\t\v]*" + validType[OpIndex] + "(.*)[ \f\r\t\v;].*";
// 		operation = regexStr.c_str();
// 		if (std::regex_match(str, operation) == true){
// 			str.erase(0, str.find(validType[OpIndex]) + validType[OpIndex].size());
// 			return new Lexem(eOperandType, validType[OpIndex]);
// 		}
// 	}
// 	return nullptr;
// }

// Lexem * Lexer::makeValue(std::string & str){
// 	std::string capacity = "";
// 	return new Lexem(Value, capacity);

// }

// void Lexer::checkEndOfStr(std::string & str){
// 	std::string ws = " \f\r\t\v";
// 	size_t pos = str.find_first_not_of(ws);

// 	if (str[pos] == str.back() || str[pos] == ';' || pos == std::string::npos)
// 		std::cout << "norm" << std::endl;
// 	else
// 		std::cout << "fuck" << std::endl;
// }