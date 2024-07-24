
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
		Bureaucrat();
	public:
		class GradeTooHighException;
		class GradeTooLowException;
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		const std::string&	getName() const;
		const int& 			getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
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

std::ostream&		operator<<(std::ostream& o, const Bureaucrat& object);

#endif