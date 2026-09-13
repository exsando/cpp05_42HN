/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 20:10:58 by asando            #+#    #+#             */
/*   Updated: 2026/09/13 19:51:06 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string& name, const int gradeToSign,
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

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm& AForm::operator=(const AForm& rhs) {
	if (this != &rhs) {
		this->_signed = rhs._signed;
	}
	return (*this);
}

AForm::~AForm(){}

const std::string& AForm::getName() const {
	return (_name);
}

bool	AForm::getIfSigned() const {
	return (_signed);
}

int	AForm::getGradeToSign() const {
	return (_gradeToSign);
}

int	AForm::getGradeToExecute() const {
	return (_gradeToExecute);
}

void	AForm::beSigned(Bureaucrat& signer) {
	if (signer.getGrade() > this->_gradeToSign) {
		throw GradeTooLowExecp();
	}
	return ;
}

void	AForm::checkExecution(const Bureaucrat& executor) const {
	if (_signed == false)
		throw FormNotSignedExecp();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowExecp();
	return ;
}

const char*	AForm::GradeTooHighExecp::what() const throw() {
	return ("Grade too High!");
}

const char* AForm::GradeTooLowExecp::what() const throw() {
	return ("Grade too Low!");
}

const char* AForm::FormNotSignedExecp::what() const throw() {
	return ("Form is not signed");
}
