/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:59:11 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/26 14:44:27 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Bureaucrat {
    private:
        std::string _name;
        double _grade;
    public:
         Bureaucrat(std::string name, double grade);
         Bureaucrat (Bureaucrat& src);
         Bureaucrat& operator=(const Bureaucrat& rhs);
         ~Bureaucrat();
         std::string getName(Bureaucrat& src);
         double getGrade(Bureaucrat& src);
         void GradeTooHighException(double grade);
         void GradeTooLowException(double grade);
         void operator++();
         void operator--();
};