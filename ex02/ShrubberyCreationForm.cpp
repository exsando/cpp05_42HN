/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 11:55:35 by asando            #+#    #+#             */
/*   Updated: 2026/09/13 20:34:20 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target){}

ShrubberyCreationForm& 
	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
		if (this != &rhs) {
			AForm::operator=(rhs);
			_target = rhs._target;
		}
		return *this;
	}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	checkExecution(executor);

	std::ofstream	file((_target + "_shrubbery").c_str());
	file << "      /\\\n"
		<< "     /  \\\n"
		<< "    /++++\\\n"
		<< "   /  ()  \\\n"
		<< "  /______  \\\n"
		<< "     ||\n"
		<< "     ||\n";
	file.close();
}
