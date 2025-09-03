/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:04:19 by nbonnet           #+#    #+#             */
/*   Updated: 2025/09/03 17:47:57 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/easyfind.hpp"

int main() {
    
    int needle = 5;
    std::vector<int> haystack ;
    haystack.push_back(1);
    haystack.push_back(2);
    haystack.push_back(3);
    haystack.push_back(4);
    haystack.push_back(5);
    haystack.push_back(6);
    haystack.push_back(7);
    haystack.push_back(8);
    try {
    easyfind(haystack, needle);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}