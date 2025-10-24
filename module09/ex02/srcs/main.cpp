/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:30:16 by nbonnet           #+#    #+#             */
/*   Updated: 2025/10/24 16:27:39 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PmergeMe.hpp"

int main (int ac, char **av) {
    if (ac < 2)
    {
        std::cerr << "Error: need at least one argument" << std::endl;
        return 1;
    }
    PmergeMe algo;
    algo.init_cont(ac, av);
    algo.display_before(ac, av);
    
    
    
    algo.display_after();
    return 0;
}