/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:47:15 by asando            #+#    #+#             */
/*   Updated: 2026/09/06 15:26:50 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class	Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& rhs);
		~Bureaucrat();

		const std::string&	getName(void) const;
		int					getGrade(void) const;
		void				setIncGrade(void);
		void				setDecGrade(void);

		class GradeTooHighExcep : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowExcep : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
#endif
