/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:31:41 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/07/19 18:31:41 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Intern.hpp"

static void	__test0(void)
{
	try
	{
		Intern	i;
		AForm	*f;

		f = i.makeForm("shrubbery creation", "Gandalf");
		std::cout << *f << std::endl;
		delete f;
	}
	catch (std::exception &e)
	{
		std::cerr
		<< "Error: "
		<< e.what()
		<< std::endl;
	}
}

static void	__test1(void)
{
	try
	{
		Intern	i;
		AForm	*f;

		f = i.makeForm("robotomy request", "Frodo");
		std::cout << *f << std::endl;
		delete f;
	}
	catch (std::exception &e)
	{
		std::cerr
		<< "Error: "
		<< e.what()
		<< std::endl;
	}
}

static void	__test2(void)
{
	try
	{
		Intern	i;
		AForm	*f;

		f = i.makeForm("presidential pardon", "Sauron");
		std::cout << *f << std::endl;
		delete f;
	}
	catch (std::exception &e)
	{
		std::cerr
		<< "Error: "
		<< e.what()
		<< std::endl;
	}
}

static void	__test3(void)
{
	try
	{
		Intern	i;
		AForm	*f;

		f = i.makeForm("wtf is this ??", "Gollum");
		std::cout << *f << std::endl;
		delete f;
	}
	catch (std::exception &e)
	{
		std::cerr
		<< "Error: "
		<< e.what()
		<< std::endl;
	}
}

int	main(void)
{
	std::srand(time(NULL));
	__test0();
	std::cout << "-----------------------------------------------" << std::endl;
	__test1();
	std::cout << "-----------------------------------------------" << std::endl;
	__test2();
	std::cout << "-----------------------------------------------" << std::endl;
	__test3();
	return EXIT_SUCCESS;
}
