/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 21:02:58 by asando            #+#    #+#             */
/*   Updated: 2026/09/13 13:17:09 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

int	main(void) {
	try {
		Form a("DocumentA", 5, 150);
		Bureaucrat bu("Bu", 6);
		a.signForm(bu);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
