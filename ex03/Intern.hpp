/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:42:06 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/19 20:05:35 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

/*-----------------------*/
/*  Define Intern class  */
/*-----------------------*/
class	Intern {

private:

	static AForm*	_createRobotomyForm( const std::string& target );
	static AForm*	_createShrubberyForm( const std::string& target );
	static AForm*	_createPresidentialForm( const std::string& target );

public:

	Intern( void );
	Intern( const Intern& other );
	Intern&	operator=( const Intern& other );
	~Intern( void );

	AForm*	makeForm( const std::string& form, const std::string& target ) const;

};

#endif
