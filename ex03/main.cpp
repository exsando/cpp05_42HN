/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 11:17:02 by asando            #+#    #+#             */
/*   Updated: 2026/09/28 20:54:00 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int	main(void) {
	Bureaucrat robert("Robert", 1);
	Intern cody;

	std::cout<< "== TEST SUCCESS EXECUTION ==\n" << std::endl;
	AForm* testPresidentialForm = cody.makeForm("presidential pardon", "jhonny");
	AForm* testShrubberyForm = cody.makeForm("shrubbery creation", "home");
	AForm* testRobotomyForm = cody.makeForm("robotomy request", "target one");

	robert.signForm(*testShrubberyForm);
	robert.executeForm(*testShrubberyForm);

	std::cout<< std::endl;
	robert.signForm(*testRobotomyForm);
	robert.executeForm(*testRobotomyForm);

	std::cout<< std::endl;
	robert.signForm(*testPresidentialForm);
	robert.executeForm(*testPresidentialForm);

	std::cout<< std::endl;
	std::cout << *testShrubberyForm << std::endl;
	std::cout << *testRobotomyForm << std::endl;
	std::cout << *testPresidentialForm << std::endl;

	delete testRobotomyForm;
	delete testPresidentialForm;
	delete testShrubberyForm;

	std::cout<< "== TEST FAILED EXECUTION ==\n" << std::endl;

	AForm* testRobotomyFormTwo = cody.makeForm("robotomy two request", "target one");

	delete testRobotomyFormTwo;

	if (testRobotomyFormTwo != NULL) {
		robert.signForm(*testRobotomyFormTwo);
		robert.executeForm(*testRobotomyFormTwo);
	}
	return (0);
}
