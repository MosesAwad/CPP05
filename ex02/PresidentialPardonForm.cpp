
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

const char* PresidentialPardonForm::UnsignedFormException::what() const throw()
{
	return ("Cannot execute an unsigned form");
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5),
													target("Default")
{
	std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Presidential Pardon Form", 25, 5),
																			target(target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm("Presidential Pardon Form", 25, 5)
{
	*this = other;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
		this->target = other.target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!(this->getIsSigned()))
		throw(PresidentialPardonForm::UnsignedFormException());
	if (executor.getGrade() > this->getReqExcGrade())
		throw(AForm::GradeTooLowException());
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
