/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:43:04 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/12 15:09:36 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class	Form {

private:

	const std::string	_name;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	bool				_isSigned;


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

	std::string	getName( void ) const;
	int			getGrade( void ) const;
	int			getGrateToSign( void ) const;
	int			getGrateToExecute( void ) const;

	void	BeSigned( const Bureaucrat& bureaucrat );

};

std::ostream& operator<<( std::ostream& os, const Form& form );

#endif
