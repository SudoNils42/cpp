/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:58:34 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/26 14:44:57 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, double grade) : _name(name), _grade(grade) {
    if (grade < 1)
        Bureaucrat::GradeTooHighException(grade);
    else if (grade > 150)
        Bureaucrat::GradeTooLowException(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat& src) : _name(src._name), _grade(src._grade) {
    if (_grade < 1)
        Bureaucrat::GradeTooHighException(_grade);
    else if (_grade > 150)
        Bureaucrat::GradeTooLowException(_grade);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
    if (this != &rhs)
    {
        _name = rhs._name;
        _grade = rhs._grade;
    }
    if (_grade < 1)
        Bureaucrat::GradeTooHighException(_grade);
    else if (_grade > 150)
        Bureaucrat::GradeTooLowException(_grade);
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName(Bureaucrat& src) {
    std::string tmp;
    tmp = src._name;
    return tmp;
}

double Bureaucrat::getGrade(Bureaucrat& src) {
    double tmp;
    tmp = src._grade;
    return tmp;
}

void Bureaucrat::GradeTooHighException (double grade) {
    if (grade < 1)
        std::cout << "Grade [" << grade << "] is to high" << std::endl;
}

void Bureaucrat::GradeTooLowException (double grade) {
    if (grade > 150)
        std::cout << "Grade [" << grade << "] is to low" << std::endl;
}

void Bureaucrat::operator++() {
    _grade--;
    if (_grade < 1)
        Bureaucrat::GradeTooHighException(_grade);
}

void Bureaucrat::operator--() {
    _grade++;
    if (_grade > 150)
        Bureaucrat::GradeTooLowException(_grade);
}