
#include "Bureaucrat.hpp"
#include <exception>
#include "AForm.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade too high!");
};

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade too low!");
};

const char* Bureaucrat::UnsignedFormException::what() const throw()
{
	return ("Unable to execute an unsigned form");
}

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	std::cout << "Bureaucrat default constructor called\n" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name)
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		(std::string) this->name = other.name;
		this->grade = other.grade;
	}
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw(GradeTooHighException());
	if (grade > 150)
		throw(GradeTooLowException());
	std::cout << "Bureaucrat constructor called\n" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string&	Bureaucrat::getName() const
{
	return (this->name);
}


const int&	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->grade - 1 < 1)
		throw (GradeTooHighException());
	else
		this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if ((this->grade + 1) > 150)
		throw (GradeTooLowException());
	else
		this->grade++;
}

void	Bureaucrat::signForm(AForm& AForm)
{
	try
	{
		AForm.beSigned(*this);
		std::cout << "✅ " << this->getName() << " signed " << AForm.getName() << " ✅" << std::endl;
	}
	catch (std::exception& e)
	{
	 	std::cerr << "🚨 " << this->getName() << " couldn't sign " << AForm.getName() << " because " << e.what() << " 🚨" << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& form)
{
	try
	{
		if (!form.getIsSigned())
		{
			std::cerr << "🚨 " << this->getName() << " couldn't execute " << form.getName() << " --> ";
			throw(Bureaucrat::UnsignedFormException());
		}
		if (this->getGrade() > form.getReqExcGrade())
		{
			std::cerr << "🚨 " << this->getName() << " couldn't execute " << form.getName() << " --> ";
			throw(AForm::GradeTooLowException());
		}
		std::cout << this->getName() << " executed " << form.getName();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

/*
	The << operator overloader cannot be defined as a Bureaucrat
	class member function. The reason for that is because it 
	needs to take an std::ostream as its first parameter to allow
	the operator to work with the output stream. So, If it were 
	defined as a Bereaucrat member function, it would imply that the 
	Bureaucrat class itself would be the left-hand operand in the 
	expression, which is not how the stream insertion operator is 
	typically used. 

	Now, since std::ostream& operator<<(std::ostream& o, const Bureaucrat& object),
	which is a function that is NOT A MEMBER OF THE BUREAUCRAT CLASS, takes a 
	CONST REFERENCE to a Bureaucrat object, I have to use the getters of the
	Bureaucrat class to access these members and the getters must have the
	CONST keyword at the end of their definition:
		const std::string&	getName() const;
		const int& 			getGrade() const;
	to allow these functions to work with CONST intances of the class as well, 
	which is what we have here because we said "const Bureaucrat& object" in
	the prototype:
		std::ostream& operator<<(std::ostream& o, const Bureaucrat& object)
*/
std::ostream& operator<<(std::ostream& o, const Bureaucrat& object)
{
	o << object.getName() <<", bureaucrat grade " << object.getGrade();

	return (o);
}
