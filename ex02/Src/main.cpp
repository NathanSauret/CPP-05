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



void	main_shrubbery(Bureaucrat &boss, Bureaucrat &last)
{
	sub_title("Create Shrubbery");
	ShrubberyCreationForm	shrubbery = ShrubberyCreationForm("home");

	sub_title("Last try to execute");
	last.executeForm(shrubbery);

	sub_title("Boss try to execute");
	boss.executeForm(shrubbery);

	sub_title("Last try to sign");
	last.signForm(shrubbery);

	sub_title("Boss try to sign");
	boss.signForm(shrubbery);

	sub_title("Last try to execute again");
	last.executeForm(shrubbery);

	sub_title("Boss try to execute again");
	boss.executeForm(shrubbery);

	sub_title("Destroy shrubbery");
}

void	main_robotomy(Bureaucrat &boss)
{
	sub_title("Create Robotomy");
	RobotomyRequestForm	robotomy = RobotomyRequestForm("not_a_robot");

	sub_title("Boss try to sign");
	boss.signForm(robotomy);


	sub_title("Boss try to execute five times in a row");
	boss.executeForm(robotomy);
	boss.executeForm(robotomy);
	boss.executeForm(robotomy);
	boss.executeForm(robotomy);
	boss.executeForm(robotomy);

	sub_title("Destroy roboty");
}

void	main_presidential(Bureaucrat &boss, Bureaucrat &last)
{
	sub_title("Create presidential");
	PresidentialPardonForm	presidential = PresidentialPardonForm("random_person");

	sub_title("Last try to execute");
	last.executeForm(presidential);

	sub_title("Boss try to execute");
	boss.executeForm(presidential);

	sub_title("Last try to sign");
	last.signForm(presidential);

	sub_title("Boss try to sign");
	boss.signForm(presidential);

	sub_title("Last try to execute again");
	last.executeForm(presidential);

	sub_title("Boss try to execute again");
	boss.executeForm(presidential);

	sub_title("Destroy presidential");
}

int	main()
{
	srand(time(0));

	title("CREATE BUREAUCRATS");
	sub_title("Create Bureaucrat Boss");
	Bureaucrat	boss = Bureaucrat("Boss", 1);
	sub_title("Create Bureaucrat Last");
	Bureaucrat	last = Bureaucrat("Last", 150);
	std::cout << std::endl;

	title("SHRUBBERRY");
	main_shrubbery(boss, last);
	std::cout << std::endl;

	title("ROBOTOMY");
	main_robotomy(boss);
	std::cout << std::endl;

	title("PRESIDENTIAL");
	main_presidential(boss, last);
	std::cout << std::endl;

	title("BUREAUCRATS DESTRUCTION");

	return (0);
}
