/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:44:51 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/12 10:01:39 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*-----------------*/
/*  Main function  */
/*-----------------*/
int	main ( void ) {

	try
	{
		Bureaucrat	bureaucrat( "Alice", 5 );
		std::cout << bureaucrat << std::endl;

		for ( int i = 0; i < 5; i++ ) {
			bureaucrat.incrementGrade();
			std::cout << bureaucrat << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	bureaucrat( "Bob", 151 );
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	bureaucrat( "Charlie", 150 );
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
