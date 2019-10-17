#include "Operand.hpp"
#include "Exception.hpp"
template <class T>
Operand<T>::Operand(){}

template <class T>
Operand<T>::~Operand(){}

template <class T>
Operand<T>::Operand(std::string str) {
	double tmp = std::stod(str);
	if (str.front() == '0')
		throw Exception("value starts with 0");
	if (tmp < std::numeric_limits<T>::min())
		throw Exception("stack underflow");
	else if (tmp > std::numeric_limits<T>::max())
		throw Exception("stack overflow");
	T n = static_cast<T>(tmp);
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
template <>
IOperand const *	Operand<int8_t>::operator%(IOperand const & rhs) const{
	if (rhs.getType() >= eOperandType::Float ||
		this->getPrecision() < rhs.getPrecision())
		return rhs % *this;
	return new Operand<int8_t>(DoubleToString(getValue() % std::stoi(rhs.toString())));
}

template<>
eOperandType		Operand<int16_t>::getType(void) const{ return Int16; }
template<>
int					Operand<int16_t>::getPrecision(void) const{ return Int16; }
template<>
IOperand const *	Operand<int16_t>::operator%(IOperand const & rhs) const{
	if (rhs.getType() >= eOperandType::Float ||
		this->getPrecision() < rhs.getPrecision())
		return rhs % *this;
	return new Operand<int16_t>(DoubleToString(getValue() % std::stoi(rhs.toString())));
}

template<>
eOperandType		Operand<int32_t>::getType(void) const{ return Int32; }
template<>
int					Operand<int32_t>::getPrecision(void) const{ return Int32; }
template<>
IOperand const *	Operand<int32_t>::operator%(IOperand const & rhs) const{
	if (rhs.getType() >= eOperandType::Float ||
		this->getPrecision() < rhs.getPrecision())
		return rhs % *this;
	return new Operand<int32_t>(DoubleToString(getValue() % std::stoi(rhs.toString())));
}

template<>
eOperandType		Operand<float>::getType(void) const{ return Float; }
template<>
int					Operand<float>::getPrecision(void) const{ return Float; }
template<>
IOperand const *	Operand<float>::operator%(IOperand const &) const{
	throw Exception("mod floating point");
}
template<>
eOperandType		Operand<double>::getType(void) const{ return Double; }
template<>
int					Operand<double>::getPrecision(void) const{ return Double; }
template<>
IOperand const *	Operand<double>::operator%(IOperand const &) const{
	throw Exception("mod floating point");
}

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
	if (this->getPrecision() < rhs.getPrecision())
		return rhs - *this;
	return new Operand<T>(DoubleToString(getValue() - std::stod(rhs.toString())));
}

template <class T>
IOperand const *	Operand<T>::operator/(IOperand const & rhs) const{
	auto otherVal = std::stod(rhs.toString());
	if (getValue() == 0 || otherVal == 0)
		throw Exception("div with 0");
	if (this->getPrecision() < rhs.getPrecision())
		return rhs / *this;
	return new Operand<T>(DoubleToString(getValue() / otherVal));
}

// template <class T>
// IOperand const *	Operand<T>::operator%(IOperand const & rhs) const{
// 	if (rhs.getType() >= eOperandType::Float)
// 		throw Exception("mod floating point");
// 	else {
// 		if (this->getPrecision() < rhs.getPrecision())
// 			return rhs % *this;
// 		return new Operand<T>(DoubleToString(getValue() % std::stod(rhs.toString())));
// 	}
// }

// --------------------------------------------------------------------------//
// 								5 CLASS DECLARATION							 //
// --------------------------------------------------------------------------//

template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<float>;
template class Operand<double>;