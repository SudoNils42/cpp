/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:26:59 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/26 14:47:57 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"

int main() {
    // Test 1 : Création d'un bureaucrate valide
    try {
        std::cout << "\n=== Test 1: Création d'un bureaucrate valide ===\n";
        Bureaucrat employee("Employee", 50);
        std::cout << "Bureaucrate créé : " << employee.getName() << ", grade " << employee.getGrade() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Erreur inattendue: " << e.what() << std::endl;
    }

    // Test 2 : Grade trop haut
    try {
        std::cout << "\n=== Test 2: Grade trop haut (-1) ===\n";
        Bureaucrat boss("Boss", -1);
    } catch (std::exception &e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }

    // Test 3 : Grade trop bas
    try {
        std::cout << "\n=== Test 3: Grade trop bas (151) ===\n";
        Bureaucrat intern("Intern", 151);
    } catch (std::exception &e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }

    // Test 4 : Incrémentation et décrémentation
    try {
        std::cout << "\n=== Test 4: Incrémentation et décrémentation ===\n";
        Bureaucrat worker("Worker", 2);
        std::cout << "Avant incrémentation : " << worker.getName() << ", grade " << worker.getGrade() << std::endl;
        ++worker;
        std::cout << "Après incrémentation : " << worker.getName() << ", grade " << worker.getGrade() << std::endl;
        ++worker; // Devrait lancer une exception (grade 1 -> 0)
    } catch (std::exception &e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }

    // Test 5 : Opérateur de copie
    try {
        std::cout << "\n=== Test 5: Copie d'un bureaucrate ===\n";
        Bureaucrat original("Original", 100);
        Bureaucrat copy(original);
        std::cout << "Original : " << original.getName() << ", grade " << original.getGrade() << std::endl;
        std::cout << "Copie : " << copy.getName() << ", grade " << copy.getGrade() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }

    // Test 6 : Opérateur d'assignation
    try {
        std::cout << "\n=== Test 6: Assignation d'un bureaucrate ===\n";
        Bureaucrat worker1("Worker1", 75);
        Bureaucrat worker2("Worker2", 25);
        std::cout << "Avant assignation : Worker1 grade " << worker1.getGrade() << ", Worker2 grade " << worker2.getGrade() << std::endl;
        worker2 = worker1;
        std::cout << "Après assignation : Worker1 grade " << worker1.getGrade() << ", Worker2 grade " << worker2.getGrade() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }

    return 0;
}