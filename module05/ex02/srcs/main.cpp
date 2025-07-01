/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:19:11 by nbonnet           #+#    #+#             */
/*   Updated: 2025/07/01 17:33:37 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incl/Bureaucrat.hpp"
#include "../incl/AForm.hpp"

int main() {
    try {
        std::cout << "=== Test 1 ===" << std::endl;
        Bureaucrat boss("Boss", 50);
        AForm form("Contract", 10, 50);
        std::cout << boss << std::endl;
        std::cout << form << std::endl;
        boss.signForm(Aform);
        std::cout << Aform << std::endl;
        boss.incrementGrade();
        std::cout << boss << std::endl;
        
    }
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cerr << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }
    catch (AForm::GradeTooHighException &e) {
        std::cerr << e.what() << std::endl;
    }
    catch (AForm::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}