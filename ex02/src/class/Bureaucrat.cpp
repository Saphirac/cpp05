/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:32:46 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/07/19 18:32:46 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) :
_name("Default"),
_grade(42)
{
	if (DEBUG)
		std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) :
_name(name)
{
	if (DEBUG)
		std::cout << "Bureaucrat constructor called\n";
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) :
_name(src._name)
{
	if (DEBUG)
		std::cout << "Bureaucrat copy constructor called\n";
	if (src._grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (src._grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = src._grade;
}

Bureaucrat::~Bureaucrat()
{
	if (DEBUG)
		std::cout << "Bureaucrat destructor called\n";
}

// Accessors

std::string const	Bureaucrat::getName(void) const
{
	if (DEBUG)
		std::cout << "Bureaucrat getName member function called\n";
	return this->_name;
}

int	Bureaucrat::getGrade(void) const
{
	if (DEBUG)
		std::cout << "Bureaucrat getGrade member function called\n";
	return this->_grade;
}

// Mandatory functions

void	Bureaucrat::incrementeGrade(void)
{
	if (DEBUG)
		std::cout << "Bureaucrat incrementeGrade member function called\n";
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	--this->_grade;
}

void	Bureaucrat::decrementeGrade(void)
{
	if (DEBUG)
		std::cout << "Bureaucrat incrementeGrade member function called\n";
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	++this->_grade;
}


/**
 * @brief signForm can throw the TooLowException of beSigned.
 * 
 * @param toSign 
 */
void	Bureaucrat::signForm(Form &toSign)
{
	if (DEBUG)
		std::cout << "Bureaucrat signForm member function called\n";
	if (toSign.getIsSigned() == true)
	{
		std::cout << this->_name << " couldn't sign " << toSign.getName()
		<< "because form is already signed.\n";
	}
	toSign.beSigned(*this);
	if (toSign.getIsSigned() == true)
		std::cout << this->_name << " signed " << toSign.getName() << ".\n";
	else if (this->_grade > toSign.getSignGrade())
	{
		std::cout << this->_name << " couldn't sign " << toSign.getName()
		<< "because grade is insuffisant.\n";
	}
}

// Exceptions

char const *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	if (DEBUG)
		std::cout << "Bureaucrat GradeTooHighException thrown\n";
	return "Bureaucrat grade is too high\n";
}

char const *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	if (DEBUG)
		std::cout << "Bureaucrat GradeTooLowException thrown\n";
	return "bureaucrat grade is too low\n";
}

// Operators

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &src)
{
	if (DEBUG)
		std::cout << "Bureaucrat copy assignment operator called\n";
	if (src._grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (src._grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = src._grade;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &src)
{
	return o << src.getName() << " bureaucrat grade " << src.getGrade() << ".\n";
}
