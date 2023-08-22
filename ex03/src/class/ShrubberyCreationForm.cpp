/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:42:25 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/08/02 20:42:25 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Constructors and Destructors //

ShrubberyCreationForm::ShrubberyCreationForm(void) :
AForm("shrubbery creation", 145, 137),
_target("Default")
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
AForm("shrubbery creation", 145, 137),
_target(target)
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
AForm(src),
_target(src._target)
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm copy constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm destructor called\n";
}

// Accessors //

std::string const	&ShrubberyCreationForm::getTarget(void) const
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm getTarget member function called\n";
	return this->_target;
}

// Member functions //

void	ShrubberyCreationForm::beSigned(Bureaucrat const &b)
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm beSigned member function called\n";
	if (b.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	if (this->getIsSigned()  == true)
		throw AForm::AlreadySignedException();
	this->setSigned(true);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &b) const
{
	std::ofstream	ofs;
	std::string		filename = this->_target + "_shrubbery";

	if (DEBUG)
		std::cout << "ShrubberyCreationForm execute member function called\n";
	if (b.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	if (this->getIsSigned()  == false)
		throw AForm::NotSignedException();
	ofs.open(filename.c_str());
	ofs << " oxoxoo    ooxoo\n  ooxoxo oo  oxoxooo\n oooo xxoxoo ooo ooox\n oxo o oxoxo  xoxxoxo\n  oxo xooxoooo o ooo\n    ooooo  /o/o\n        \\  \\ /\n         |   /\n         |  |\n         | D|\n         |  |\n         |  |\n  ______/____\\____\n\n"
	<< "     ccee88oo\n  C8O8O8Q8PoOb o8oo\n dOB69QO8PdUOpugoO9bD\nCgggbU8OU qOp qOdoUOdcb\n    6OuU  /p u gcoUodpP\n      \\\\//  /douUP\n        \\\\////\n         |||/\n         |||/\n         |||||\n   .....//||||....\n \n\n"
	<< "                                    @\n                              @ @ @  @ @ @\n                            @  @/@ @ /__@\n                            @@@ @ / @/  @ @\n                           @  \\/@| @ | @\n                          @__\\@ \\ |/ \\| / @\n                             __\\|@|  ||/__/@\n                            /  \\ \\  / /__\n                           @    \\  \\/ /   @\n                                 |   |\n                                 |   |\n                                 |   |\n                                ~|   |~\n                            ~~~~       ~~~~\n                          ~~               ~~~\n \n \n"
	<< "               ,@@@@@@@,\n       ,,,.   ,@@@@@@/@@,  .oo8888o.\n    ,&/%/%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88\n   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888\n   %&&%/ %&/%/%&&@@\\ V /@@ 88\\8 /88\n   &%\\  /%&    |.|        \\ |8\n       |o|        | |         | |\n       |.|        | |         | |\n    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";
	ofs.close();
}

// Operators //

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm copy assignment operator called\n";
	if (this != &src)
	{
		this->AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm const &src)
{
	return o << src.getName() << " ShrubberyCreationForm isSigned : " << std::boolalpha
	<< src.getIsSigned() << ", ShrubberyCreationForm signGrade : " << src.getSignGrade()
	<< ", ShrubberyCreationForm execGrade : " << src.getExecGrade()
	<< ", ShrubberyCreationForm target : " << src.getTarget() << ".\n";
}
