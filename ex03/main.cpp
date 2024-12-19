/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:44:51 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/19 14:24:35 by tkubanyc         ###   ########.fr       */
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
// int main() {

// 	try {
// 		std::cout << B_BLACK
// 				  << "\n-------- Bureaucrat Creation Tests --------\n\n"
// 				  << RESET;

// 		Bureaucrat john("John", 50);
// 		Bureaucrat sarah("Sarah", 1);  // Highest grade
// 		Bureaucrat mike("Mike", 150); // Lowest grade
// 		std::cout << john << std::endl;
// 		std::cout << sarah << std::endl;
// 		std::cout << mike << std::endl;

// 		std::cout << B_BLACK
// 				  << "\n------- ShrubberyCreationForm Tests -------\n\n"
// 				  << RESET;

// 		ShrubberyCreationForm shrubbery("ChristmasTree");
// 		std::cout << shrubbery << std::endl;

// 		john.signForm(shrubbery); // Should succeed
// 		std::cout << shrubbery << std::endl;
// 		mike.executeForm(shrubbery); // Should fail (low grade)
// 		john.executeForm(shrubbery); // Should succeed

// 		std::cout << B_BLACK
// 				  << "\n-------- RobotomyRequestForm Tests --------\n\n"
// 				  << RESET;

// 		RobotomyRequestForm robotomy("Robot");
// 		std::cout << robotomy << std::endl;

// 		john.signForm(robotomy);  // Should succeed
// 		std::cout << robotomy << std::endl;
// 		sarah.signForm(robotomy); // Should fail (already signed)
// 		john.executeForm(robotomy); // Should fail (low grade)
// 		sarah.executeForm(robotomy); // Should succeed (50% chance of success)

// 		std::cout << B_BLACK
// 				  << "\n------- PresidentialPardonForm Tests ------\n\n"
// 				  << RESET;

// 		PresidentialPardonForm pardon("Alice");
// 		std::cout << pardon << std::endl;

// 		sarah.signForm(pardon);  // Should succeed
// 		std::cout << pardon << std::endl;
// 		john.executeForm(pardon); // Should fail (low grade)
// 		sarah.executeForm(pardon); // Should succeed

// 		std::cout << B_BLACK
// 				  << "\n--------------------------------------------\n\n"
// 				  << RESET;

// 	} catch (const std::exception &e) {
// 		std::cerr << "Exception in main: "
// 				  << RED << e.what() << RESET << std::endl;
// 	}

// 	return 0;
// }


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
