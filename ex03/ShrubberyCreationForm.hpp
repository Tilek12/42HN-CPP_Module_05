/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:06:22 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/18 09:23:11 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

/*--------------------------------------*/
/*  Define ShrubberyCreationForm class  */
/*--------------------------------------*/
class	ShrubberyCreationForm : public AForm {

private:

	std::string	_target;
	void		_executeAction( void ) const override;

public:

	ShrubberyCreationForm( const std::string& target );
	ShrubberyCreationForm( const ShrubberyCreationForm& other );
	ShrubberyCreationForm&	operator=( const ShrubberyCreationForm& other );
	~ShrubberyCreationForm( void );

};

#endif
