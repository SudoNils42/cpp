/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:55:40 by nbonnet           #+#    #+#             */
/*   Updated: 2025/09/30 14:58:59 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include <deque>

template <typename T>
void easyfind(T& haystack, int needle) {

    typename T::iterator i;
    i = haystack.begin();
    int index = 0;
    while (i != haystack.end())
    {
        if (*i == needle)
        {
            std::cout << "needle '" << needle << "' found at occurence '" << index << "'" << std::endl;
            return ;
        }
        i++;
        index++;
    }
    throw std::exception();
}