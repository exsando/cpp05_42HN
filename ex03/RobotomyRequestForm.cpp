/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 17:49:09 by asando            #+#    #+#             */
/*   Updated: 2026/09/20 12:13:01 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("RobotomyRequestForm", 75, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	checkExecution(executor);

	std::cout << "* Drilling noise *" << std::endl;
	if (rand() % 2)
		std::cout << _target
			<< " has been Robotomized successfully 50% of the time" << std::endl;
	else
		std::cout << "Robotomy failed on" << _target << std::endl;
}
