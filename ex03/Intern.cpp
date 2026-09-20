/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 07:48:14 by asando            #+#    #+#             */
/*   Updated: 2026/09/20 12:13:43 by asando           ###   ########.fr       */
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

AForm* Intern::makeForm(std::string nameForm, std::string target) {
	int	i;

	std::string arrFormName[3] = { "shrubbery creation",
		"robotomy request", "presidential pardon" };

	for (i = 0; i < 3; i++) {
		if (arrFormName[i] == nameForm)
			break ;
	}

	switch (i) {
		case 0:
			std::cout << "Intern creates " << nameForm << std::endl;
			return new ShrubberyCreationForm(target);
		case 1:
			std::cout << "Intern creates " << nameForm << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << "Intern creates " << nameForm << std::endl;
			return new PresidentialPardonForm(target);
		default:
			std::cout << "Intern couldn't create " << nameForm
				<< ", because it is not in the list" << std::endl;
			return NULL;
	}
}
