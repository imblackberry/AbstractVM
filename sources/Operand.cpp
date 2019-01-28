#include "Operand.cpp"
Operand::Operand(){

}
Operand::Operand(const Operand & other){

}
const Operand& Operand::operator=(const Operand & other){

}
Operand::~Operand(){
	
}
int					getPrecision(void) const{
	return _precision;
}	// Precision of the type of the instance
eOperandType		getType(void){
	return _type;
}	// Type of the instance
IOperand const *	operator+(IOperand const & rhs) const = 0; // Sum
IOperand const *	operator-(IOperand const & rhs) const = 0; // Difference
IOperand const *	operator*(IOperand const & rhs) const = 0; // Product
IOperand const *	operator/(IOperand const & rhs) const = 0; // Quotient
IOperand const *	operator%(IOperand const & rhs) const = 0; // Modulo
std::string const & toString( void ) const{
	return itoa(value);
} // String representation of the instance
	