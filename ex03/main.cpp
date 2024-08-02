
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
		Intern		Joebas;
		AForm* 		form;
		Bureaucrat	Hanzaemon("Hanzaemon", 2);

		form = NULL;

		std::cout << "\n\n\t---------------------------------------" << std::endl;
		std::cout << "\t\tAttempting to create form" << std::endl;
		std::cout << "\t---------------------------------------" << std::endl;
		try 
		{
			// form = Joebas.makeForm("	   ", "Genji Shimada");
			form = Joebas.makeForm("rObOTomy rEQuEst", "Genji Shimada");
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		if (form == NULL)
			return (0);

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

	std::cout << "\n---------------- MAIN 2 ----------------\n" << std::endl;
	{
		Intern		Joebas;
		AForm* 		form;
		Bureaucrat	Hanzaemon("Hanzaemon", 2);

		form = NULL;

		std::cout << "\n\n\t---------------------------------------" << std::endl;
		std::cout << "\t\tAttempting to create form" << std::endl;
		std::cout << "\t---------------------------------------" << std::endl;
		try 
		{
			form = Joebas.makeForm("Shruppopry Creation", "Genji Shimada");
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << "\n";

		if (form == NULL)
			return (0);
		delete(form);
	}
	return (0);
}
