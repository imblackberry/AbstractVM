#include "Exception.hpp"

Exception::Exception() { }
Exception::~Exception() throw() { }

Exception::Exception(Exception const & other) {
	*this = other;
}

Exception::Exception(std::string const & message) :
	_message(message) { }

Exception & Exception::operator=(Exception const &) { return *this; }

const char* Exception::what() const throw() {
	return _message.c_str();
}