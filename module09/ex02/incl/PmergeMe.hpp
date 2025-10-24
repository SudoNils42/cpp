/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:30:04 by nbonnet           #+#    #+#             */
/*   Updated: 2025/10/24 18:21:13 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <deque>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

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


template <typename Container>
void merge_sort(Container &container) {
    
    if (container.size() <= 1)
        return;
    else if (container.size() == 2) {
        if (container[0] > container[1])
            std::swap(container[0], container[1]);
        return;
    }
    size_t mid = container.size() / 2;
    Container left(container.begin(), container.begin() + mid);
    Container right(container.begin() + mid, container.end());
    
    merge_sort(left);
    merge_sort(right);

    container.clear();
    typename Container::iterator left_it = left.begin();
    typename Container::iterator right_it = right.begin();
    typename Container::iterator left_end = left.end();
    typename Container::iterator right_end = right.end();

    while (left_it != left_end && right_it != right_end) {
        if (*left_it <= *right_it) {
            container.push_back(*left_it);
            ++left_it;
        } else {
            container.push_back(*right_it);
            ++right_it;
        }
    }

    // Ajouter les éléments restants
    while (left_it != left_end) {
        container.push_back(*left_it);
        ++left_it;
    }
    while (right_it != right_end) {
        container.push_back(*right_it);
        ++right_it;
    }
}