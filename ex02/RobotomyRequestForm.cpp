/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:38:28 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/17 15:50:13 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string& target )
	: AForm( "RobotomyRequestForm", 72, 45 ),
	  _target( target ) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other )
	: AForm( other ),
	  _target( other._target ) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm& other ) {

	if ( this != &other ) {
		AForm::operator=( other );
		_target = other._target;
	}

	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

void	RobotomyRequestForm::_executeAction( void ) const {

	std::cout << "* Drilling noses *\n";

	if ( rand() % 2 )
		std::cout << _target << " has been robotomized successfully!\n";
	else
		std::cout << "Robotomy failed for " << _target << std::endl;
}
