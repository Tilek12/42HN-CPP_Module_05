/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:12:30 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/14 17:50:26 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( const std::string& name, int gradeToSign, int gradeToExecute ) : _name( name ),
																			 _isSigned( false ),
																			 _gradeToSign( gradeToSign ),
																			 _gradeToExecute( gradeToExecute) {


	if ( _gradeToSign < 1 || _gradeToExecute < 1 )
		throw GradeTooHighException();
	else if ( _gradeToSign > 150 || gradeToExecute > 150 )
		throw GradeTooLowException();
}

Form::Form( const Form& other ) : _name( other._name ),
								  _isSigned( other._isSigned ),
								  _gradeToSign( other._gradeToSign),
								  _gradeToExecute( other._gradeToExecute) {}

Form&	Form::operator=( const Form& other ) {

	if ( this != &other ) {
		_isSigned = other._isSigned;
	}

	return *this;
}

Form::~Form( void ) {}

const std::string&	Form::getName( void ) const { return _name; }

bool	Form::getIsSigned( void ) const { return _isSigned; }

int	Form::getGradeToSign( void ) const { return _gradeToSign; }

int	Form::getGradeToExecute( void ) const { return _gradeToExecute; }

void	Form::beSigned( const Bureaucrat& bureaucrat ) {

	if (bureaucrat.getGrade() > _gradeToSign ) {
		throw GradeTooLowException();
	}

	_isSigned = true;
}

std::ostream& operator<<( std::ostream& os, const Form& form ) {

	os << BLUE << form.getName() << RESET
	   << " is "
	   << B_WHITE << (form.getIsSigned() ? "signed" : "NOT signed" ) << RESET
	   << ". Grade to sign: "
	   << CYAN << form.getGradeToSign() << RESET
	   << ". Grade to execute: "
	   << CYAN << form.getGradeToExecute() << RESET;

	return os;
}

