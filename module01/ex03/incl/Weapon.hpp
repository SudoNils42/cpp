/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:28:49 by nbonnet           #+#    #+#             */
/*   Updated: 2025/05/14 17:44:22 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H
# include <iostream>
# include <string>

class Weapon {
	private:
		std::string _type;

	public:
		Weapon(std::string type);
		~Weapon();
		std::string& getType();
		void setType(std::string typeValue);


};

#endif
