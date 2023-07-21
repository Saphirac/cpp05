/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:52:11 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/07/20 13:52:11 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form 
{
private :

	std::string	_name;
	bool		_isSigned;
	int const	_signGrade;
	int const	_execGrade;

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

	class	AlreadySignedException : public std::exception
	{
	private :
		virtual char const *what(void) const throw();
	};

public :

	Form();
	Form(Form const &src);
	Form(std::string name, int signGrade, int execGrade);
	~Form();

	std::string const	&getName(void) const;
	bool const			&getIsSigned(void) const;
	int const			&getSignGrade(void) const;
	int const			&getExecGrade(void) const;

	void	beSigned(Bureaucrat const &b);

	Form	&operator=(Form const &src);
};

std::ostream	&operator<<(std::ostream &o, Form const &src);

#endif
