/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:37:29 by nbonnet           #+#    #+#             */
/*   Updated: 2025/05/14 17:58:08 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	_type = type;
}

Weapon::~Weapon() {

}

std::string& Weapon::getType() {
	return _type;
}

void Weapon::setType(std::string typeValue) {
	_type = typeValue;
}
