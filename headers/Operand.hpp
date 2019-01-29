#ifndef OPERAND_HPP
#define OPERAND_HPP
#include "IOperand.hpp"
#define BITS_IN_BYTE 8
template <class T>
class Operand : public IOperand{
	public:
		Operand();
		Operand(T  value): _value(value){
			_strValue = std::to_string(value);
		}
		// Operand(const Operand & other);
		// const Operand& operator=(const Operand & other);
		~Operand(){}
		T & getValue() const{
			return _value;
		}
		// virtual int					getPrecision(void) const;	// Precision of the type of the instance
		// virtual	eOperandType		getType(void) const;	// Type of the instance
		// virtual IOperand const *	operator+(IOperand const & rhs) const; // Sum
		// virtual IOperand const *	operator-(IOperand const & rhs) const; // Difference
		// virtual IOperand const *	operator*(IOperand const & rhs) const; // Product
		// virtual IOperand const *	operator/(IOperand const & rhs) const; // Quotient
		// virtual IOperand const *	operator%(IOperand const & rhs) const; // Modulo
		virtual std::string const & toString( void ) const{
			return _strValue;
		} // String representation of the instance
	private:
		T _value;
		std::string _strValue;
};

#endif