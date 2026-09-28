/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 11:17:02 by asando            #+#    #+#             */
/*   Updated: 2026/09/28 13:40:06 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	Bureaucrat robert("Robert", 1);
	Bureaucrat julia("julia", 50);

	std::cout<< "== TEST SUCCESS EXECUTION ==\n" << std::endl;
	ShrubberyCreationForm testShrubberyForm("ShrubberyTest");
	AForm* testRobotomyForm = new RobotomyRequestForm("TargetOne");
	AForm* testPresidentialForm = new PresidentialPardonForm("Jhonny");

	robert.signForm(testShrubberyForm);
	robert.executeForm(testShrubberyForm);

	std::cout<< std::endl;
	robert.signForm(*testRobotomyForm);
	robert.executeForm(*testRobotomyForm);

	std::cout<< std::endl;
	robert.signForm(*testPresidentialForm);
	robert.executeForm(*testPresidentialForm);

	std::cout<< std::endl;
	std::cout << testShrubberyForm << std::endl;
	std::cout << *testRobotomyForm << std::endl;
	std::cout << *testPresidentialForm << std::endl;

	delete testRobotomyForm;
	delete testPresidentialForm;

	std::cout<< "== TEST FAILED EXECUTION ==\n" << std::endl;

	ShrubberyCreationForm testShrubberyFormTwo("ShrubberyTestTwo");
	AForm* testRobotomyFormTwo = new RobotomyRequestForm("TargetTwo");
	AForm* testPresidentialFormTwo = new PresidentialPardonForm("Depp");

	julia.signForm(testShrubberyFormTwo);
	julia.executeForm(testShrubberyFormTwo);

	std::cout<< std::endl;
	julia.signForm(*testRobotomyFormTwo);
	julia.executeForm(*testRobotomyFormTwo);

	std::cout<< std::endl;
	julia.signForm(*testPresidentialFormTwo);
	julia.executeForm(*testPresidentialFormTwo);

	std::cout<< std::endl;
	std::cout << testShrubberyFormTwo << std::endl;
	std::cout << *testRobotomyFormTwo<< std::endl;
	std::cout << *testPresidentialFormTwo << std::endl;

	delete testRobotomyFormTwo;
	delete testPresidentialFormTwo;
	return (0);
}
