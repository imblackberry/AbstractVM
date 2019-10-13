#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP
#include <iostream>
#include <exception>

class Exception : public std::exception
{
	public:
				
		Exception();
		virtual ~Exception(void) throw();
		Exception(std::string const &message);
		Exception(Exception const &other);
		Exception & operator=(Exception const &r);
		virtual const char* what() const throw();

	private:
		std::string	_message;
};

#endif