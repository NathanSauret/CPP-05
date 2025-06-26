#include "../Include/bureau.hpp"



// Constructors
Intern::Intern()
{
	std::cout << "\tIntern default constructor called" << std::endl;
}

Intern::Intern( const Intern &src )
{
	std::cout << "\tIntern copy constructor called" << std::endl;
	*this = src;
}



// Destructor
Intern::~Intern()
{
	std::cout << "\tIntern destructor called" << std::endl;
}



// Operators overload
Intern	&Intern::operator=( const Intern &src )
{
	std::cout << "\tIntern operator assignement called" << std::endl;
	return (*this);
}



// Class member functions
AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*makeRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*makePresidential(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm( const std::string form, const std::string target )
{
	AForm *(*forms_functions[])(const std::string target) = {&makeShrubbery, &makeRobotomy, &makePresidential};
	std::string forms_names[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for (int i=0; i<3; i++)
	{
		if (form == forms_names[i])
		{
			std::cout << GREEN << "\tIntern creates " << form << RESET << std::endl;
			return (forms_functions[i](target));
		}
	}
	std::cout << RED << "\tIntern could't create the form, form " << form << " not recognized" << RESET << std::endl;
	return (NULL);
}