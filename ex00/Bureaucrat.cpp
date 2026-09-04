/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:47:48 by asando            #+#    #+#             */
/*   Updated: 2026/09/04 20:31:40 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string>

Bureaucrat::Bureaucrat(std::string& name, int grade)
	: _name(name), _grade(grade) {
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat(){}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs) {
	if (this != &rhs)
		_grade = rhs._grade;
	return *this;
}
