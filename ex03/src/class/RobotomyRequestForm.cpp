/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:28:09 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/08/16 12:28:09 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

// Constructors and Destructors //

RobotomyRequestForm::RobotomyRequestForm(void) :
AForm("robotomy request", 72, 45),
_target("Default")
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
AForm("robotomy request", 72, 45),
_target(target)
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
AForm(src),
_target(src._target)
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm copy constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm destructor called\n";
}

// Accessors //

std::string const	&RobotomyRequestForm::getTarget(void) const
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm getTarget member function called\n";
	return this->_target;
}

// Member functions //

void	RobotomyRequestForm::beSigned(Bureaucrat const &b)
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm beSigned member function called\n";
	if (b.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	if (this->getIsSigned()  == true)
		throw AForm::AlreadySignedException();
	this->setSigned(true);
}

void	RobotomyRequestForm::execute(Bureaucrat const &b) const
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm execute member function called\n";
	if (b.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	if (this->getIsSigned() == false)
		throw AForm::NotSignedException();
	std::cout << "* drilling noises * \n";
	if (std::rand() % 2)
		std::cout << "Successful robotomy on : " << this->_target << "!!!\n";
	else
		std::cout << "Failed robotomy on : " << this->_target << " :(\n";	
}

// Operators //

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm copy assignment operator called\n";
	if (this != &src)
	{
		this->AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm const &src)
{
	return o << src.getName() << " RobotomyRequestForm isSigned : " << std::boolalpha
	<< src.getIsSigned() << ", RobotomyRequestForm signGrade : " << src.getSignGrade()
	<< ", RobotomyRequestForm execGrade : " << src.getExecGrade()
	<< ", RobotomyRequestForm target : " << src.getTarget() << ".\n";
}
