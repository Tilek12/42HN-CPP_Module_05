/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:02:07 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/17 16:07:43 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string& target )
	: AForm( "PresidentialPardonForm", 25, 5 ),
	  _target( target ) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other )
	: AForm( other ),
	  _target( other._target ) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm& other ) {

	if ( this != &other ) {
		AForm::operator=( other );
		_target = other._target;
	}

	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

void	PresidentialPardonForm::_executeAction( void ) const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}
