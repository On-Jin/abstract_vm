#include <iostream>
#include "InstructionPop.hpp"
#include "AvmCore.hpp"

InstructionPop::InstructionPop(void) :
_type(Pop)
{
	if (InstructionPop::_debug)
		std::cout << "InstructionPop:: Default constructor called." << std::endl;
	return ;
}

InstructionPop::InstructionPop(InstructionPop const &src) :
_type(Pop)
{
	if (InstructionPop::_debug)
		std::cout << "InstructionPop:: Copy constructor called." << std::endl;
	*this = src;
	return ;
}

InstructionPop::~InstructionPop(void)
{
	if (InstructionPop::_debug)
		std::cout << "InstructionPop:: Destructor called." << std::endl;
	return ;
}

InstructionPop		&InstructionPop::operator=(InstructionPop const &rhs)
{
	if (InstructionPop::_debug)
		std::cout << "InstructionPop:: Assignement called." << std::endl;
	if (this != &rhs)
	{
	}
	return (*this);
}

eInstructionType		InstructionPop::getType(void) const
{
	return (this->_type);
}

void					InstructionPop::execute(AvmCore &avm) const
{
	if (!avm.getStack().size())
		throw(AvmCore::StackTooSmall("Trying Pop a empty stack"));

	IOperand const *v1 = avm.getStack().top();
	avm.getStack().pop();

	delete v1;
}

const bool		InstructionPop::_debug = 0;
