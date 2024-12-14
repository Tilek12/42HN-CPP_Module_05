/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:51:37 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/14 16:40:24 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

/*---------------*/
/*  Text colors  */
/*---------------*/
// Colors
const std::string BLACK		= "\033[0;30m";
const std::string RED		= "\033[0;31m";
const std::string GREEN		= "\033[0;32m";
const std::string YELLOW	= "\033[0;33m";
const std::string BLUE		= "\033[0;34m";
const std::string PURPLE	= "\033[0;35m";
const std::string CYAN		= "\033[0;36m";
const std::string WHITE		= "\033[0;37m";

// Bold colors
const std::string B_BLACK	= "\033[1;30m";
const std::string B_RED		= "\033[1;31m";
const std::string B_GREEN	= "\033[1;32m";
const std::string B_YELLOW	= "\033[1;33m";
const std::string B_BLUE	= "\033[1;34m";
const std::string B_PURPLE	= "\033[1;35m";
const std::string B_CYAN	= "\033[1;36m";
const std::string B_WHITE	= "\033[1;37m";

// Reset code
const std::string RESET		= "\033[0m";

/*---------------------------*/
/*  Define Bureaucrat class  */
/*---------------------------*/
class	Bureaucrat {

private:

	const std::string	_name;
	int					_grade;


public:

	class	GradeTooHighException : public std::exception {
	public:
		const char*	what() const noexcept override {
			return "Grade is too high!";
		}
	};

	class	GradeTooLowException : public std::exception {
	public:
		const char*	what() const noexcept override {
			return "Grade is too low!";
		}
	};

	Bureaucrat( const std::string& name, int grade );
	Bureaucrat( const Bureaucrat& other );
	Bureaucrat& operator=( const Bureaucrat& other );
	~Bureaucrat( void );

	std::string	getName( void ) const;
	int			getGrade( void ) const;
	void		incrementGrade( void );
	void		decrementGrade( void );

};

/*------------------------------------------*/
/*  Overload of the insertion («) operator  */
/*------------------------------------------*/
std::ostream& operator<<( std::ostream& os, const Bureaucrat& bureaucrat );

#endif
