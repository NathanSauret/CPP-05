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

	// if (str.length() + 8 + 3 + 2 >= 42)
	// 	return ;

	title.append("        ~~~ " + str + " ");
	while (title.length() < 42)
		title.append("~");
	
	std::cout << CYAN << title << RESET << std::endl;
}



void	main_no_name()
{
	sub_title("Constructor");
	Bureaucrat	no_name;

	sub_title("std::cout");
	std::cout << "\t" << no_name << std::endl;

	sub_title("Destructor");
}

void	main_name_and_grade()
{
	sub_title("Constructor");
	Bureaucrat	bob = Bureaucrat("Bob", 42);

	sub_title("std::cout");
	std::cout << "\t" << bob << std::endl;

	sub_title("Destructor");
}

void	main_copy()
{
	sub_title("Creating Bob");
	Bureaucrat	bob = Bureaucrat("Bob", 42);

	sub_title("Alice is a copy of Bob");
	Bureaucrat	alice = Bureaucrat(bob);

	sub_title("std::cout");
	std::cout << "\t  Bob : " << bob << std::endl;
	std::cout << "\tAlice : " << bob << std::endl;

	sub_title("Destructors");
}

void	main_boss()
{
	sub_title("Creating Boss");
	Bureaucrat	boss = Bureaucrat("Boss", 1);
	std::cout << "\t" << boss << std::endl;

	sub_title("Increment grade");
	try
	{
		boss.incrementGrade();
	}
	catch( const std::exception& e )
	{
		std::cerr << RED << "\tException caught: " << e.what() << RESET << std::endl;
	}
	std::cout << "\t" << boss << std::endl;

	sub_title("Decrement grade");
	try
	{
		boss.decrementGrade();
	}
	catch( const std::exception& e )
	{
		std::cerr << RED << "\tException caught: " << e.what() << RESET << std::endl;
	}
	std::cout << "\t" << boss << std::endl;

	sub_title("Destructor");
}

void	main_last()
{
	sub_title("Creating Last, with the lowest grade");
	Bureaucrat	last = Bureaucrat("Last", 150);
	std::cout << "\t" << last << std::endl;

	sub_title("Decrement grade");
	try
	{
		last.decrementGrade();
	}
	catch( const std::exception& e )
	{
		std::cerr << RED << "\tException caught: " << e.what() << RESET << std::endl;
	}
	std::cout << "\t" << last << std::endl;

	sub_title("Increment grade");
	try
	{
		last.incrementGrade();
	}
	catch( const std::exception& e )
	{
		std::cerr << RED << "\tException caught: " << e.what() << RESET << std::endl;
	}
	std::cout << "\t" << last << std::endl;

	sub_title("Destructor");
}

void	main_employee()
{
	sub_title("Creating Steve, an employee");
	Bureaucrat	steve = Bureaucrat("Steve", 42);
	std::cout << "\t" << steve << std::endl;

	sub_title("Decrement grade");
	try
	{
		steve.decrementGrade();
	}
	catch( const std::exception& e )
	{
		std::cerr << RED << "\tException caught: " << e.what() << RESET << std::endl;
	}
	std::cout << "\t" << steve << std::endl;

	sub_title("Increment grade");
	try
	{
		steve.incrementGrade();
	}
	catch( const std::exception& e )
	{
		std::cerr << RED << "\tException caught: " << e.what() << RESET << std::endl;
	}
	std::cout << "\t" << steve << std::endl;

	sub_title("Increment grade");
	try
	{
		steve.incrementGrade();
	}
	catch( const std::exception& e )
	{
		std::cerr << RED << "\tException caught: " << e.what() << RESET << std::endl;
	}
	std::cout << "\t" << steve << std::endl;

	sub_title("Destructor");
}

int	main()
{
	title("Default constructor");
	main_no_name();
	std::cout << std::endl;

	title("Constructor with name and grade");
	main_name_and_grade();
	std::cout << std::endl;

	title("Copy constructor");
	main_copy();
	std::cout << std::endl;

	title("Boss increment / decrement");
	main_boss();
	std::cout << std::endl;

	title("Last increment / decrement");
	main_last();
	std::cout << std::endl;

	title("Employee increment / decrement");
	main_employee();
	std::cout << std::endl;

	return (0);
}
