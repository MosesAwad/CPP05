
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

const char*	ShrubberyCreationForm::InvalidFileException::what() const throw()
{
	return ("Error opening file");
}

const char*	ShrubberyCreationForm::UnsignedFormException::what() const throw()
{
	return ("Unable to execute an unsigned form");
}

/*
	Since we are asked by the subject PDF to keep the attributes of AForm private
	instead of protected, for some STUPID reason, I am unable to do the following:
		ShrubberyCreationForm::ShrubberyCreationForm() : target("Default"),
															name("Default"), 
															reqSignGrade(145),
															reqExcGrade(137)

	But we can do instead is to initialize the parent class AForm portion of
	the ShrubberyCreationForm class directly using the parent (AForm) class's
	constructor as shown below.
*/
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137),
													target("Default")
{
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery Creation Form", 145, 137), 
																			target(target)
{
																			
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm("Shrubbery Creation From", 145, 137)
{
	*this = other;
}

/*
	The contents AForm will automatically be the same so no need
	to copy them because the contents of AForm are private and
	they will always be initialized to the same values and stay
	as those values for every object of the ShrubberyCreationForm
	class.
*/
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		this->target = other.target;

	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!(this->getIsSigned()))
		throw(ShrubberyCreationForm::UnsignedFormException());
	if (executor.getGrade() > this->getReqExcGrade())
		throw(AForm::GradeTooLowException());
	
	std::ofstream tree_file((target + "_shrubbery").c_str());
	if (!tree_file.is_open())
		throw(ShrubberyCreationForm::InvalidFileException());

	std::string forest = 	"    *         *         *         *\n"
							"   ***       ***       ***       ***\n"
							"  *****     *****     *****     *****\n"
							" *******   *******   *******   *******\n"
							"********* ********* ********* *********\n"
							"    |         |         |         |\n";
	
	for (int i = 0; i <= 25; i++)
		tree_file << forest << "\n";	
}
