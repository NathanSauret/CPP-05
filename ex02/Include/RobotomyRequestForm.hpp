#ifndef ROOTOMYREQUESTFORM_HPP
#define ROOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	_target;

	public:
		// Constructors
		RobotomyRequestForm();
		RobotomyRequestForm( const RobotomyRequestForm &src );
		RobotomyRequestForm( std::string target );

		// Destructor
		~RobotomyRequestForm();

		// Operators overload
		RobotomyRequestForm	&operator=( const RobotomyRequestForm &src );

		// Get
		std::string	getTarget() const;

		// Class member functions
		void	execute( Bureaucrat const &executor )const;

};

std::ostream	&operator<<( std::ostream &o, RobotomyRequestForm *a );

#endif