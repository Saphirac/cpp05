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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void	__test0(void)
{
	try
	{
		Bureaucrat				b("Delphine", 137);
		ShrubberyCreationForm	f("FoodTruck");

		std::cout << b << std::endl;
		std::cout << f << std::endl;

		b.signForm(f);
		b.executeForm(f);
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
		Bureaucrat			b("Melissa", 1);
		RobotomyRequestForm	f("Hoodie");

		std::cout << b << std::endl;
		std::cout << f << std::endl;

		b.signForm(f);
		b.executeForm(f);
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
		Bureaucrat				b("Bibiche", 2);
		PresidentialPardonForm	f("Reach");

		std::cout << b << std::endl;
		std::cout << f << std::endl;

		b.signForm(f);
		b.executeForm(f);
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
	std::srand(time(NULL));
	__test0();
	std::cout << "-----------------------------------------------" << std::endl;
	__test1();
	std::cout << "-----------------------------------------------" << std::endl;
	__test2();
	return EXIT_SUCCESS;
}
