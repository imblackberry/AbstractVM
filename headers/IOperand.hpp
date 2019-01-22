class IOperand { public:
virtual int getPrecision( void ) const = 0; virtual eOperandType getType( void ) const = 0;
virtual IOperand const * operator+( IOperand const & virtual IOperand const * operator-( IOperand const & virtual IOperand const * operator*( IOperand const & virtual IOperand const * operator/( IOperand const & virtual IOperand const * operator%( IOperand const &
  // Precision of the type of the instance
  // Type of the instance
rhs ) const = 0; // Sum
rhs ) const = 0; // Difference rhs ) const = 0; // Product rhs ) const = 0; // Quotient rhs ) const = 0; // Modulo
 virtual std::string const & toString( void ) const = 0; // String representation of the instance
virtual ~IOperand( void ) {} };