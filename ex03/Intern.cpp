/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:20:33 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/19 14:29:51 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {}

Intern::Intern( const Intern& other ) { (void)other; }

Intern&	Intern::operator=( const Intern& other ) {

	(void)other;
	return *this;
}

Intern::~Intern( void ) {}

AForm*	Intern::_createRobotomyForm( const std::string& target ) {
	return new RobotomyRequestForm( target );
}

AForm*	Intern::_createShrubberyForm( const std::string& target ) {
	return new ShrubberyCreationForm( target );
}

AForm*	Intern::_createPresidentialForm( const std::string& target ) {
	return new PresidentialPardonForm( target );
}

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
