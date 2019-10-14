#ifndef OPERAND_HPP
#define OPERAND_HPP
#include "IOperand.hpp"
#include <iostream>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <OperandFactory.hpp>
template <class T>
class Operand : public IOperand{
	public:
		Operand();
		~Operand();
		Operand(std::string str);
		Operand(const Operand & other);
		Operand const & operator=(Operand const & other);
		T const 			getValue() const;
		int					getPrecision(void) const;	// Precision of the type of the instance
		enum eOperandType   getType(void) const;	// Type of the instance
		IOperand const *	operator+(IOperand const & rhs) const; // Sum
		IOperand const *	operator-(IOperand const & rhs) const; // Difference
		IOperand const *	operator*(IOperand const & rhs) const; // Product
		IOperand const *	operator/(IOperand const & rhs) const; // Quotient
		IOperand const *	operator%(IOperand const & rhs) const; // Modulo
		std::string const & toString( void ) const; // String representation of the instance
		std::string			DoubleToString(double const & value) const{
			std::ostringstream sstr;
			sstr << value;
			return sstr.str();
		}
	private:
		std::string		_strValue;

};

#endif