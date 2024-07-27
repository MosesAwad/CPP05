
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <exception>

int main()
{

	std::cout << "\n---------------- MAIN 1 ----------------\n" << std::endl;
	{
		Intern	Joebas;
		AForm* form;
		Bureaucrat	Hanzaemon("Hanzaemon", 2);

		std::cout << "\n\n\t---------------------------------------" << std::endl;
		std::cout << "\t\tAttempting to create form" << std::endl;
		std::cout << "\t---------------------------------------" << std::endl;
		try 
		{
			form = Joebas.makeForm("robotomy request", "Genji Shimada");
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}


		std::cout << "\n\n\t---------------------------------------" << std::endl;
		std::cout << "\t\tAttempting to execute form" << std::endl;
		std::cout << "\t---------------------------------------" << std::endl;
		try 
		{
			form->execute(Hanzaemon);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << "\n\n\t---------------------------------------" << std::endl;
		std::cout << "\t\tAttempting to sign form" << std::endl;
		std::cout << "\t---------------------------------------" << std::endl;
		try 
		{
			form->beSigned(Hanzaemon);
			std::cout << "\nSigning complete" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << "\n\n\t---------------------------------------" << std::endl;
		std::cout << "\t\tAttempting to re-execute form" << std::endl;
		std::cout << "\t---------------------------------------" << std::endl;
		try 
		{
			form->execute(Hanzaemon);
			std::cout << "\nExecution complete\n" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		delete(form);
	}
	return (0);
}
