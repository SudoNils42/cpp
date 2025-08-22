/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:15:43 by nbonnet           #+#    #+#             */
/*   Updated: 2025/08/22 14:57:21 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Array.hpp"


int main() {
    Array<int> IntTabEmpty();
    Array<int> IntTab(3);
    IntTab[0] = 1;
    IntTab[1] = 2;
    IntTab[2] = 3;
    
    Array<char> CharTabEmpty();
    Array<char> CharTab(3);
    CharTab[0] = 'a';
    CharTab[1] = 'b';
    CharTab[2] = 'c';
    
    Array<std::string> StringTab(2);
    StringTab[0] = "Hello";
    StringTab[1] = "wolrd!";
    
    
    
}