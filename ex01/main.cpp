/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 21:02:58 by asando            #+#    #+#             */
/*   Updated: 2026/09/27 21:12:18 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

int	main(void) {
	std::cout << "Form Creation Test" << std::endl;
	try {
		Form formOne("DocumentA", 5, 150);
		std::cout << formOne << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "Form Creation Failed Test" << std::endl;
	try {
		Form formOne("DocumentA", 5, 151);
		std::cout << formOne << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form formOne("DocumentA", 0, 150);
		std::cout << formOne << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nSigning Test" << std::endl;
	try {
		Form formOne("DocumentA", 5, 150);
		Bureaucrat robert("Robert", 4);
		robert.signForm(formOne);
		std::cout << formOne << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "Signing Failed Test" << std::endl;
	try {
		Form formOne("DocumentA", 5, 150);
		Bureaucrat robert("Robert", 6);
		robert.signForm(formOne);
		std::cout << formOne << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
