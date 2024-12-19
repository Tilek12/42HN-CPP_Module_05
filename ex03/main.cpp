/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:44:51 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/19 20:04:56 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*-----------------*/
/*  Main function  */
/*-----------------*/
int main( void ) {

	try {
		Intern someRandomIntern;

		std::cout << B_BLACK
				  << "\n---------- Intern Creates Forms ----------\n\n"
				  << RESET;

		AForm *shrubbery = someRandomIntern.makeForm("shrubbery creation", "Home");
		AForm *robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
		AForm *pardon = someRandomIntern.makeForm("presidential pardon", "Alice");
		AForm *unknown = someRandomIntern.makeForm("unknown form", "Target");

		std::cout << B_BLACK
				  << "\n--- Bureaucrats Sign and Execute Forms ---\n\n"
				  << RESET;

		Bureaucrat highRanker("Sarah", 1);
		Bureaucrat lowRanker("Mike", 150);

		highRanker.signForm(*shrubbery);
		highRanker.executeForm(*shrubbery);

		highRanker.signForm(*robotomy);
		highRanker.executeForm(*robotomy);

		highRanker.signForm(*pardon);
		highRanker.executeForm(*pardon);

		std::cout << B_BLACK
				  << "\n------------ Low Ranker Tests ------------\n\n"
				  << RESET;

		lowRanker.signForm(*shrubbery); // Should fail
		lowRanker.executeForm(*shrubbery); // Should fail

		std::cout << B_BLACK
				  << "\n------------------------------------------\n\n"
				  << RESET;

		delete shrubbery;
		delete robotomy;
		delete pardon;
		delete unknown;

	} catch (const std::exception &e) {
		std::cerr << "Exception: "
				  << RED << e.what() << RESET << std::endl;
	}

	return 0;
}
