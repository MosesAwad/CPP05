
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib> // for srand() and rand()
#include <ctime> // for time()

class RobotomyRequestForm : public AForm
{
	private:
		std::string	target;
		RobotomyRequestForm();
	public:
		class UnsignedFormException;
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();
		void	execute(const Bureaucrat& executor) const;
};

class RobotomyRequestForm::UnsignedFormException : public std::exception 
{
	public:
		const char* what() const throw();
};

#endif