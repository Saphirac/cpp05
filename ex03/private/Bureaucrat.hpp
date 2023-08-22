/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:32:04 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/07/19 18:32:04 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# ifndef DEBUG
#  define DEBUG 0
# endif

# include <string>
# include <iostream>
# include "AForm.hpp"

class	AForm;

class	Bureaucrat
{
private:
	
	std::string const	_name;
	int					_grade;

	class	GradeTooHighException : public std::exception
	{
	private :
		virtual char const *what(void) const throw();
	};
	
	class	GradeTooLowException : public std::exception
	{
	private :
		virtual char const *what(void) const throw();
	};

public:
	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat();

	std::string const	getName(void) const;
	int					getGrade(void) const;

	void	incrementeGrade(void);
	void	decrementeGrade(void);
	void	signForm(AForm &tosign);
	void	executeForm(AForm const &toexecute);

	//operator
	Bureaucrat	&operator=(Bureaucrat const &src);
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &src);

#endif
