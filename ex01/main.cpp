/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:44:51 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/14 16:05:55 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/*-----------------*/
/*  Main function  */
/*-----------------*/
int	main ( void ) {

	try
	{
		Bureaucrat	bureaucratAlice( "Alice", 50 );
		Form form( "Form", 40, 30 );

		std::cout << bureaucratAlice << std::endl;
		std::cout << form << std::endl;

		bureaucratAlice.signForm( form );

		Bureaucrat	bureaucratBob( "Bob", 30 );
		bureaucratBob.signForm( form );

		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
