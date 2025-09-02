/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:55:40 by nbonnet           #+#    #+#             */
/*   Updated: 2025/09/02 18:28:58 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>

template <class T>
void easyfind(T& haystack, int needle) {
    
    int i = 0;
    while (haystack[i])
    {
        if (haystack[i] - '0' == needle)
        {
            std::cout << "needle found at occurence '" << i << "'" << std::endl;
            return ;
        }
        i++;
    }
    throw std::exception();
}