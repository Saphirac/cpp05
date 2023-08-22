/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:26:05 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/08/02 20:26:05 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
private :

	std::string	_target;

public :

	RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	RobotomyRequestForm(std::string const &target);
	virtual	~RobotomyRequestForm(void);

	std::string	const	&getTarget(void) const;

	virtual void	beSigned(Bureaucrat const &b);
	virtual void	execute(Bureaucrat const &b) const;

	RobotomyRequestForm	&operator=(RobotomyRequestForm const &src);
};

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm const &src);

#endif
