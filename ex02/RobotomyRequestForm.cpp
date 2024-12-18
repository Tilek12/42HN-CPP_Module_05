/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:38:28 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/18 08:58:52 by tkubanyc         ###   ########.fr       */
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

	std::cout << B_BLUE << "* Drilling noises *\n" << RESET;

	if ( rand() % 2 )
		std::cout << BLUE << _target << RESET
				  << GREEN << " has been robotomized successfully!\n" << RESET;
	else
		std::cout << PURPLE << "Robotomy failed for " << RESET
				  << BLUE << _target << RESET << std::endl;
}
