
#include "Bureaucrat.hpp"
#include <exception>

int main()
{
		std::cout << "\n--------- MAIN 1 ---------" << std::endl;
	{
		Bureaucrat Moosa("Moosa", 2);

		std::cout << "Grade is initially " << Moosa.getGrade() << std::endl;
		try
		{
			Moosa.incrementGrade();
			std::cout << "Grade is now " << Moosa.getGrade() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{

			std::cout << "\nAttempt to increment grade beyond 1" << std::endl;
			Moosa.incrementGrade();
			std::cout << "Grade is still " << Moosa.getGrade() << std::endl;
			std::cout << "should not print because we threw an error in Moosa.getGrade()" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

		std::cout << "\n--------- MAIN 2 ---------" << std::endl;
	{

		Bureaucrat Moosa("Moosa", 1);

		std::cout << "Grade is initially " << Moosa.getGrade() << std::endl;
		try
		{
			for (int i = 0; i < 149; i++)
			Moosa.decrementGrade();
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "Grade is now " << Moosa.getGrade() << std::endl;

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
		std::cout << "Grade is still " << Moosa.getGrade() << std::endl;
	}

	return (0);
}
