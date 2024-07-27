
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"

const char* Intern::InvalidRequest::what() const throw()
{
	return ("cannot proceed with this request! Please enter a valid option");
}

Intern::Intern()
{
	std::cout << "Intern Default constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void) other;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

static AForm* makeRobotomyPTR(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

static AForm* makeShrubberyPTR(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm* makePresidentialPTR(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

/*
	Function pointers in C++ are powerful tools that allow for more flexible 
	and dynamic code. Here are some key reasons for using function pointers:

	1. Callback Mechanisms:
		Function pointers are often used in callback mechanisms where you need
		to pass a function as an argument to another function. This is common in
		event-driven programming, such as handling user input or processing asynchronous events.
	
	2. Function Tables:
		You can create arrays of function pointers (function tables) to map input
		values to specific functions. This is a common technique in interpreters,
		compilers, and virtual machines for handling different operations or commands.
*/
AForm*	Intern::makeForm(const std::string form_name, const std::string target)
{
	t_funcs func_arr[3] = {
		{"robotomy request" , makeRobotomyPTR},
		{"shrubbery creation", makeShrubberyPTR},
		{"presidential pardon", makePresidentialPTR}
	};

	for (int i = 0; i < 3; i++) {
		if (form_name == func_arr[i].form_name)
		{
			std::cout << "Intern creates " << func_arr[i].form_name <<std::endl;
			return (func_arr[i].funcptr(target));
		}
	}
	throw InvalidRequest();
}
