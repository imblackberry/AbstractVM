#include "Operand.hpp"
template <class T>
Operand<T>::Operand(){}

template <class T>
Operand<T>::Operand(std::string str) {
	T n = static_cast<T>(std::stod(str));
	_strValue = DoubleToString(n);
}

template <class T>
Operand<T>::Operand(const Operand<T> & other){
	*this = other;
}

template <class T>
Operand<T> const & Operand<T>::operator=(Operand<T> const & other){
	if (this != &other){
		_strValue = other._strValue;
	}
	return *this;
}

template <class T>
std::string const & Operand<T>::toString( void ) const { return _strValue; }

template <class T>
T const 			Operand<T>::getValue() const {
	return static_cast<T>(std::stod(toString()));
}

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
	return new Operand<T>(DoubleToString(getValue() + std::stod(rhs.toString()))); //need i cast ?
}

template <class T>
IOperand const *	Operand<T>::operator*(IOperand const & rhs) const{
	if (this->getPrecision() < rhs.getPrecision())
		return rhs * *this;
	return new Operand<T>(DoubleToString(getValue() * std::stod(rhs.toString())));
}

template <class T>
IOperand const * Operand<T>::operator-(IOperand const & rhs) const{
	OperandFactory factory;

	eOperandType type = std::max(getType(), rhs.getType());
	return factory.createOperand(type, DoubleToString(getValue() - std::stod(rhs.toString())));
}

template <class T>
IOperand const *	Operand<T>::operator/(IOperand const & rhs) const{
	OperandFactory factory;

	eOperandType type = std::max(getType(), rhs.getType());
	return factory.createOperand(type, DoubleToString(getValue() / std::stod(rhs.toString())));
}
template <class T>
IOperand const *	Operand<T>::operator%(IOperand const & rhs) const{
	OperandFactory factory;

	eOperandType type = std::max(getType(), rhs.getType());
	return factory.createOperand(type, DoubleToString(fmod(getValue(), std::stod(rhs.toString()))));
}

// --------------------------------------------------------------------------//
// 								5 CLASS DECLARATION							 //
// --------------------------------------------------------------------------//
// explicit instantiations
template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<float>;
template class Operand<double>;
//I will only be able to use Operand with this 5 types