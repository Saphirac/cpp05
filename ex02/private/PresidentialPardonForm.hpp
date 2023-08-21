/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:26:05 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/08/02 20:26:05 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
private :

	std::string	_target;

public :

	PresidentialPardonForm(void);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	PresidentialPardonForm(std::string const &target);
	virtual	~PresidentialPardonForm(void);

	std::string	const	&getTarget(void) const;

	virtual void	beSigned(Bureaucrat const &b);
	virtual void	beExecuted(Bureaucrat const &b);

	PresidentialPardonForm	&operator=(PresidentialPardonForm const &src);
};

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm const &src);

#endif
