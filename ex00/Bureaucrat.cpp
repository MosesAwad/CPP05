
#include "Bureaucrat.hpp"
#include <exception>


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade too high!");
};

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade too low!");
};

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	std::cout << "Bureaucrat default constructor called\n" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw(GradeTooHighException());
	if (grade > 150)
		throw(GradeTooLowException());
	std::cout << "Bureaucrat constructor called\n" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name)
{
	*this = other;
}

/*
	In here, I cast const std::string to just std::string
	on the name attribute as follows:
		(std::string) this->name = other.name;
	but this is just to shut the compiler up. It, however,
	has no effect on the name. No matter what you do, the
	name attribute can never be reassigned so yes, the following
	line:
		(std::string) this->name = other.name;
	is effecitvely useless, it's just a formality.

	Check Main 3 to see the difference.
*/
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		(std::string) this->name = other.name;
		this->grade = other.grade;
	}
	return (*this);
}

const std::string&	Bureaucrat::getName() const
{
	return (this->name);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

const int&	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	if ((this->grade - 1) < 1)
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
