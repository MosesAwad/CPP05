
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int main()
{

	std::cout << "\n---------------- MAIN 1 ----------------\n" << std::endl;
	{
		Form MOR("Magistrate Office Refurbishing", 126, 132);
		std::cout << "\n";

		std::cout << MOR << std::endl;

		Bureaucrat Hanzaemon("Hanzaemon", 128);

		std::cout << "⏳ Hanzaemon attempts to sign the form and sanction the decision ⌛" << std::endl;
		try 
		{
			MOR.beSigned(Hanzaemon);
			std::cout << "✅ Hanzaemon was able to sign the form ✅" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << "🚨 Cannot sign grade 🚨 -> " << e.what() << std::endl;
		}

		std::cout << "\n\t-----------------------" << std::endl;
		std::cout << "\t| Promoting Hanzaemon |" << std::endl;
		std::cout << "\t-----------------------\n" << std::endl;
		Hanzaemon.incrementGrade();
		Hanzaemon.incrementGrade();

		std::cout << "⏳ Hanzaemon attempts to sign the form and sanction the decision ⌛" << std::endl;
		try 
		{
			MOR.beSigned(Hanzaemon);
			std::cout << "✅ Hanzaemon was able to sign the form ✅" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << "🚨 Cannot sign grade 🚨 -> " << e.what() << std::endl;
		}

		std::cout << "\n";
		std::cout << MOR << std::endl;
	}

	std::cout << "\n\n---------------- MAIN 2 ----------------\n" << std::endl;
	{
		Form MOR("Magistrate Office Refurbishing", 126, 132);
		std::cout << "\n";

		std::cout << MOR << std::endl;

		Bureaucrat Hanzaemon("Hanzaemon", 128);

		std::cout << MOR << std::endl;
		std::cout << "⏳ Hanzaemon attempts to sign the form and sanction the decision ⌛" << std::endl;

		Hanzaemon.signForm(MOR);
	
		std::cout << "\n\t-----------------------" << std::endl;
		std::cout << "\t| Promoting Hanzaemon |" << std::endl;
		std::cout << "\t-----------------------\n" << std::endl;
		Hanzaemon.incrementGrade();
		Hanzaemon.incrementGrade();

		std::cout << "⏳ Hanzaemon attempts to sign the form and sanction the decision ⌛" << std::endl;

		Hanzaemon.signForm(MOR);

		std::cout << "\n";
		std::cout << MOR << std::endl;
	}

	std::cout << "\n\n---------------- MAIN 3 ----------------\n" << std::endl;
	{
		try 
		{
			Form MOR("Magistrate Office Refurbishing", 151, 132);
			std::cout << MOR << std::endl;
		} 
		catch (std::exception& e) 
		{
			std::cerr << "Unable to create form because " << e.what() << std::endl;
		}
		std::cout << "\n";
	}
	return (0);
}
