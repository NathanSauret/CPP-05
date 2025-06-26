#include "../Include/bureau.hpp"



void	title(const std::string str)
{
	std::string	title;

	if (str.length() + 2 >= 42)
		return ;

	title.append(" " + str + " ");
	while (title.length() < 42)
		title.append("~");
	
	std::cout << YELLOW << title << RESET << std::endl;
}

void	sub_title(const std::string str)
{
	std::string	title;

	title.append("        ~~~ " + str + " ");
	while (title.length() < 42)
		title.append("~");
	
	std::cout << CYAN << title << RESET << std::endl;
}

void	main_existing_forms(Intern &intern)
{
	AForm* shrubbery;
	AForm* robotomy;
	AForm* presidential;

	sub_title("Intern make a shrubbery form");
	shrubbery = intern.makeForm("ShrubberyCreationForm", "home");

	sub_title("Intern make a robotomy form");
	robotomy = intern.makeForm("RobotomyRequestForm", "not_a_robot");

	sub_title("Intern make a presidential form");
	presidential = intern.makeForm("PresidentialPardonForm", "random_person");
	std::cout << std::endl;

	sub_title("Creating Boss and testing presidential");
	Bureaucrat	boss = Bureaucrat("Boss", 1);
	boss.signForm(*presidential);
	boss.executeForm(*presidential);
	std::cout << std::endl;

	sub_title("Delete shrubbery");
	delete shrubbery;
	sub_title("Delete robotomy");
	delete robotomy;
	sub_title("Delete presidential");
	delete presidential;
}

void	main_non_existing_forms(Intern &intern)
{
	AForm* form;

	sub_title("Intern make a gaming form");
	form = intern.makeForm("GamingSessionForm", "home");
}

int	main()
{
	title("Create intern");
	Intern intern;
	std::cout << std::endl;

	title("Testing with existing forms");
	main_existing_forms(intern);
	std::cout << std::endl;

	title("Testing with non-existing forms");
	main_non_existing_forms(intern);
	std::cout << std::endl;

	title("Delete Intern");

	return (0);
}
