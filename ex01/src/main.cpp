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
#include "Bureaucrat.hpp"

static void	__test0(void)
{
	try
	{
		Form	f("ation", 50, 25);

		std::cout << f << std::endl;
	}
	catch (std::exception const &e)
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
		Form	f("alin", 256, 42);

		std::cout << f << std::endl;
	}
	catch (std::exception const &e)
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
		Form	f("ulaire", 21, 0);

		std::cout << f << std::endl;
	}
	catch (std::exception const &e)
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
		Bureaucrat	b("Charlie", 42);
		Form		f("at", 42, 21);

		std::cout << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(f);
	}
	catch (std::exception const &e)
	{
		std::cerr
		<< "Error: "
		<< e.what()
		<< std::endl;
	}
}

static void	__test4(void)
{
	try
	{
		Bureaucrat	b("Ben", 55);
		Form		f("ula 1", 54, 21);

		std::cout << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(f);
	}
	catch (std::exception const &e)
	{
		std::cerr
		<< "Error: "
		<< e.what()
		<< std::endl;
	}
}

static void	__test5(void)
{
	try
	{
		Bureaucrat	b("Melissa", 1);
		Form		f("idable", 42, 24);

		std::cout << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(f);
	}
	catch (std::exception const &e)
	{
		std::cerr
		<< "Error: "
		<< e.what()
		<< std::endl;
	}
}

int	main(void)
{
	__test0();
	std::cout << "-----------------------------------------------" << std::endl;
	__test1();
	std::cout << "-----------------------------------------------" << std::endl;
	__test2();
	std::cout << "-----------------------------------------------" << std::endl;
	__test3();
	std::cout << "-----------------------------------------------" << std::endl;
	__test4();
	std::cout << "-----------------------------------------------" << std::endl;
	__test5();
	return EXIT_SUCCESS;
}
