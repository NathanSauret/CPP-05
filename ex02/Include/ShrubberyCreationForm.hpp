#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string	_target;

	public:
		// Constructors
		ShrubberyCreationForm();
		ShrubberyCreationForm( const ShrubberyCreationForm &src );
		ShrubberyCreationForm( std::string target );

		// Destructor
		~ShrubberyCreationForm();

		// Operators overload
		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm &src );

		// Get
		std::string	getTarget() const;

		// Class member functions
		void	execute( Bureaucrat const &executor )const;

};

std::ostream	&operator<<( std::ostream &o, ShrubberyCreationForm *a );

#endif