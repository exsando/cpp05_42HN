/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:47:48 by asando            #+#    #+#             */
/*   Updated: 2026/09/19 20:22:31 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name), _grade(grade) {
		if (_grade < 1)
			throw GradeTooHighExcep();
		if (_grade > 150)
			throw GradeTooLowExcep();
		return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat(){}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs) {
	if (this != &rhs)
		_grade = rhs._grade;
	return *this;
}

const std::string& Bureaucrat::getName(void) const {
	return _name;
}

int	Bureaucrat::getGrade(void) const {
	return _grade;
}

void	Bureaucrat::setIncGrade(void) {
	if (_grade - 1 < 1)
		throw GradeTooHighExcep();
	_grade--;
}

void	Bureaucrat::setDecGrade(void) {
	if (_grade + 1 > 150)
		throw GradeTooLowExcep();
	_grade++;
}

void	Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName()
			<< std::endl;

	} catch (std::exception& e) {
		std::cout << _name << " couldn't sign " << form.getName()
			<< " because" << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const& form) const {
	try {
		form.execute(*this);
		std::cout << _name << " execute " << form.getName()
			<< std::endl;
	} catch (std::exception& e) {

		std::cout << _name << " couln't execute " << form.getName()
			<< " because" << e.what() << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighExcep::what() const throw() {
	return "Grade too High!";
}

const char*	Bureaucrat::GradeTooLowExcep::what() const throw() {
	return "Grade too Low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
