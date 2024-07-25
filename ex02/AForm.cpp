
#include "AForm.hpp"
#include <exception>
#include <ostream>
#include <string>
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

AForm::AForm() : name("default"), isSigned(false), reqSignGrade(150), reqExcGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(const std::string name, 
			const int req_sign_grade, 
			const int req_exc_grade) 
			: name(name), 
			  isSigned(false),
			  reqSignGrade(req_sign_grade),
			  reqExcGrade(req_exc_grade)
{
	if (req_sign_grade > 150 || req_exc_grade > 150)
		throw (GradeTooLowException());
	if (req_sign_grade < 1 || req_exc_grade < 1)
		throw (GradeTooHighException());

	std::cout << "Form constructor called" << std::endl;
}

AForm::AForm(const AForm& other) : name(other.name),
								reqSignGrade(other.reqSignGrade),
								reqExcGrade(other.reqExcGrade)
{
	*this = other;
}

/*
	In C++, you can cast a const std::string to a non-const std::string
	type without errors because:

	1.	Copy Construction: When you cast a const std::string to a std::string,
		you're actually creating a new std::string object with the same value. 
		The original const std::string remains unchanged.

	2.	Temporary Object: The cast operation creates a temporary std::string 
		object that is not const, which you can then manipulate.

	However, this workaround does not work for int data types.
	For primitive types like int, you can’t cast a const int to a 
	non-const int and then modify it. Casting in C++ doesn’t change 
	the constness of an object; it’s more about converting between 
	types or changing how the type is interpreted. The cast doesn’t 
	affect the underlying immutability of a const object.
*/
AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		(std::string) this->name = other.name;
		this->isSigned = other.isSigned;
		// (int) this->reqSignGrade = other.reqSignGrade;
		// (int) this->reqExcGrade = other.reqExcGrade;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "Form destructor called" << std::endl;
}

const std::string&	AForm::getName() const
{
	return (this->name);
}

const bool&	AForm::getIsSigned() const
{
	return (this->isSigned);
}

const int&	AForm::getReqSignGrade() const
{
	return (this->reqSignGrade);
}

const int&	AForm::getReqExcGrade() const
{
	return (this->reqExcGrade);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->reqSignGrade >= bureaucrat.getGrade())
		this->isSigned = true;
	else
	 	throw(GradeTooLowException());
}

std::ostream& operator<<(std::ostream& o, const AForm& object)
{
	std::string	signed_status;

	if (!object.getIsSigned())
		signed_status = "False";
	else
	 	signed_status = "True";

	o 	<< "Name of the form -> " << object.getName() << std::endl
		<< "Signed status of the form -> "<<  signed_status << std::endl
		<< "Required grade to sign the form -> " << object.getReqSignGrade() << std::endl
		<< "Required grade to execute the form -> " << object.getReqExcGrade() << std::endl;

	return (o);
}
