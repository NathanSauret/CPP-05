#include "../Include/ex01.hpp"



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


void	main_sign()
{
	sub_title("Create Bureaucrat");
	Bureaucrat	bob = Bureaucrat("Bob", 42);
	std::cout << "\t" << bob << std::endl;

	sub_title("Create Form");
	Form	form = Form("form", 50, 25);
	std::cout << "\t" << form << std::endl;

	sub_title("Try to sign form");
	bob.signForm(form);

	sub_title("Destructors");
}

void	main_cant_sign()
{
	sub_title("Create Bureaucrat");
	Bureaucrat	bob = Bureaucrat("Bob", 64);
	std::cout << "\t" << bob << std::endl;

	sub_title("Create Form");
	Form	form = Form("form", 50, 25);
	std::cout << "\t" << form << std::endl;

	sub_title("Try to sign form");
	bob.signForm(form);

	sub_title("Destructors");
}


int	main()
{
	title("Sign Form");
	main_sign();
	std::cout << std::endl;

	title("Can't sign Form");
	main_cant_sign();
	std::cout << std::endl;

	return (0);
}
