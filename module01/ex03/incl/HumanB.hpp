/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:06:52 by nbonnet           #+#    #+#             */
/*   Updated: 2025/05/14 18:07:16 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B
# define HUMAN_B
# include "Weapon.hpp"

class HumanB {
	private:
		Weapon _weapon;
		std::string _name;

	public:
		HumanB();
		~HumanB();
		void attack();

};


#endif
