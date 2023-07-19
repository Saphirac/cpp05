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

#include "Bureaucrat.hpp"

int	main()
{
	try 
	{
		Bureaucrat	Jojo("Jojo", 42);
		Bureaucrat	Boss("Boss", 1);
		Bureaucrat	Nullos("Nullos", 150);

		std::cout << Jojo;
		std::cout << Boss;
		std::cout << Nullos;

		try
		{
			Nullos.decrementeGrade();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what();
		}
		std::cout << Nullos;
		try
		{
			Boss.incrementeGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what();	
		}
		std::cout << Boss;

		try
		{
			for (int i = 42; i > 1; i--)
				Jojo.incrementeGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what();
		}

		try
		{
			for (int i = 42; i > 1; i--)
				Jojo.incrementeGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what();
		}
		std::cout << Jojo;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what();
	}

	try
	{
		Bureaucrat	GodTier("NON", 0);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what();
	}

	try
	{
		Bureaucrat	GodTier("NON", 151);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what();
	}

	return 0;
}
