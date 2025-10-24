/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:30:34 by nbonnet           #+#    #+#             */
/*   Updated: 2025/10/24 16:31:09 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src) : _deque(src._deque), _vector(src._vector) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
    if (this != &rhs)
    {
        _deque = rhs._deque;
        _vector = rhs._vector;

    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::init_cont(int ac, char **av) {
    int i = 1;
    while (i < ac)
    {
     _deque.push_back(std::atoi(av[i]));
     _vector.push_back(std::atoi(av[i]));
     i++;
    }
}

void PmergeMe::display_before(int ac, char **av) {
    std::cout << "Before:";
    int max = 6;
    if (ac > 6)
        max = 5;
    int i = 1;
    while (i != max && i < ac)
    {
        std::cout << " " << av[i];
        i++;
    }
    if (max == 5)
        std::cout << " [...]";
    std::cout << std::endl;
}

void PmergeMe::display_after() {
    std::cout << "After:";
    int max = 6;
    
    if (_deque.size() > 5)
        max = 5;
    int i = 1;
    while (i != max && i != static_cast<int>(_deque.size()) + 1)
    {
        std::cout << " " << _deque.front();
        i++;
    }
    if (max == 5)
        std::cout << " [...]";
    std::cout << std::endl;
}