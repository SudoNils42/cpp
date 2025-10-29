/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:30:04 by nbonnet           #+#    #+#             */
/*   Updated: 2025/10/29 18:14:05 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <deque>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class PmergeMe {
    private:
        std::deque<int> _deque;
        std::vector<int> _vector;
        
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe& operator=(const PmergeMe &rhs);
        ~PmergeMe();

        void init_cont(int ac, char **av);
        void display_before(int ac, char **av);
        void display_after(std::deque<int> deque);
        std::deque<int>& get_deque();
        std::vector<int>& get_vector();

};

template <typename T>
int jacobsthal(int k)
{
    if (k <= 0)
        return 0;
    if (k == 1)
        return 1;
    int a = 1;
    int b = 1;
    for (int i = 2; i < k; i++)
    {
        int c = 2 * b + a;
        a = b;
        b = c;
    }
    return b;
}

template <typename Container>
void ford_johnson(Container &container) {
    if (container.size() <= 1)
        return;

    Container main;
    Container pend;
    
    int odd = -1;
    if (container.size() % 2 == 1)
    {
        odd = container.back();
        container.pop_back();
    }
    
    typename Container::iterator it = container.begin();
    while (it != container.end())
    {
        int a = *it;
        it++;
        int b = *it;
        main.push_back(std::min(a, b));
        pend.push_back(std::max(a, b));
        it++;
    }
    ford_johnson(main);

    int size = pend.size();
    int k = 1;
    while (size > 0)
    {
        int j = jacobsthal<int>(k);
        if (j >= size)
            break;
        typename Container::iterator it = pend.begin();
        for (int i = 0; i < j; ++i)
            ++it;
        int val = *it;
        pend.erase(it);
        main.insert((std::lower_bound(main.begin(), main.end(), val)), val);
        --size;
        ++k;
    }
    if (odd != -1)
        main.insert((std::lower_bound(main.begin(), main.end(), odd)), odd);
    
    container = main;
}