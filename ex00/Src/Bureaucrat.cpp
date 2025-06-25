#include "../Include/Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat() : _name("random_bureaucrat"), _grade(150)
{
	std::cout << "\tBureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &src ) : _name(src._name), _grade(src._grade)
{
	std::cout << "\tBureaucrat copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const std::string &name, const int &grade ) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
	std::cout << "\tBureaucrat constructor with grade " << this->_grade << " called" << std::endl;
}



// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\tBureaucrat "<< this->_name << " destroyed" << std::endl;
}



// Operators overload
Bureaucrat const	&Bureaucrat::operator=( const Bureaucrat &src )
{
	std::cout << "\tBureaucrat assignation operator called" << std::endl;
	this->_grade = src._grade;
	return (*this);
}

std::ostream &operator<<( std::ostream &os, Bureaucrat const &src )
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade();
	return (os);
}



// Get
std::string const	&Bureaucrat::getName() const
{
	return (this->_name);
}

int const	&Bureaucrat::getGrade() const
{
	return (this->_grade);
}



// Class member function
void	Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade += 1;
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade -= 1;
}



// Exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}