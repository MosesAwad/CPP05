
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5),
													target("Default")
{
	std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Default", 25, 5),
																			target(target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

 