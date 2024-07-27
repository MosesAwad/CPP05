
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>

int main()
{

	std::cout << "\n---------------- MAIN 1 ----------------\n" << std::endl;
	{
		ShrubberyCreationForm Mori("Sekigahara");
		Bureaucrat Hanzaemon("Hanzaemon", 98);


		try 
		{
			Mori.execute(Hanzaemon);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n";

		try 
		{
			Hanzaemon.signForm(Mori);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << "\n";
		try 
		{
			Mori.execute(Hanzaemon);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n";
	}

	std::cout << "\n---------------- MAIN 2 ----------------\n" << std::endl;
	{
		RobotomyRequestForm GenjiForm("Shimada Genji");
		Bureaucrat Hanzaemon("Hanzaemon", 28);

		try 
		{
			GenjiForm.execute(Hanzaemon);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n";

		try 
		{
			Hanzaemon.signForm(GenjiForm);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << "\n";
		try 
		{
			GenjiForm.execute(Hanzaemon);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n";
		std::cout << "\n";
	}

	std::cout << "\n---------------- MAIN 3 ----------------\n" << std::endl;
	{
		PresidentialPardonForm Pardon("Ishida Mitsunari");
		Bureaucrat Tokugawa("Tokugawa Ieyasu", 28);

		Tokugawa.executeForm(Pardon);
		std::cout << "\n";

		Tokugawa.signForm(Pardon);

		std::cout << "\n\t---------------------------------------" << std::endl;
		std::cout << "\t| Promoting Tokugawa Ieyasu to Shogun |" << std::endl;
		std::cout << "\t---------------------------------------\n" << std::endl;

		for (int i = 28; i >= 5; i--) {
			Tokugawa.incrementGrade();
		}

		Tokugawa.signForm(Pardon);

		std::cout << "\n";

		Tokugawa.executeForm(Pardon);

		std::cout << "\n";
		std::cout << "\n";
	}
	return (0);
}
