/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 20:10:58 by asando            #+#    #+#             */
/*   Updated: 2026/09/17 19:49:34 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute) {
		if (gradeToSign < 1 || gradeToExecute < 1)
			throw GradeTooHighExecp();
		if (gradeToSign > 150 || gradeToExecute > 150)
			throw GradeTooLowExecp();
		return ;
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form& Form::operator=(const Form& rhs) {
	if (this != &rhs) {
		this->_signed = rhs._signed;
	}
	return (*this);
}

Form::~Form(){}

const std::string& Form::getName() const {
	return (_name);
}

bool	Form::getIfSigned() const {
	return (_signed);
}

int	Form::getGradeToSign() const {
	return (_gradeToSign);
}

int	Form::getGradeToExecute() const {
	return (_gradeToExecute);
}

void	Form::beSigned(Bureaucrat& signer) {
	if (signer.getGrade() > this->_gradeToSign) {
		throw GradeTooLowExecp();
	}
	return ;
}

const char*	Form::GradeTooHighExecp::what() const throw() {
	return ("Grade too High!");
}

const char* Form::GradeTooLowExecp::what() const throw() {
	return ("Grade too Low!");
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << "Form Name : " << f.getName() << std::endl
		<< "Status : " << f.getIfSigned() << std::endl
		<< "Grade to Sign : " << f.getGradeToSign() << std::endl
		<< "Grade to Execute : " << f.getGradeToExecute() << std::endl;
	return (os);
}
