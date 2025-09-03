/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:04:19 by nbonnet           #+#    #+#             */
/*   Updated: 2025/09/03 15:43:35 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/easyfind.hpp"

int main() {
    
    int needle = 5;
    std::vector<int> haystack = {1, 2, 3, 4, 5, 6, 7, 8};
    std::list<int> haystack = {1, 2, 3, 4, 5, 6, 7, 8};
    try {
    easyfind(haystack, needle);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}