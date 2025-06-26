#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
	private:
		const std::string	_target;

	public:
		// Constructors
		PresidentialPardonForm();
		PresidentialPardonForm( const PresidentialPardonForm &src );
		PresidentialPardonForm( std::string target );

		// Destructor
		~PresidentialPardonForm();

		// Operators overload
		PresidentialPardonForm	&operator=( const PresidentialPardonForm &src );

		// Get
		std::string	getTarget() const;

		// Class member functions
		void	execute( Bureaucrat const &executor )const;

};

std::ostream	&operator<<( std::ostream &o, PresidentialPardonForm *a );

#endif