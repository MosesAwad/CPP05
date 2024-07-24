
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
			std::cout << "🚨 Cannot sign grade 🚨 -> " << e.what() << std::endl;
		}

		std::cout << "\n\t--------------------" << std::endl;
		std::cout << "\tPromoting Hanzaemon" << std::endl;
		std::cout << "\t--------------------\n" << std::endl;
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
			std::cout << "🚨 Cannot sign grade 🚨 -> " << e.what() << std::endl;
		}

		std::cout << "\n";
		std::cout << MOR << std::endl;
	}

	return (0);
}
