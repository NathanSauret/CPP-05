#include "../Include/bureau.hpp"



// Constructors
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("no_target")
{
	std::cout << "\tPresidentialPardonForm default constructor called" << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &src ) : AForm("PresidentialPardonForm", 25, 5), _target("no_target")
{
	std::cout << "\tPresidentialPardonForm default constructor called" << std::endl;
	*this = src;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "\tPresidentialPardonForm constructor with target " << this->_target << " called" << std::endl;
}



// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\tPresidentialPardonForm destructor for " << this->_name << " called" << std::endl;
}



// Operators overload
PresidentialPardonForm	&PresidentialPardonForm::operator=( const PresidentialPardonForm &src )
{
	std::cout << "\tPresidentialPardonForm assignation operator called" << std::endl;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a)
{
	o << "Form " << a->getName() <<
	":\n\tsign-grade:\t" << a->getGradeSign() <<
	"\n\texec-grade:\t" << a->getGradeExecute() <<
	"\n\tis signed:\t" << a->getSigned() <<
	std::endl;
	return (o);
}



// Class member functions
void	PresidentialPardonForm::execute( Bureaucrat const &executor ) const
{
	if ((int)executor.getGrade() > this->getGradeExecute())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == false)
		throw (AForm::FormNotSignedException());

	std::cout << GREEN << "\t" << this->_target << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}



// Get
std::string	PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}