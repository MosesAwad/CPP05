
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* RobotomyRequestForm::UnsignedFormException::what() const throw()
{
	return ("Cannot execute an unsigned form");
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), 
												target("Default")
{
	std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy Request Form", 72, 45), 
																		target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm("Robotomy Request Form", 72, 45)
{
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		this->target = other.target;

	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!(this->getIsSigned()))
		throw(RobotomyRequestForm::UnsignedFormException());
	if (executor.getGrade() > this->getReqExcGrade())
		throw(AForm::GradeTooLowException());

	std::cout << "Drilling into metal plates in process..." << std::endl;

	srand(static_cast<unsigned>(time(0))); // Seed the random number generator each time execute() is called
	if (rand() % 2)
		std::cout << this->target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy on " << this->target << " has failed." << std::endl;
}
