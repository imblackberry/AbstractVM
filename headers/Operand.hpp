#ifndef OPERAND_HPP
#define OPERAND_HPP
#include "IOperand.hpp"
#define BITS_IN_BYTE 8
template <class T>
class Operand : public IOperand{
	public:
		Operand();
		Operand(T  value): _value(value){_strValue = std::to_string(value);}
		// Operand(const Operand & other);
		Operand const & operator=(Operand const & other){
			if (this != &other){
				_value = other._value;
				_precision = other._precision;
				_type = other._type;
				_strValue = other._strValue;
			}
			return *this;
		}
		~Operand(){}
		T const & getValue() const {return _value;}
		// virtual int					getPrecision(void) const;	// Precision of the type of the instance
		// virtual	eOperandType		getType(void) const;	// Type of the instance
		// virtual Operand const *	operator+(IOperand const & rhs) const; // Sum
		// virtual IOperand const *	operator-(IOperand const & rhs) const; // Difference
		// virtual IOperand const *	operator*(IOperand const & rhs) const; // Product
		// virtual IOperand const *	operator/(IOperand const & rhs) const; // Quotient
		// virtual IOperand const *	operator%(IOperand const & rhs) const; // Modulo
		virtual std::string const & toString( void ) const{return _strValue;} // String representation of the instance
	private:
		T				_value;
		int				_precision;
		eOperandType	_type;
		std::string		_strValue;
};
// ------------------------------
// 			DECLARATION
// ------------------------------
template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<float>;
template class Operand<double>;
#endif