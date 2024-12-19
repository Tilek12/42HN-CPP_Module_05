/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:12:36 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/19 20:15:25 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*--------------------------------*/
/*  Bureaucrat Class constructor  */
/*--------------------------------*/
Bureaucrat::Bureaucrat( const std::string& name, int grade ) : _name( name ),
															   _grade( grade ) {

	if ( _grade < 1 )
		throw GradeTooHighException();
	else if ( _grade > 150 )
		throw GradeTooLowException();
}

/*-------------------------------------*/
/*  Bureaucrat Class copy constructor  */
/*-------------------------------------*/
Bureaucrat::Bureaucrat( const Bureaucrat& other ) : _name( other._name ),
													_grade( other._grade ) {}

/*---------------------------------------------*/
/*  Bureaucrat Class copy assignment operator  */
/*---------------------------------------------*/
Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& other ) {

	if ( this != &other ) {
		_grade = other._grade;
	}

	return *this;
}

/*-------------------------------*/
/*  Bureaucrat Class destructor  */
/*-------------------------------*/
Bureaucrat::~Bureaucrat( void ) {}

/*---------------------------*/
/*  Define getName function  */
/*---------------------------*/
const std::string&	Bureaucrat::getName( void ) const { return _name; }

/*----------------------------*/
/*  Define getGrade function  */
/*----------------------------*/
int	Bureaucrat::getGrade( void ) const { return _grade; }

/*----------------------------------*/
/*  Define incrementGrade function  */
/*----------------------------------*/
void	Bureaucrat::incrementGrade( void ) {

	if ( _grade <= 1) {
		throw GradeTooHighException();
	}
	_grade--;
}

/*----------------------------------*/
/*  Define decrementGrade function  */
/*----------------------------------*/
void	Bureaucrat::decrementGrade( void ) {

	if ( _grade >= 150 ) {
		throw GradeTooLowException();
	}
	_grade++;
}

/*----------------------------*/
/*  Define signForm function  */
/*----------------------------*/
void	Bureaucrat::signForm( AForm& form ) const {

	if ( form.getIsSigned() ) {
		std::cout << PURPLE
				  << form.getName() << " is already signed."
				  << RESET << std::endl;
		return;
	}

	try {
		form.beSigned( *this );
		std::cout << YELLOW << _name << RESET
				  << GREEN << " signed " << RESET
				  << BLUE << form.getName() << RESET
				  << std::endl;
	} catch(const std::exception& e) {
		std::cout << YELLOW << _name << RESET
				  << PURPLE << " couldn't sign " << RESET
				  << BLUE << form.getName() << RESET
				  << " because "
				  << RED << e.what() << RESET
				  << std::endl;
	}
}

/*-------------------------------*/
/*  Define executeForm function  */
/*-------------------------------*/
void	Bureaucrat::executeForm( AForm const& form ) const {

	try {
		form.execute( *this );
		std::cout << YELLOW << _name << RESET
				  << GREEN << " executed " << RESET
				  << BLUE << form.getName() << RESET
				  << std::endl;
	} catch ( const std::exception &e ) {
		std::cout << YELLOW << _name << RESET
				  << PURPLE << " couldn't execute " << RESET
				  << BLUE << form.getName() << RESET
				  << " because "
				  << RED << e.what() << RESET
				  << std::endl;
	}
}

/*----------------------------------------------------*/
/*  Define overloading of the insertion («) operator  */
/*----------------------------------------------------*/
std::ostream& operator<<( std::ostream& os, const Bureaucrat& bureaucrat ) {

	os << YELLOW << bureaucrat.getName() << RESET
	   << ", bureaucrat grade "
	   << CYAN << bureaucrat.getGrade() << RESET;

	return os;
}
