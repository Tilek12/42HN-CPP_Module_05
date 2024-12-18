/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:43:04 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/18 07:30:17 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

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

/*----------------------------*/
/*  Include Bureaucrat class  */
/*----------------------------*/
class Bureaucrat;

/*---------------------*/
/*  Define Form class  */
/*---------------------*/
class	AForm {

private:

	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

protected:

	virtual void		_executeAction( void ) const = 0;

public:

	class	GradeTooHighException : public std::exception {
		const char*	what() const noexcept override {
			return "Grade is too high!";
		}
	};

	class	GradeTooLowException : public std::exception {
		const char*	what() const noexcept override {
			return "Grade is too low!";
		}
	};

	class	FormNotSignedException : public std::exception {
		const char* what() const noexcept override {
			return "Form is not signed!";
		}
	};

	AForm( const std::string& name, int gradeToSign, int gradeToExecute );
	AForm( const AForm& other );
	AForm&	operator=( const AForm& other );
	~AForm( void );

	const std::string&	getName( void ) const;
	bool				getIsSigned( void ) const;
	int					getGradeToSign( void ) const;
	int					getGradeToExecute( void ) const;

	void				beSigned( const Bureaucrat& bureaucrat );
	void				execute( const Bureaucrat& executor ) const;

};

/*------------------------------------------*/
/*  Overload of the insertion («) operator  */
/*------------------------------------------*/
std::ostream& operator<<( std::ostream& os, const AForm& form );

#endif
