/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:59:05 by nbonnet           #+#    #+#             */
/*   Updated: 2025/05/14 18:42:31 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon) {
	_name = name;
	_weapon = weapon;
}
HumanA::~HumanA() {

}

void HumanA::attack() {

	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
