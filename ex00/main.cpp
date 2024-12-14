/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:44:51 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/14 16:50:21 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	printError( const std::exception& e ) {
	std::cerr << RED << e.what() << RESET << std::endl;
}

/*-----------------*/
/*  Main function  */
/*-----------------*/
int	main ( void ) {

	try {
		Bureaucrat	bureaucratAlice( "Alice", 5 );
		std::cout << bureaucratAlice << std::endl;

		for ( int i = 0; i < 5; i++ ) {
			bureaucratAlice.incrementGrade();
			std::cout << bureaucratAlice << std::endl;
		}
	}
	catch(const std::exception& e) { printError( e ); }

	try {
		Bureaucrat	bureaucratBob( "Bob", 151 );
	}
	catch(const std::exception& e) { printError( e ); }

	try {
		Bureaucrat	bureaucratCharlie( "Charlie", 150 );
		std::cout << bureaucratCharlie << std::endl;
		bureaucratCharlie.decrementGrade();
	}
	catch(const std::exception& e) { printError( e ); }

	return 0;
}
