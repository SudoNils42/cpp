/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:52:24 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/05 15:32:10 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Animal.hpp"
#include "../incl/Cat.hpp"
#include "../incl/Dog.hpp"
#include "../incl/WrongAnimal.hpp"
#include "../incl/WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    j->makeSound();
    i->makeSound();
    meta->makeSound();

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound();
    wrongMeta->makeSound();

    Animal* copyAnimal = new Animal();
    *copyAnimal = *meta;
    std::cout << copyAnimal->getType() << " " << std::endl;
    copyAnimal->makeSound();

    Cat* copyCat = new Cat();
    *copyCat = *new Cat();
    std::cout << copyCat->getType() << " " << std::endl;
    copyCat->makeSound();

    Dog* assignedDog = new Dog();
    *assignedDog = *new Dog();
    std::cout << assignedDog->getType() << " " << std::endl;
    assignedDog->makeSound();

    WrongCat* copyWrongCat = new WrongCat();
    *copyWrongCat = *new WrongCat();
    std::cout << copyWrongCat->getType() << " " << std::endl;
    copyWrongCat->makeSound();

    delete meta;
    delete j;
    delete i;
    delete wrongMeta;
    delete wrongCat;
    delete copyAnimal;
    delete copyCat;
    delete new Cat();
    delete assignedDog;
    delete new Dog();
    delete copyWrongCat;
    delete new WrongCat();

    return 0;
}