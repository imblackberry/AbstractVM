#ifndef OPERAND_HPP
#define OPERAND_HPP
#include "IOperand.hpp"
#include <boost/lexical_cast.hpp>
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
		T const 			getValue() const {
			return static_cast<T>(std::stod(toString()));
			}
		int					getPrecision(void) const;	// Precision of the type of the instance
		eOperandType		getType(void) const;	// Type of the instance
		IOperand const *	operator+(IOperand const & rhs) const;
		// 	IOperand const *result;
	
		// 	if (this->getType() < rhs.getType())
		// 		result = rhs + *this;
		// 	return new Operand<T>(boost::lexical_cast<std::string>(getValue() + static_cast<T>(std::stod(rhs.toString()))));
		// 	// }else
		// 		// result = new Operand<T>(boost::lexical_cast<std::string>(getValue() + static_cast<T>(std::stod(rhs.toString()))));
		// 	// return result;
		// } // Sum
		// virtual IOperand const *	operator-(IOperand const & rhs) const; // Difference
		// virtual IOperand const *	operator*(IOperand const & rhs) const; // Product
		// virtual IOperand const *	operator/(IOperand const & rhs) const; // Quotient
		// virtual IOperand const *	operator%(IOperand const & rhs) const; // Modulo
		std::string const & toString( void ) const {
			return _strValue;
		} // String representation of the instance
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