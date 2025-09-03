/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:55:40 by nbonnet           #+#    #+#             */
/*   Updated: 2025/09/03 15:44:35 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>

template <typename T>
void easyfind(T& haystack, int needle) {
    

    while (haystack[i])
    {
        if (haystack[i] == needle)
        {
            std::cout << "needle '" << needle << "' found at occurence '" << i << "'" << std::endl;
            return ;
        }

    }
    throw std::exception();
}