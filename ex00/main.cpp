/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:48:00 by asando            #+#    #+#             */
/*   Updated: 2026/09/06 18:13:36 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main(void) {
	std::cout << "TEST: Too Low Inisialization" << std::endl;

	try {
		Bureaucrat	alice("Alice", 151);
		std::cout << alice << std::endl;
	} catch (std::exception& e) {
		std::cout << "Execption: " << e.what() << std::endl << std::endl;
	}
	
	std::cout << "TEST: Too High Inisialization" << std::endl;

	try {
		Bureaucrat	alice("Alice", 0);
		std::cout << alice << std::endl;
	} catch (std::exception& e) {
		std::cout << "Execption: " << e.what() << std::endl << std::endl;
	}

	std::cout << "TEST: Call Setter and Getter Inisialization" << std::endl;

	try {
		Bureaucrat	alice("Alice", 50);

		std::cout << alice.getName() << std::endl;
		std::cout << alice.getGrade() << std::endl;
		alice.setDecGrade();
		std::cout << alice << std::endl;
		alice.setIncGrade();
		std::cout << alice << std::endl << std::endl;
	} catch (std::exception& e) {
		std::cout << "Execption: " << e.what() << std::endl;
	}

	std::cout << "TEST: Increase & Decrease over limit" << std::endl;

	try {
		Bureaucrat	alice("Alice", 150);

		alice.setDecGrade();
		std::cout << alice << std::endl;
	} catch (std::exception& e) {
		std::cout << "Execption: " << e.what() << std::endl;
	}

	try {
		Bureaucrat	alice("Alice", 1);

		alice.setIncGrade();
		std::cout << alice << std::endl;
	} catch (std::exception& e) {
		std::cout << "Execption: " << e.what() << std::endl;
	}
	return (0);
}
