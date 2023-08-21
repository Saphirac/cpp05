/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:25:26 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/07/21 13:25:26 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) :
_name("Default"),
_isSigned(false),
_signGrade(1),
_execGrade(1)
{
	if (DEBUG)
		std::cout << "AForm default constructor called\n";
}

AForm::AForm(AForm const &src) :
_name(src._name),
_isSigned(false),
_signGrade(src._signGrade),
_execGrade(src._execGrade)
{
	if (DEBUG)
		std::cout << "AForm copy constructor called\n";
	if (src._signGrade > 150 || src._execGrade > 150)
		throw AForm::GradeTooLowException();
	if (src._signGrade < 1 || src._execGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(std::string name, int signGrade, int execGrade) :
_name(name),
_isSigned(false),
_signGrade(signGrade),
_execGrade(execGrade)
{
	if (DEBUG)
		std::cout << "AForm constructor called\n";
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm::~AForm()
{
	if (DEBUG)
		std::cout << "AForm destructor called\n";
}

// Accessors

std::string const	&AForm::getName(void) const
{
	if (DEBUG)
		std::cout << "AForm getName member function called\n";
	return this->_name;
}

bool const	&AForm::getIsSigned(void) const
{
	if (DEBUG)
		std::cout << "AForm getIsSigned member function called\n";
	return this->_isSigned;
}

int const	&AForm::getSignGrade(void) const
{
	if (DEBUG)
		std::cout << "AForm getSignGrade member function called\n";
	return this->_signGrade;
}

int const	&AForm::getExecGrade(void) const
{
	if (DEBUG)
		std::cout << "Form getExecGrade member function called\n";
	return this->_execGrade;
}

// Exceptions

char const *AForm::GradeTooHighException::what(void) const throw()
{
	if (DEBUG)
		std::cout << "AForm GradeTooHighException thrown\n";
	return "AForm grade is too high\n";
}

char const *AForm::GradeTooLowException::what(void) const throw()
{
	if (DEBUG)
		std::cout << "AForm GradeTooLowException thrown\n";
	return "AForm grade is too low\n";
}

char const *AForm::AlreadySignedException::what(void) const throw()
{
	if (DEBUG)
		std::cout << "AForm GradeTooLowException thrown\n";
	return "AForm grade is too low\n";
}

// Operators

AForm	&AForm::operator=(AForm const &src)
{
	if (DEBUG)
		std::cout << "AForm copy assignment operator called\n";
	this->_isSigned = src._isSigned;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, AForm const &src)
{
	return o << src.getName() << " AForm isSigned : " << std::boolalpha
	<< src.getIsSigned() << ", AForm signGrade : " << src.getSignGrade()
	<< ", AForm execGrade : " << src.getExecGrade() << ".\n";
}
