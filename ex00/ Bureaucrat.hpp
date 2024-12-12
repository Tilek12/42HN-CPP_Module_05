/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Bureaucrat.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:51:37 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/12 09:10:31 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>

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

std::ostream& operator<<( std::ostream& os, const Bureaucrat& bureaucrat );

#endif