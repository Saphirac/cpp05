/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:26:05 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/08/02 20:26:05 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
private :

	std::string	_target;

public :

	ShrubberyCreationForm(void);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	ShrubberyCreationForm(std::string const &target);
	virtual	~ShrubberyCreationForm(void);

	std::string const	&getTarget(void) const;

	virtual void	beSigned(Bureaucrat const &b);
	virtual void	beExecuted(Bureaucrat const &b);

	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &src);
};

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm const &src);

#endif
