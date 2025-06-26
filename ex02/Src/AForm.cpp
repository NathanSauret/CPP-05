#include "../Include/bureau.hpp"

AForm::AForm() : _name("random_name"), _signed(false), _grade_sign(150), _grade_execute(150)
{
	std::cout << "\tForm default constructor called" << std::endl;
}

AForm::AForm( const AForm &src ) : _name(src._name), _signed(src._signed), _grade_sign(src._grade_sign), _grade_execute(src._grade_execute)
{
	std::cout << "\tForm copy constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int grade_sign, const int grade_execute) : _name(name), _signed(false), _grade_sign(grade_sign), _grade_execute(grade_execute)
{
	std::cout << "\tForm constructor with infos called" << std::endl;
}



// Destructor
AForm::~AForm()
{
	std::cout << "\tForm " << this->_name << " destroyed" << std::endl;
}



// Operators overload
AForm	&AForm::operator=( const AForm &src )
{
	std::cout << "\tForm assignation operator called" << std::endl;
	this->_signed = src._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, AForm const &form)
{
	os << "Name: " << form.getName() << " isSigned: " << form.getSigned() << " SignGrade: " << form.getGradeSign() << " ExecuteGrade: " << form.getGradeExecute();
	return (os);
}



// Get
std::string	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSigned() const
{
	return (this->_signed);
}

int	AForm::getGradeSign() const
{
	return (this->_grade_sign);
}

int	AForm::getGradeExecute() const
{
	return (this->_grade_execute);
}



// Class member functions
void	AForm::beSigned( const Bureaucrat &bureaucrat )
{
	if (bureaucrat.getGrade() > _grade_sign)
		throw GradeTooLowException();
	else
		this->_signed = true;
}



// Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form needs to be signed before executing");
};