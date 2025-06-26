#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		// Constructors
		Bureaucrat();
		Bureaucrat( const Bureaucrat &src );
		Bureaucrat(const std::string &name, const int &grade );

		// Destructor
		~Bureaucrat();

		// Operators overload
		Bureaucrat const	&operator=( const Bureaucrat &src );

		// Get
		std::string const	&getName() const;
		int const			&getGrade() const;

		// Class member functions
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(AForm &form);
		void	executeForm( AForm &form ) const;


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

std::ostream	&operator<<(std::ostream & os, Bureaucrat const &other);

#endif