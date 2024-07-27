
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

/*
	This is known as a Forward Declaration.
	
	In Bureaucrat.hpp, only a forward declaration of Form is used because
	the Form class only needs to reference Bureaucrat as a type. The same
	applies to Form.hpp with Bureaucrat.

	Otherwise, doing include "Form.hpp" in Bureaucrat.hpp and doing
	include "Bureaucrat.hpp" in Form.hpp would result in the following
	error:
		In included file: main file cannot be included recursively when
		building a preamble
*/
class AForm;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
		Bureaucrat();
	public:
		class GradeTooHighException;
		class GradeTooLowException;
		class UnsignedFormException;
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		const std::string&	getName() const;
		const int& 			getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm& aform);
		void				executeForm(const AForm& form);
};

class Bureaucrat::GradeTooHighException : public std::exception
{
	public:
		const char* what() const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	public:
		const char* what() const throw();
};

class Bureaucrat::UnsignedFormException : public std::exception
{
	public:
		const char*	what() const throw();
};

std::ostream&		operator<<(std::ostream& o, const Bureaucrat& object);

#endif