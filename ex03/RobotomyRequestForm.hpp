/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:32:22 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/18 09:20:48 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

/*------------------------------------*/
/*  Define RobotomyRequestForm class  */
/*------------------------------------*/
class	RobotomyRequestForm : public AForm {

private:

	std::string	_target;
	void		_executeAction( void ) const override;

public:
	RobotomyRequestForm( const std::string& target );
	RobotomyRequestForm( const RobotomyRequestForm& other );
	RobotomyRequestForm&	operator=( const RobotomyRequestForm& other );
	~RobotomyRequestForm();

};

#endif
