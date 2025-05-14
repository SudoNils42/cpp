/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:59:40 by nbonnet           #+#    #+#             */
/*   Updated: 2025/05/14 18:11:40 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A
# define HUMAN_A
# include "Weapon.hpp"

class HumanA {
	private:
		Weapon _weapon;
		std::string _name;

	public:
		HumanA(std::string name, Weapon weapon);
		~HumanA();
		void attack();

};


#endif
