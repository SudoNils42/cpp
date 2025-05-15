/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:28:49 by nbonnet           #+#    #+#             */
/*   Updated: 2025/05/15 16:23:43 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H_HPP
# define WEAPON_H_HPP
# include <iostream>
# include <string>

class Weapon {
	private:
		std::string _type;

	public:
		Weapon(std::string type);
		~Weapon();
		const std::string& getType() const;
		void setType(std::string typeValue);


};

#endif
