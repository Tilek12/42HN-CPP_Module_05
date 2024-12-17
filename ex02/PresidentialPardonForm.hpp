/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:53:49 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/12/17 16:00:40 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class	PresidentialPardonForm : public AForm {

private:

	std::string	_target;
	void		_executeAction( void ) const override;

public:

	PresidentialPardonForm( const std::string& target );
	PresidentialPardonForm( const PresidentialPardonForm& other );
	PresidentialPardonForm&	operator=( const PresidentialPardonForm& other );
	~PresidentialPardonForm( void );

};

#endif
