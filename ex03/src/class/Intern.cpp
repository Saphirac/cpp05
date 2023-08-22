/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:31:30 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/08/22 20:07:57 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Constructors and destructor //

Intern::Intern(void)
{
	if (DEBUG)
		std::cout << "Intern default constructor called.\n";
}

Intern::Intern(Intern const &src __attribute__((unused)))
{
	if (DEBUG)
		std::cout << "Intern copy constructor called.\n";
}

Intern::~Intern(void)
{
	if (DEBUG)
		std::cout << "Intern destructor called.\n";
}

// Exception //

char const	*Intern::UnknownFormException::what(void) const throw()
{
	if (DEBUG)
		std::cout << "Intern UnknowFormException thrown\n";
	return "Unknown form name\n";
}

// Mandatory functions //

AForm	*Intern::makeForm(std::string const &name, std::string const &target) const
{
	if (DEBUG)
		std::cout << "Intern makeForm member function called\n";
	for (int i = 0; _lookupTable[i].maker; i++)
		if (!name.compare(_lookupTable[i].name))
			return (_lookupTable[i].maker(target));
	throw Intern::UnknownFormException();
}

AForm	*Intern::makeShrubberyCreationForm(std::string const &target)
{
	if (DEBUG)
		std::cout << "Intern makeShrubberyCreationForm member function called\n";
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::makeRobotomyRequestForm(std::string const &target)
{
	if (DEBUG)
		std::cout << "Intern makeRobotomyRequestForm member function called\n";
	return new RobotomyRequestForm(target);
}

AForm	*Intern::makePresidentialPardonForm(std::string const &target)
{
	if (DEBUG)
		std::cout << "Intern makePresidentialPardonForm member function called\n";
	return new PresidentialPardonForm(target);
}

// Operator //
Intern	&Intern::operator=(Intern const &src __attribute__((unused)))
{
	if (DEBUG)
		std::cout << "Intern copy operator called\n";
	return *this;
}

// Lookup table //

t_makeForm	Intern::_lookupTable[] = {
	{std::string("shrubbery creation"), Intern::makeShrubberyCreationForm},
	{std::string("robotomy request"), Intern::makeRobotomyRequestForm},
	{std::string("presidential pardon"), Intern::makePresidentialPardonForm},
	{std::string(""), NULL}
};
