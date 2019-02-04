#ifndef OPERAND_HPP
#define OPERAND_HPP
#include "IOperand.hpp"
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <math.h>
#include <algorithm>
#include <OperandFactory.hpp>
template <class T>
class Operand : public IOperand{
	public:
		Operand();
		Operand(std::string str) {
			T n = static_cast<T>(std::stod(str));
			_strValue = DoubleToString(n);
		}
		Operand(const Operand & other){
			*this = other;
		}
		Operand const & operator=(Operand const & other){
			if (this != &other){
				_strValue = other._strValue;
			}
			return *this;
		}
		~Operand(){}
		T const 			getValue() const;
		int					getPrecision(void) const;	// Precision of the type of the instance
		eOperandType		getType(void) const;	// Type of the instance
		IOperand const *	operator+(IOperand const & rhs) const;	// Sum
		IOperand const *	operator-(IOperand const & rhs) const; // Difference
		IOperand const *	operator*(IOperand const & rhs) const; // Product
		IOperand const *	operator/(IOperand const & rhs) const; // Quotient
		IOperand const *	operator%(IOperand const & rhs) const; // Modulo
		std::string const & toString( void ) const; // String representation of the instance
		std::string			DoubleToString(double const & value) const{
			std::stringstream sstr;
			sstr << value;
			return sstr.str();
		}
	private:
		std::string		_strValue;

};

#endif