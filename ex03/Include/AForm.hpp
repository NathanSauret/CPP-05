#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm
{
	protected:
		const std::string	_name;
		bool				_signed;
		const int			_grade_sign;
		const int			_grade_execute;

	public:
		// Constructors
		AForm();
		AForm( const AForm &src );
		AForm( const std::string name, const int grade_sign, const int grade_execute );

		// Destructor
		virtual ~AForm();

		// Operators overload
		AForm	&operator=( const AForm &src );

		// Get
		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeSign() const;
		int			getGradeExecute() const;

		// Class member functions
		void			beSigned( const Bureaucrat &bureaucrat );
		virtual void	execute( Bureaucrat const &executor ) const = 0;



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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<( std::ostream &os, AForm const &form );

#endif