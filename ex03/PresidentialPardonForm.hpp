
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;
		PresidentialPardonForm();
	public:
		class UnsignedFormException;
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();
		void	execute(const Bureaucrat& executor) const;
};

class PresidentialPardonForm::UnsignedFormException : public std::exception
{
	public:
		const char*	what() const throw();
};

#endif