#include "../Include/ex01.hpp"

Form::Form() : _name("random_name"), _signed(false), _grade_sign(150), _grade_execute(150)
{
	std::cout << "\tForm default constructor called" << std::endl;
}

Form::Form( const Form &src ) : _name(src._name), _signed(src._signed), _grade_sign(src._grade_sign), _grade_execute(src._grade_execute)
{
	std::cout << "\tForm copy constructor called" << std::endl;
}

Form::Form(const std::string name, const int grade_sign, const int grade_execute) : _name(name), _signed(false), _grade_sign(grade_sign), _grade_execute(grade_execute)
{
	std::cout << "\tForm constructor with infos called" << std::endl;
}



// Destructor
Form::~Form()
{
	std::cout << "\tForm " << this->_name << " destroyed" << std::endl;
}



// Operators overload
Form const	&Form::operator=( const Form &src )
{
	std::cout << "\tForm assignation operator called" << std::endl;
	this->_signed = src._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &os,  Form const &form)
{
	os << "Name: " << form.getName() << " isSigned: " << form.getSigned() << " SignGrade: " << form.getGradeSign() << " ExecuteGrade: " << form.getGradeExecute();
	return (os);
}



// Get
std::string	Form::getName() const
{
	return (this->_name);
}

bool	Form::getSigned() const
{
	return (this->_signed);
}

int	Form::getGradeSign() const
{
	return (this->_grade_sign);
}

int	Form::getGradeExecute() const
{
	return (this->_grade_execute);
}



// Class member functions
void	Form::beSigned( const Bureaucrat &bureaucrat )
{
	if (bureaucrat.getGrade() > _grade_sign)
		throw GradeTooLowException();
	else
		this->_signed = true;
}



// Exceptions
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}