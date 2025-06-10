/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:52:24 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/10 14:35:08 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Animal.hpp"
#include "../incl/Cat.hpp"
#include "../incl/Dog.hpp"
#include "../incl/WrongAnimal.hpp"
#include "../incl/WrongCat.hpp"
#include "../incl/Brain.hpp"

int main()
{
    // Test de l'exercice 00 : polymorphisme
    std::cout << "=== Test de l'exercice 00 ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    j->makeSound(); // Affiche "BARKKKKKK !!!"
    i->makeSound(); // Affiche "MEOUWWWWWWWW !!!"
    meta->makeSound(); // Affiche "[makeSound] WEIRRRRD animal sound"
    
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); // Affiche "WRONG MEOUWWWWWWWW !!!"
    wrongMeta->makeSound(); // Affiche "[makeSound] WEIRRRRD WrongAnimal sound"

    delete meta;
    delete j;
    delete i;
    delete wrongMeta;
    delete wrongCat;

    // Test de l'exercice 01 : tableau d'objets Animal
    std::cout << "\n=== Test de l'exercice 01 : Tableau d'objets Animal ===" << std::endl;
    const int SIZE = 10;
    Animal* animals[SIZE];
    
    // Remplissage du tableau : moitié Dog, moitié Cat
    for (int i = 0; i < SIZE / 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = SIZE / 2; i < SIZE; ++i) {
        animals[i] = new Cat();
    }

    // Affichage des types et sons
    for (int i = 0; i < SIZE; ++i) {
        std::cout << "Animal " << i << " type: " << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
    }

    // Suppression des objets du tableau
    for (int i = 0; i < SIZE; ++i) {
        delete animals[i];
    }

    // Test de copie profonde
    std::cout << "\n=== Test de copie profonde ===" << std::endl;
    Dog original;
    original.getBrain().setIdea(0, "Chase tail");
    Dog copy = original;
    copy.getBrain().setIdea(0, "Bark loudly");
    
    std::cout << "Original idea: " << original.getBrain().getIdea(0) << std::endl; // Doit afficher "Chase tail"
    std::cout << "Copy idea: " << copy.getBrain().getIdea(0) << std::endl;       // Doit afficher "Bark loudly"

    // Test des fonctionnalités de Brain
    std::cout << "\n=== Test des fonctionnalités de Brain ===" << std::endl;
    Cat myCat; // Renommé pour éviter le conflit
    myCat.getBrain().setIdea(0, "Catch mouse");
    myCat.getBrain().setIdea(1, "Sleep on couch");
    std::cout << "Cat idea 0: " << myCat.getBrain().getIdea(0) << std::endl; // Doit afficher "Catch mouse"
    std::cout << "Cat idea 1: " << myCat.getBrain().getIdea(1) << std::endl; // Doit afficher "Sleep on couch"
    std::cout << "Cat idea 100: " << myCat.getBrain().getIdea(100) << std::endl; // Doit afficher "Invalid index"

    // Test de suppression sans fuite
    std::cout << "\n=== Test de suppression sans fuite ===" << std::endl;
    const Animal* dog = new Dog();
    const Animal* anotherCat = new Cat(); // Renommé pour éviter le conflit
    delete dog; // Ne doit pas causer de fuite
    delete anotherCat; // Ne doit pas causer de fuite

    return 0;
}