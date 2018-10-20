#ifndef OPERAND_TPP
# define OPERAND_TPP

#include "IOperand.hpp"
#include "FactoryOperand.hpp"
#include <cmath>

template < typename T >
class Operand : public IOperand {

public:

	Operand(eOperandType e, T const &value);
	Operand(Operand<T> const &src);
	~Operand(void) { }

	eOperandType		getType(void) const;

	IOperand const		*operator*(IOperand const &rhs) const;
	IOperand const		*operator/(IOperand const &rhs) const;
	IOperand const		*operator+(IOperand const &rhs) const;
	IOperand const		*operator-(IOperand const &rhs) const;
	IOperand const		*operator%(IOperand const &rhs) const;

	std::string const	&toString(void) const;

private:
	eOperandType		const _eOperandType;
	T					const _value;
	std::string			const _stringValue;

	Operand				&operator=(Operand const &rhs);
	Operand(void);

	static IOperand const *_returnOperand(IOperand const &lhs, IOperand const &rhs, double value);

	static const bool	_debug;
};

template <typename T>
Operand<T>::Operand(eOperandType e, T const &value) :
	_eOperandType(e),
	_value(value),
	_stringValue(std::to_string(this->_value))
{ }

template <typename T>
Operand<T>::Operand(Operand<T> const &src) :
	_eOperandType(src._eOperandType),
	_value(src._value),
	_stringValue(std::to_string(this->_value))
{
	*this = src;
}

template <typename T>
std::string const	&Operand<T>::toString(void) const
{
	return (this->_stringValue);
}

template <typename T>
eOperandType		Operand<T>::getType(void) const
{
	return (this->_eOperandType);
}

template <typename T>
IOperand const *Operand<T>::operator*(IOperand const &rhs) const
{
	double value;

	value = static_cast<double>(this->_value) * static_cast<double>(stof(rhs.toString()));
	return (Operand<T>::_returnOperand(*this, rhs, value));
}
template <typename T>
IOperand const *Operand<T>::operator/(IOperand const &rhs) const
{
	double value;

	value = static_cast<double>(this->_value) / static_cast<double>(stof(rhs.toString()));
	return (Operand<T>::_returnOperand(*this, rhs, value));
}
template <typename T>
IOperand const *Operand<T>::operator-(IOperand const &rhs) const
{
	double value;

	value = static_cast<double>(this->_value) - static_cast<double>(stof(rhs.toString()));
	return (Operand<T>::_returnOperand(*this, rhs, value));
}
template <typename T>
IOperand const *Operand<T>::operator+(IOperand const &rhs) const
{
	double value;

	value = static_cast<double>(this->_value) + static_cast<double>(stof(rhs.toString()));
	return (Operand<T>::_returnOperand(*this, rhs, value));
}
template <typename T>
IOperand const *Operand<T>::operator%(IOperand const &rhs) const
{
	double value;

	value = std::fmod(static_cast<double>(this->_value), static_cast<double>(stof(rhs.toString())));
	return (Operand<T>::_returnOperand(*this, rhs, value));
}

template <typename T>
IOperand const *Operand<T>::_returnOperand(IOperand const &lhs, IOperand const &rhs, double value)
{
	if (lhs.getType() > rhs.getType())
		return (FactoryOperand::getInstance()->createOperand(lhs.getType(), std::to_string(value)));
	return (FactoryOperand::getInstance()->createOperand(rhs.getType(), std::to_string(value)));
}


#endif
