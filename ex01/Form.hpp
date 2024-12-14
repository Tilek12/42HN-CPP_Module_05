/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:43:04 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/14 17:02:35 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <stdexcept>

class Bureaucrat;

class	Form {

private:

	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

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

	Form( const std::string& name, int gradeToSign, int gradeToExecute );
	Form( const Form& other );
	Form&	operator=( const Form& other );
	~Form( void );

	const std::string&	getName( void ) const;
	bool				getIsSigned( void ) const;
	int					getGradeToSign( void ) const;
	int					getGradeToExecute( void ) const;

	void				beSigned( const Bureaucrat& bureaucrat );

};

std::ostream& operator<<( std::ostream& os, const Form& form );

#endif
