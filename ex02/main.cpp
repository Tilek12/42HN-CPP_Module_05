/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:44:51 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/14 17:54:28 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/*-----------------------*/
/*  Print Error message  */
/*-----------------------*/
void	printError( const std::exception& e ) {
	std::cerr << RED << e.what() << RESET << std::endl;
}

/*-----------------*/
/*  Main function  */
/*-----------------*/
int	main ( void ) {

	// Normal case: Bureaucrat with sufficient grade signs the form
	try {
		std::cout << B_BLACK
				  << "\n----------------- Test 1: Normal signing -----------------\n\n"
				  << RESET;

		Bureaucrat alice( "Alice", 10 );
		Form formA( "FormA", 40, 30 );

		std::cout << alice << std::endl;
		std::cout << formA << std::endl;

		alice.signForm(formA);
		std::cout << formA << std::endl;
	} catch (const std::exception& e) { printError( e ); }

	// Edge case: Bureaucrat's grade is too low to sign
	try {
		std::cout << B_BLACK
				  << "\n----------- Test 2: Insufficient grade to sign -----------\n\n"
				  << RESET;

		Bureaucrat bob("Bob", 100);
		Form formB("FormB", 50, 40);

		std::cout << bob << std::endl;
		std::cout << formB << std::endl;

		bob.signForm(formB);
		std::cout << formB << std::endl;
	} catch (const std::exception& e) { printError( e ); }

	// Case: Form is already signed
	try {
		std::cout << B_BLACK
				  << "\n--------------- Test 3: Form already signed --------------\n\n"
				  << RESET;

		Bureaucrat charlie("Charlie", 20);
		Form formC("FormC", 30, 20);

		std::cout << charlie << std::endl;
		std::cout << formC << std::endl;

		charlie.signForm(formC); // First signing attempt
		std::cout << formC << std::endl;
		charlie.signForm(formC); // Attempting to sign again
	} catch (const std::exception& e) { printError( e ); }

	// Edge case: Invalid grade for form creation (too high)
	try {
		std::cout << B_BLACK
				  << "\n--- Test 4: Invalid grade for form creation (too high) ---\n\n"
				  << RESET;

		Form formD("FormD", 0, 50); // Invalid grade
		std::cout << formD << std::endl;
	} catch (const std::exception& e) { printError( e ); }

	// Edge case: Invalid grade for form creation (too low)
	try {
		std::cout << B_BLACK
				  << "\n---- Test 5: Invalid grade for form creation (too low) ---\n\n"
				  << RESET;

		Form formE("FormE", 160, 150); // Invalid grade
		std::cout << formE << std::endl;
	} catch (const std::exception& e) { printError( e ); }

	// Case: Bureaucrat with the highest grade signs the form
	try {
		std::cout << B_BLACK
				  << "\n--------- Test 6: Bureaucrat with highest grade ----------\n\n"
				  << RESET;

		Bureaucrat diana("Diana", 1);
		Form formF("FormF", 1, 1);

		std::cout << diana << std::endl;
		std::cout << formF << std::endl;

		diana.signForm(formF);
		std::cout << formF << std::endl;
	} catch (const std::exception& e) { printError( e ); }

	// Case: Bureaucrat with the lowest grade attempts to sign
	try {
		std::cout << B_BLACK
				  << "\n---------- Test 7: Bureaucrat with lowest grade ----------\n\n"
				  << RESET;

		Bureaucrat edward("Edward", 150);
		Form formG("FormG", 150, 150);

		std::cout << edward << std::endl;
		std::cout << formG << std::endl;

		edward.signForm(formG);
		std::cout << formG << std::endl;
	} catch (const std::exception& e) { printError( e ); }

	std::cout << B_BLACK
			  << "\n----------------------------------------------------------\n\n"
			  << RESET;

	return 0;
}
