/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:03:11 by nbonnet           #+#    #+#             */
/*   Updated: 2025/05/14 16:46:54 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Zombie.hpp"

int	main() {
	int	N = 8;
	Zombie* horde = zombieHorde(N, "Horde");
	if (horde == NULL) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	for (int i = 0; i < N; i++){
		horde[i].announce();
	}
	delete []horde;

	return 0;
}
