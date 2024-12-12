/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:12:36 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/12 10:08:04 by tkubanyc         ###   ########.fr       */
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
		const_cast<std::string&>( _name ) = other._name;
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
std::string	Bureaucrat::getName( void ) const { return _name; }

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

/*----------------------------------------------------*/
/*  Define overloading of the insertion («) operator  */
/*----------------------------------------------------*/
std::ostream& operator<<( std::ostream& os, const Bureaucrat& bureaucrat ) {

	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
