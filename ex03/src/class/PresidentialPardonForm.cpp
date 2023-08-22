/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:45:45 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/08/22 18:17:24 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructors and Destructors //

PresidentialPardonForm::PresidentialPardonForm(void) :
AForm("presidential pardon", 25, 5),
_target("Default")
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
AForm("presidential pardon", 25, 5),
_target(target)
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
AForm(src),
_target(src._target)
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm copy constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm destructor called\n";
}

// Accessors //

std::string const	&PresidentialPardonForm::getTarget(void) const
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm getTarget member function called\n";
	return this->_target;
}

// Member functions //

void	PresidentialPardonForm::beSigned(Bureaucrat const &b)
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm beSigned member function called\n";
	if (b.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	if (this->getIsSigned() == true)
		throw AForm::AlreadySignedException();
	this->setSigned(true);
}

void	PresidentialPardonForm::execute(Bureaucrat const &b) const
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm execute member function called\n";
	if (b.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	if (this->getIsSigned() == false)
		throw AForm::NotSignedException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox.\n";
}

// Operators //

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm copy assignment operator called\n";
	if (this != &src)
	{
		this->AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm const &src)
{
	return o << src.getName() << " PresidentialPardonForm isSigned : " << std::boolalpha
	<< src.getIsSigned() << ", PresidentialPardonForm signGrade : " << src.getSignGrade()
	<< ", PresidentialPardonForm execGrade : " << src.getExecGrade()
	<< ", PresidentialPardonForm target : " << src.getTarget() << ".\n";
}
