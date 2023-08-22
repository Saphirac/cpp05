/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:52:11 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/07/20 13:52:11 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm 
{
private :

	std::string	_name;
	bool		_isSigned;
	int const	_signGrade;
	int const	_execGrade;

protected :

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

	class	NotSignedException : public std::exception
	{
	private :
		virtual char const *what(void) const throw();
	};

public :

	AForm(void);
	AForm(AForm const &src);
	AForm(std::string name, int signGrade, int execGrade);
	virtual	~AForm();

	std::string const	&getName(void) const;
	bool const			&getIsSigned(void) const;
	int const			&getSignGrade(void) const;
	int const			&getExecGrade(void) const;

	void	setSigned(bool const &input);

	virtual void	beSigned(Bureaucrat const &b) = 0;
	virtual void	execute(Bureaucrat const &b) const = 0;

	AForm	&operator=(AForm const &src);
};

std::ostream	&operator<<(std::ostream &o, AForm const &src);

#endif
