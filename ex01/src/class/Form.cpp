/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:25:26 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/07/21 13:25:26 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) :
_name("Default"),
_isSigned(false),
_signGrade(1),
_execGrade(1)
{
	if (DEBUG)
		std::cout << "Form default constructor called\n";
}

Form::Form(Form const &src) :
_name(src._name),
_isSigned(false),
_signGrade(src._signGrade),
_execGrade(src._execGrade)
{
	if (DEBUG)
		std::cout << "Form copy constructor called\n";
	if (src._signGrade > 150 || src._execGrade > 150)
		throw Form::GradeTooLowException();
	if (src._signGrade < 1 || src._execGrade < 1)
		throw Form::GradeTooHighException();
}

Form::Form(std::string name, int signGrade, int execGrade) :
_name(name),
_isSigned(false),
_signGrade(signGrade),
_execGrade(execGrade)
{
	if (DEBUG)
		std::cout << "Form constructor called\n";
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
}

Form::~Form()
{
	if (DEBUG)
		std::cout << "Form destructor called\n";
}

// Accessors

std::string const	&Form::getName(void) const
{
	if (DEBUG)
		std::cout << "Form getName member function called\n";
	return this->_name;
}

bool const	&Form::getIsSigned(void) const
{
	if (DEBUG)
		std::cout << "Form getIsSigned member function called\n";
	return this->_isSigned;
}

int const	&Form::getSignGrade(void) const
{
	if (DEBUG)
		std::cout << "Form getSignGrade member function called\n";
	return this->_signGrade;
}

int const	&Form::getExecGrade(void) const
{
	if (DEBUG)
		std::cout << "Form getExecGrade member function called\n";
	return this->_execGrade;
}

// Mandatory function

void	Form::beSigned(Bureaucrat const &b)
{
	if (DEBUG)
		std::cout << "Form beSigned member function called\n";
	if (b.getGrade() >= this->_signGrade)
		throw Form::GradeTooLowException();
	if (this->_isSigned == false)
		this->_isSigned = true;
	else
		throw Form::AlreadySignedException();
}

// Exceptions

char const *Form::GradeTooHighException::what(void) const throw()
{
	if (DEBUG)
		std::cout << "Form GradeTooHighException thrown\n";
	return "Form grade is too high\n";
}

char const *Form::GradeTooLowException::what(void) const throw()
{
	if (DEBUG)
		std::cout << "Form GradeTooLowException thrown\n";
	return "Form grade is too low\n";
}

char const *Form::AlreadySignedException::what(void) const throw()
{
	if (DEBUG)
		std::cout << "Form GradeTooLowException thrown\n";
	return "Form grade is too low\n";
}

// Operators

Form	&Form::operator=(Form const &src)
{
	if (DEBUG)
		std::cout << "Form copy assignment operator called\n";
	this->_isSigned = src._isSigned;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Form const &src)
{
	return o << src.getName() << " form isSigned : " << std::boolalpha
	<< src.getIsSigned() << ", Form signGrade : " << src.getSignGrade()
	<< ", Form execGrade : " << src.getExecGrade() << ", ";
}
