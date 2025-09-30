/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:38:11 by nbonnet           #+#    #+#             */
/*   Updated: 2025/09/30 17:02:57 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        
        iterator begin();
        iterator end(); 
};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator  MutantStack<T>::end()
{
    return (this->c.end());
}