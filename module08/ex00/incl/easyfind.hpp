/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:55:40 by nbonnet           #+#    #+#             */
/*   Updated: 2025/09/03 17:48:23 by nbonnet          ###   ########.fr       */
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
    std::vector<int>::iterator i;
    i = haystack.begin();
    while (i < haystack.end())
    {
        if (*i == needle)
        {
            std::cout << "needle '" << needle << "' found at occurence '" << *i << "'" << std::endl;
            return ;
        }
        i++;
    }
    throw std::exception();
}