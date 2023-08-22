/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:05:30 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/08/22 20:06:59 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"

typedef struct s_makeForm	t_makeForm;
typedef AForm *			(*t_fct)(std::string const &target);


struct s_makeForm
{
	std::string const	name;
	t_fct const			maker;
};

class	AForm;

class	Intern
{
private:

	static t_makeForm	_lookupTable[];

	class UnknownFormException : public std::exception
	{
	private:
		virtual char const	*what(void) const throw();
	};

	static AForm	*makeShrubberyCreationForm(std::string const &target);
	static AForm	*makeRobotomyRequestForm(std::string const &target);
	static AForm	*makePresidentialPardonForm(std::string const &target);

public:

	Intern(void);
	Intern(Intern const &src);
	virtual ~Intern(void);

	AForm	*makeForm(std::string const &name, std::string const &target) const;

	Intern	&operator=(Intern const &rhs);
};

#endif
