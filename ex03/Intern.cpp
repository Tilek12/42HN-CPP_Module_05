/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:20:33 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/18 14:27:39 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {}

Intern::Intern( const Intern& other ) {}

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

}
