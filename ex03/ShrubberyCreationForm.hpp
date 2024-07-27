
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <exception>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
		ShrubberyCreationForm();
	public:
		class InvalidFileException;
		class UnsignedFormException;
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
		void		execute(const Bureaucrat& executor) const;
};

class ShrubberyCreationForm::InvalidFileException : public std::exception 
{
	public:
		const char* what() const throw();
};

class ShrubberyCreationForm::UnsignedFormException : public std::exception 
{
	public:
		const char* what() const throw();
};

#endif