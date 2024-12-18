/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:13:06 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/18 08:15:46 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target )
	: AForm( "ShrubberyCreationForm", 145, 137 ),
	  _target( target ) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other )
	: AForm( other ),
	  _target( other._target ) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other ) {

	if ( this != &other ) {
		AForm::operator=( other );
		_target = other._target;
	}

	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

void	ShrubberyCreationForm::_executeAction( void ) const {

	std::ofstream	file( _target + "_shrubbery");
	if ( !file )
		throw std::ios_base::failure( "Failed to open file" );

	file << "             /\\\n"
		 << "            <  >\n"
		 << "             \\/\n"
		 << "             /\\\n"
		 << "            /  \\\n"
		 << "           /++++\\\n"
		 << "          /  ()  \\\n"
		 << "          /      \\\n"
		 << "         /~`~`~`~`\\\n"
		 << "        /  ()  ()  \\\n"
		 << "        /          \\\n"
		 << "       /*&*&*&*&*&*&\\\n"
		 << "      /  ()  ()  ()  \\\n"
		 << "      /              \\\n"
		 << "     /++++++++++++++++\\\n"
		 << "    /  ()  ()  ()  ()  \\\n"
		 << "    /                  \\\n"
		 << "   /~`~`~`~`~`~`~`~`~`~`\\\n"
		 << "  /  ()  ()  ()  ()  ()  \\\n"
		 << "  /*&*&*&*&*&*&*&*&*&*&*&\\\n"
		 << " /                        \\\n"
		 << "/,.,.,.,.,.,.,.,.,.,.,.,.,.\\\n"
		 << "           |   |\n"
		 << "          |`````|\n"
		 << "          \\_____/\n";

	file.close();
}
