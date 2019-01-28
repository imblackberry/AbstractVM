#ifndef OPERAND_HPP
#define OPERAND_HPP
class Operand : public IOperand{
	public:
		Operand();
		Operand(const Operand & other);
		const Operand& operator=(const Operand & other);
		~Operand();
		virtual int					getPrecision(void) const;	// Precision of the type of the instance
		virtual	eOperandType		getType(void) const;	// Type of the instance
		virtual IOperand const *	operator+(IOperand const & rhs) const; // Sum
		virtual IOperand const *	operator-(IOperand const & rhs) const; // Difference
		virtual IOperand const *	operator*(IOperand const & rhs) const; // Product
		virtual IOperand const *	operator/(IOperand const & rhs) const; // Quotient
		virtual IOperand const *	operator%(IOperand const & rhs) const; // Modulo
		virtual std::string const & toString( void ) const = 0; // String representation of the instance
	private:
		std::deque<int> _value;
		short _precision;
		eOperandType _type;
};

#endif