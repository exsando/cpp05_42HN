/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 20:10:58 by asando            #+#    #+#             */
/*   Updated: 2026/09/13 19:36:06 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, const int gradeToSign,
		const int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute) {
		if (gradeToSign < 1)
			throw GradeTooHighExecp();
		if (gradeToSign > 150)
			throw GradeTooLowExecp();
		if (gradeToExecute < 1)
			throw GradeTooHighExecp();
		if (gradeToExecute > 150)
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
