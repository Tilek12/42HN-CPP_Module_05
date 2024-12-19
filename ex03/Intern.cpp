/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:20:33 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/19 20:15:28 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*----------------------------*/
/*  Intern Class constructor  */
/*----------------------------*/
Intern::Intern( void ) {}

/*---------------------------------*/
/*  Intern Class copy constructor  */
/*---------------------------------*/
Intern::Intern( const Intern& other ) { (void)other; }

/*----------------------------------------*/
/*  Intern Class copy assignment operator */
/*----------------------------------------*/
Intern&	Intern::operator=( const Intern& other ) {

	(void)other;
	return *this;
}

/*---------------------------*/
/*  Intern Class destructor  */
/*---------------------------*/
Intern::~Intern( void ) {}

/*---------------------------------------*/
/*  Define _createRobotomyForm function  */
/*---------------------------------------*/
AForm*	Intern::_createRobotomyForm( const std::string& target ) {
	return new RobotomyRequestForm( target );
}

/*----------------------------------------*/
/*  Define _createShrubberyForm function  */
/*----------------------------------------*/
AForm*	Intern::_createShrubberyForm( const std::string& target ) {
	return new ShrubberyCreationForm( target );
}

/*-------------------------------------------*/
/*  Define _createPresidentialForm function  */
/*-------------------------------------------*/
AForm*	Intern::_createPresidentialForm( const std::string& target ) {
	return new PresidentialPardonForm( target );
}

/*----------------------------*/
/*  Define makeForm function  */
/*----------------------------*/
AForm*	Intern::makeForm( const std::string& form, const std::string& target ) const {

	const std::string	formTypes[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm*	( *formCreators[3] )( const std::string& ) = {
		&Intern::_createShrubberyForm,
		&Intern::_createRobotomyForm,
		&Intern::_createPresidentialForm
	};

	for ( int i = 0; i < 3; i++ ) {
		if ( form == formTypes[i]) {
			std::cout << YELLOW << "Intern" << RESET
					  << " creates "
					  << BLUE << form << " form.\n" << RESET;
			return formCreators[i]( target );
		}
	}

	std::cout << RED << "Incorrect form.\n" << RESET;
	return nullptr;
}
