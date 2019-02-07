#include "Lexer.hpp"
Lexer::Lexer() : input(std::cin){
	
}
Lexer::Lexer(std::istream & input) : input(input){
	// if (ac == NOARGS)
	// 	_fd = 0;
	// else{
	// 	for (int i = FIRSTARG; i < ac; i++)

	// }
	// if (ac == NOARGS)
		// input(std::cin);
		//  : file_input;
}
Lexer::~Lexer(){}
void Lexer::makeLexems(){
	std::string line;

	for (size_t i = 1; std::getline(input, line).eof() != true; i++){
		std::cout << i << " line == " << line << std::endl;
		makeOperation(line);
	}
}

Lexem * Lexer::makeOperation(std::string & str){
	std::string validOp[11] = {"push", "pop", "dump", "assert", "add",
								"sub", "mull", "div", "mod", "print", "exit"};
	std::string capacity = "";
	size_t OpIndex = 0;
	std::string regexStr;
	std::regex operation;
	for (OpIndex = 0; OpIndex < 11; OpIndex++){
		regexStr = ("(" + std::string(WHITESPACES) + ")" + validOp[OpIndex] + "(*)");
		operation = regexStr.c_str();
		if (std::regex_match(str, operation) == true){
			std::cout << "true" << std::endl;
			capacity = validOp[OpIndex];
		}
		else
			std::cout << "false" << std::endl;
	}
	return new Lexem(Operation, capacity);
}

Lexem * Lexer::makeOperandType(std::string & str){
	std::string validType[5] = {"int8", "int16", "int32", "float", "double"};
	std::string capacity = "";
	return new Lexem(Operation, capacity);
}

Lexem * Lexer::makeValue(std::string & str){
	std::string capacity = "";
	return new Lexem(Operation, capacity);

}