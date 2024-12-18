/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:02:07 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/18 09:19:48 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*--------------------------------------------*/
/*  PresidentialPardonForm Class constructor  */
/*--------------------------------------------*/
PresidentialPardonForm::PresidentialPardonForm( const std::string& target )
	: AForm( "PresidentialPardonForm", 25, 5 ),
	  _target( target ) {}

/*-------------------------------------------------*/
/*  PresidentialPardonForm Class copy constructor  */
/*-------------------------------------------------*/
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other )
	: AForm( other ),
	  _target( other._target ) {}

/*---------------------------------------------------------*/
/*  PresidentialPardonForm Class copy assignment operator  */
/*---------------------------------------------------------*/
PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm& other ) {

	if ( this != &other ) {
		AForm::operator=( other );
		_target = other._target;
	}

	return *this;
}

/*-------------------------------------------*/
/*  PresidentialPardonForm Class destructor  */
/*-------------------------------------------*/
PresidentialPardonForm::~PresidentialPardonForm( void ) {}

/*----------------------------------*/
/*  Define _executeAction function  */
/*----------------------------------*/
void	PresidentialPardonForm::_executeAction( void ) const {
	std::cout << BLUE << _target << RESET
			  << " has been pardoned by Zaphod Beeblebrox.\n";
}
