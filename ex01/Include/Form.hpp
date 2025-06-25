#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_grade_sign;
		const int			_grade_execute;

	public:
		// Constructors
		Form();
		Form( const Form &src );
		Form( const std::string name, const int grade_sign, const int grade_execute );

		// Destructor
		~Form();

		// Operators overload
		Form const &operator=( const Form &src );

		// Get
		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeSign() const;
		int			getGradeExecute() const;

		// Class member functions
		void	beSigned( const Bureaucrat &bureaucrat );



		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<( std::ostream &os,  Form const &form );

#endif