#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:

	public:
		// Constructors
		Intern();
		Intern( const Intern &src );

		// Destructor
		~Intern();

		// Operators overload
		Intern	&operator=( const Intern &src );

		// Class member functions
		AForm	*makeForm( const std::string form, const std::string target );
};

#endif