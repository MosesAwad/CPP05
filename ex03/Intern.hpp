
#ifndef INTERN_HPP
# define INTERN_HPP

#include <exception>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern 
{
	private:
		typedef struct s_funcs
		{
			const std::string form_name;
			AForm*	(*funcptr) (const std::string&);
		} t_funcs;
	public:
		class InvalidRequest;
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();
		AForm*	makeForm(const std::string form_name, const std::string target);
};

class Intern::InvalidRequest : public std::exception
{
	public:
		const char* what() const throw();
};

#endif