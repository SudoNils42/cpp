/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:30:04 by nbonnet           #+#    #+#             */
/*   Updated: 2025/10/30 17:39:41 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <deque>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
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

        int init_cont(int ac, char **av);
        void display_before(int ac, char **av);
        void display_after(std::deque<int> deque);
        std::deque<int>& get_deque();
        std::vector<int>& get_vector();

};

int jacobsthal(int n);

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
   
    std::cout << "DEBUG: Taille initiale: " << container.size() << std::endl;
    if (odd != -1)
        std::cout << "DEBUG: Element impair extrait: " << odd << std::endl;

    typename Container::iterator it = container.begin();
    while (it != container.end())
    {
        int a = *it;
        it++;
        int b = *it;
        main.push_back(std::min(a, b));
        pend.push_back(std::max(a, b));
        it++;

        std::cout << "DEBUG: Paire (" << a << ", " << b 
                  << ") -> main: " << std::min(a, b) 
                  << ", pend: " << std::max(a, b) << std::endl;
    }

    std::cout << "DEBUG: Appel recursif sur main (taille: " << main.size() << ")" << std::endl;

    ford_johnson(main);
    std::cout << "DEBUG: Main trie: ";
    for (typename Container::iterator i = main.begin(); i != main.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;
    std::cout << "DEBUG: Pend en attente: ";
    for (typename Container::iterator i = pend.begin(); i != pend.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;

    int n = 1;
    while (!pend.empty())
    {
        int j = jacobsthal(n);
        if (j >= static_cast<int>(pend.size()))
            break;

        std::cout << "DEBUG: Jacobsthal(" << n << ") = " << j 
                  << " -> insertion de pend[" << j << "]" << std::endl;

        typename Container::iterator it = pend.begin();
        for (int i = 0; i < j; i++)
            it++;
        int val = *it;
        pend.erase(it);

        std::cout << "DEBUG: Insertion de " << val << " dans main" << std::endl;

        main.insert((std::lower_bound(main.begin(), main.end(), val)), val);

        n++;
    }
    if (odd != -1)
        pend.push_back(odd);

    std::cout << "DEBUG: Insertion finale des elements restants (pend): ";
    for (typename Container::iterator i = pend.begin(); i != pend.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;

    while (!pend.empty())
    {
        int val = pend.back();
        pend.pop_back();

        std::cout << "DEBUG: Insertion finale de " << val << std::endl;

        main.insert((std::lower_bound(main.begin(), main.end(), val)), val);
    }
    container = main;

    std::cout << "DEBUG: Conteneur trie: ";
    for (typename Container::iterator i = container.begin(); i != container.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;
}