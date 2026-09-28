/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 07:48:14 by asando            #+#    #+#             */
/*   Updated: 2026/09/28 13:56:12 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(){}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& rhs) {
	(void)rhs;
	return *this;
}

Intern::~Intern(){}

static AForm* createShrubberyForm(std::string target) {
	return (new ShrubberyCreationForm(target));
}

static AForm* createRobotomyForm(std::string target) {
	return (new RobotomyRequestForm(target));
}

static AForm* createPresidentialForm(std::string target) {
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string nameForm, std::string target) {
	int	i;

	std::string arrFormName[3] = { "shrubbery creation",
		"robotomy request", "presidential pardon" };

	for (i = 0; i < 3; i++) {
		if (arrFormName[i] == nameForm)
			break ;
	}

	if (i >= 3) {
		std::cout << "Form name not in the list!" << std::endl;
		return NULL;
	}

	AForm* (*funcs[3])(std::string) = {
		createShrubberyForm,
		createRobotomyForm,
		createPresidentialForm
	};
	std::cout << "Intern creates " << arrFormName[i] << " Form" << std::endl;

	return (funcs[i](target));
}
