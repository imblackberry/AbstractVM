#ifndef OPERAND_HPP
#define OPERAND_HPP
#include "IOperand.hpp"
#include <boost/lexical_cast.hpp>
#include <math.h>
template <class T>
class Operand : public IOperand{
	public:
		Operand();
		Operand(std::string str): _strValue(str) {}
		// Operand(const Operand & other);
		Operand const & operator=(Operand const & other){
			if (this != &other){
				_strValue = other._strValue;
			}
			return *this;
		}
		~Operand(){}
		T const 			getValue() const { return static_cast<T>(std::stod(toString())); }
		int					getPrecision(void) const;	// Precision of the type of the instance
		eOperandType		getType(void) const;	// Type of the instance
		IOperand const *	operator+(IOperand const & rhs) const;	// Sum
		IOperand const *	operator-(IOperand const & rhs) const; // Difference
		IOperand const *	operator*(IOperand const & rhs) const; // Product
		IOperand const *	operator/(IOperand const & rhs) const; // Quotient
		IOperand const *	operator%(IOperand const & rhs) const; // Modulo
		std::string const & toString( void ) const { return _strValue; } // String representation of the instance
	private:
		std::string		_strValue;
};
// --------------------------------------------------------------------------//
// 								5 CLASS DECLARATION							 //
// --------------------------------------------------------------------------//
template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<float>;
template class Operand<double>;
#endif