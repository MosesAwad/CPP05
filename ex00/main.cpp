
#include "Bureaucrat.hpp"

int main()
{

	std::cout << "\n--------- MAIN 1 ---------\n" << std::endl;
	{
		Bureaucrat Moosa("Moosa", 2);

		std::cout << "Initially -> " << Moosa << std::endl;
		try
		{
			Moosa.incrementGrade();
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}


		std::cout << "Now -> " << Moosa << std::endl;

		std::cout << "\nAttempt to increment grade beyond 1" << std::endl;
		try
		{

			Moosa.incrementGrade();
			std::cout << "should not print because we threw an error in Moosa.getGrade()" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "Grade did not change -> " << Moosa << std::endl;
		std::cout << "\n";
	}


	std::cout << "\n--------- MAIN 2 ---------" << std::endl;
	{

		Bureaucrat Moosa("Moosa", 1);

		std::cout << "Initially -> " << Moosa << std::endl;
		try
		{
			for (int i = 0; i < 149; i++)
			Moosa.decrementGrade();
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << "Now -> " << Moosa << std::endl;

		std::cout << "\nAttempt to decrement grade beyond 150" << std::endl;
		try
		{
			Moosa.decrementGrade();
			std::cout << "should not print because we threw an error in Moosa.getGrade()" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "Grade did not change -> " << Moosa << std::endl;
		std::cout << "\n";
	}


	std::cout << "\n--------- MAIN 3 ---------" << std::endl;
	{
		Bureaucrat Carlito("Carlito", 126);
		Bureaucrat Joebas("Joebas", 138);

		Joebas = Carlito;
		std::cout << "Logistics of Joebas 😂 -> " << Joebas << std::endl;
		std::cout << "\n";

		Bureaucrat Hanzaemon(Carlito);
		std::cout << "Logistics of Hanzaemon (in Carlito form) 🏯 -> " << Hanzaemon << std::endl;
		std::cout << "\n";
	}
	return (0);
}
