/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 07:48:05 by asando            #+#    #+#             */
/*   Updated: 2026/09/20 07:53:50 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>

class AForm;

class Intern {
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& rhs);
		~Intern();

		AForm* makeForm(std::string nameForm, std::string target);
};

#endif
