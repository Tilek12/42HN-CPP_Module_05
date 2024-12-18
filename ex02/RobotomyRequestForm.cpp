/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:38:28 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/18 09:22:32 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*-----------------------------------------*/
/*  RobotomyRequestForm Class constructor  */
/*-----------------------------------------*/
RobotomyRequestForm::RobotomyRequestForm( const std::string& target )
	: AForm( "RobotomyRequestForm", 72, 45 ),
	  _target( target ) {}

/*----------------------------------------------*/
/*  RobotomyRequestForm Class copy constructor  */
/*----------------------------------------------*/
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other )
	: AForm( other ),
	  _target( other._target ) {}

/*------------------------------------------------------*/
/*  RobotomyRequestForm Class copy assignment operator  */
/*------------------------------------------------------*/
RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm& other ) {

	if ( this != &other ) {
		AForm::operator=( other );
		_target = other._target;
	}

	return *this;
}

/*----------------------------------------*/
/*  RobotomyRequestForm Class destructor  */
/*----------------------------------------*/
RobotomyRequestForm::~RobotomyRequestForm( void ) {}

/*----------------------------------*/
/*  Define _executeAction function  */
/*----------------------------------*/
void	RobotomyRequestForm::_executeAction( void ) const {

	std::cout << B_BLUE << "* Drilling noises *\n" << RESET;

	if ( rand() % 2 )
		std::cout << BLUE << _target << RESET
				  << GREEN << " has been robotomized successfully!\n" << RESET;
	else
		std::cout << PURPLE << "Robotomy failed for " << RESET
				  << BLUE << _target << RESET << std::endl;
}
