/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:47:31 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/05 15:18:51 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/WrongCat.hpp"

WrongCat::WrongCat() : Animal("WrongCat") {
    std::cout << "[WrongCat] Default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat& src) : Animal(src) {
    std::cout << "[WrongCat] copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat& rhs) {
    std::cout << "[WrongCat] operator= called" << std::endl;
    if (this != &rhs)
        Animal::operator=(rhs);
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "[WrongCat] Destructor called" << std::endl;
}

void WrongCat::makeSound(void) const {
    std::cout << "WRONG MEOUWWWWWWWW !!!" << std::endl;
}

std::string WrongCat::getType(void) const {
    return _type;
}