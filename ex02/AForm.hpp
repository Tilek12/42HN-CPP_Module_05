/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:43:04 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/17 11:57:03 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

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

	virtual void		executeAction( void ) const = 0;

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
