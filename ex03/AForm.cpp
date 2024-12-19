/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:12:30 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/19 20:48:12 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/*--------------------------*/
/*  Form Class constructor  */
/*--------------------------*/
AForm::AForm( const std::string& name, int gradeToSign, int gradeToExecute )
	: _name( name ),
	  _isSigned( false ),
	  _gradeToSign( gradeToSign ),
	  _gradeToExecute( gradeToExecute) {

	if ( _gradeToSign < 1 || _gradeToExecute < 1 )
		throw GradeTooHighException();
	else if ( _gradeToSign > 150 || _gradeToExecute > 150 )
		throw GradeTooLowException();
}

/*-------------------------------*/
/*  Form Class copy constructor  */
/*-------------------------------*/
AForm::AForm( const AForm& other ) : _name( other._name ),
									 _isSigned( other._isSigned ),
									 _gradeToSign( other._gradeToSign),
									 _gradeToExecute( other._gradeToExecute) {}

/*---------------------------------------*/
/*  Form Class copy assignment operator  */
/*---------------------------------------*/
AForm&	AForm::operator=( const AForm& other ) {

	if ( this != &other ) {
		_isSigned = other._isSigned;
	}

	return *this;
}

/*-------------------------*/
/*  Form Class destructor  */
/*-------------------------*/
AForm::~AForm( void ) {}

/*---------------------------*/
/*  Define getName function  */
/*---------------------------*/
const std::string&	AForm::getName( void ) const { return _name; }

/*-------------------------------*/
/*  Define getIsSigned function  */
/*-------------------------------*/
bool	AForm::getIsSigned( void ) const { return _isSigned; }

/*----------------------------------*/
/*  Define getGradeToSign function  */
/*----------------------------------*/
int	AForm::getGradeToSign( void ) const { return _gradeToSign; }

/*-------------------------------------*/
/*  Define getGradeToExecute function  */
/*-------------------------------------*/
int	AForm::getGradeToExecute( void ) const { return _gradeToExecute; }

/*----------------------------*/
/*  Define beSigned function  */
/*----------------------------*/
void	AForm::beSigned( const Bureaucrat& bureaucrat ) {

	if (bureaucrat.getGrade() > _gradeToSign ) {
		throw GradeTooLowException();
	}

	_isSigned = true;
}

/*---------------------------*/
/*  Define execute function  */
/*---------------------------*/
void	AForm::execute( const Bureaucrat& executor ) const {

	if ( !_isSigned )
		throw FormNotSignedException();
	if ( executor.getGrade() > _gradeToExecute )
		throw GradeTooLowException();

	_executeAction();
}

/*----------------------------------------------------*/
/*  Define overloading of the insertion («) operator  */
/*----------------------------------------------------*/
std::ostream& operator<<( std::ostream& os, const AForm& form ) {

	os << BLUE << form.getName() << RESET
	   << " is "
	   << B_WHITE << (form.getIsSigned() ? "signed" : "NOT signed" ) << RESET
	   << ". Grade to sign: "
	   << CYAN << form.getGradeToSign() << RESET
	   << ". Grade to execute: "
	   << CYAN << form.getGradeToExecute() << RESET;

	return os;
}
