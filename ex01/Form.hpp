
#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

/*
	This is known as a Forward Declaration.

	In Form.hpp, only a forward declaration of Bureaucrat is used because
	the Form class only needs to reference Bureaucrat as a type. The same
	applies to Bureaucrat.hpp with Form.

	Otherwise, doing include "Form.hpp" in Bureaucrat.hpp and doing
	include "Bureaucrat.hpp" in Form.hpp would result in the following
	error:
		In included file: main file cannot be included recursively when
		building a preamble
*/
class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			reqSignGrade;
		const int			reqExcGrade;
		Form();
	public:
		class GradeTooHighException;
		class GradeTooLowException;
		Form(const std::string name, const int req_sign_grade, const int req_exc_grade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		const std::string&	getName() const;
		const bool&			getIsSigned() const;
		const int&			getReqSignGrade() const;
		const int&			getReqExcGrade() const;
		void				beSigned(const Bureaucrat& bureaucrat);
};

class Form::GradeTooHighException : public std::exception
{
	const char* what() const throw();
};

class Form::GradeTooLowException : public std::exception
{
	const char* what() const throw();
};

std::ostream&	operator<<(std::ostream& o, const Form& object);

#endif