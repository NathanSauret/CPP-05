#include "../Include/bureau.hpp"



// Constructors
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("no_target")
{
	srand(time(0));
	std::cout << "\tRobotomyRequestForm default constructor called" << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &src ) : AForm("RobotomyRequestForm", 72, 45), _target("no_target")
{
	std::cout << "\tRobotomyRequestForm default constructor called" << std::endl;
	*this = src;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	srand(time(0));
	std::cout << "\tRobotomyRequestForm constructor with target " << this->_target << " called" << std::endl;
}



// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\tRobotomyRequestForm destructor for " << this->_name << " called" << std::endl;
}



// Operators overload
RobotomyRequestForm	&RobotomyRequestForm::operator=( const RobotomyRequestForm &src )
{
	std::cout << "\tRobotomyRequestForm assignation operator called" << std::endl;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a)
{
	o << "Form " << a->getName() <<
	":\n\tsign-grade:\t" << a->getGradeSign() <<
	"\n\texec-grade:\t" << a->getGradeExecute() <<
	"\n\tis signed:\t" << a->getSigned() <<
	std::endl;
	return (o);
}



// Class member functions
void	RobotomyRequestForm::execute( Bureaucrat const &executor ) const
{
	if ((int)executor.getGrade() > this->getGradeExecute())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == false)
		throw (AForm::FormNotSignedException());

	if (rand() % 2 == 1)
		std::cout << GREEN << "\t" << this->_target << " got robotomized successfully" << RESET << std::endl;
	else
		std::cout << RED << "\t" << this->_target << " died, shit happens ¯\\_(ツ)_/¯" << RESET << std::endl;
}



// Get
std::string	RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}