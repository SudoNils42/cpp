/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:54:13 by nbonnet           #+#    #+#             */
/*   Updated: 2025/10/23 15:19:10 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/RPN.hpp"

int main (int ac, char **av) {
    if (ac != 2)
    {
        std::cerr << "Error: need one argument" << std::endl;
        return 1;
    }
    RPN rpn;
    try {
        rpn.parse_input(std::string(av[1]));
        calculation<double>(std::string(av[1]));
    } catch (const char* e) {
        std::cerr << e << std::endl; 
    }
    
    return 0;
}