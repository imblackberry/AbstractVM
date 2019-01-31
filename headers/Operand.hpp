#ifndef OPERAND_HPP
#define OPERAND_HPP
#include "IOperand.hpp"
#include <boost/lexical_cast.hpp>
#define BITS_IN_BYTE 8
template <class T>
class Operand : public IOperand{
	public:
		Operand();
		Operand(std::string str): _strValue(str) {
			_value = static_cast <T> (std::stod(str));
			}
		// Operand(const Operand & other);
		Operand const & operator=(Operand const & other){
			if (this != &other){
				_strValue = other._strValue;
				_value = other._value;
			}
			return *this;
		}
		~Operand(){}
		T const & getValue() const {return _value;}
		// virtual int					getPrecision(void) const;	// Precision of the type of the instance
		// virtual	eOperandType		getType(void) const;	// Type of the instance
		IOperand const *	operator+(IOperand const & rhs) const {
			IOperand const *tmp = new Operand (boost::lexical_cast<std::string>(_value + static_cast<T>(std::stod(rhs.toString()))));
			return tmp;
		} // Sum
		// virtual IOperand const *	operator-(IOperand const & rhs) const; // Difference
		// virtual IOperand const *	operator*(IOperand const & rhs) const; // Product
		// virtual IOperand const *	operator/(IOperand const & rhs) const; // Quotient
		// virtual IOperand const *	operator%(IOperand const & rhs) const; // Modulo
		virtual std::string const & toString( void ) const {
			return _strValue;
		} // String representation of the instance
	private:
		T				_value;
		std::string		_strValue;
};
// ------------------------------
// 			5 CLASS DECLARATION
// ------------------------------
template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<float>;
template class Operand<double>;
#endif