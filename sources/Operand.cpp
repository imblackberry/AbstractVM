#include "Operand.hpp"
// --------------------------------------------------------------------------//
// 						5 CLASS METHOD SPECIALIZATION						 //
// --------------------------------------------------------------------------//


template<>
eOperandType		Operand<int8_t>::getType(void) const{ return Int8; }
template<>
int					Operand<int8_t>::getPrecision(void) const{ return Int8; }

template<>
eOperandType		Operand<int16_t>::getType(void) const{ return Int16; }
template<>
int					Operand<int16_t>::getPrecision(void) const{ return Int16; }

template<>
eOperandType		Operand<int32_t>::getType(void) const{ return Int32; }
template<>
int					Operand<int32_t>::getPrecision(void) const{ return Int32; }

template<>
eOperandType		Operand<float>::getType(void) const{ return Float; }
template<>
int					Operand<float>::getPrecision(void) const{ return Float; }

template<>
eOperandType		Operand<double>::getType(void) const{ return Double; }
template<>
int					Operand<double>::getPrecision(void) const{ return Double; }

template <class T>
IOperand const *	Operand<T>::operator+(IOperand const & rhs) const {
	if (this->getPrecision() < rhs.getPrecision())
		return rhs + *this;
	return new Operand<T>(boost::lexical_cast<std::string>(getValue() + static_cast<T>(std::stod(rhs.toString()))));
}

template <class T>
IOperand const *	Operand<T>::operator*(IOperand const & rhs) const{
	if (this->getPrecision() < rhs.getPrecision())
		return rhs * *this;
	return new Operand<T>(boost::lexical_cast<std::string>(getValue() * static_cast<T>(std::stod(rhs.toString()))));
}

template <class T>
IOperand const * Operand<T>::operator-(IOperand const & rhs) const{
	if (this->getPrecision() < rhs.getPrecision())
		return rhs - *this;
	return new Operand<T>(boost::lexical_cast<std::string>(getValue() - static_cast<T>(std::stod(rhs.toString()))));

}
template <class T>
IOperand const *	Operand<T>::operator/(IOperand const & rhs) const{
	if (this->getPrecision() < rhs.getPrecision())
		return rhs / *this;
	return new Operand<T>(boost::lexical_cast<std::string>(getValue() / static_cast<T>(std::stod(rhs.toString()))));
}
template <class T>
IOperand const *	Operand<T>::operator%(IOperand const & rhs) const{
	if (this->getPrecision() < rhs.getPrecision())
		return rhs % *this;
	return new Operand<T>(boost::lexical_cast<std::string>(fmod(getValue(), static_cast<T>(std::stod(rhs.toString())))));
}

