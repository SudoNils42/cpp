/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:30:16 by nbonnet           #+#    #+#             */
/*   Updated: 2025/10/29 17:21:41 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PmergeMe.hpp"


int main (int ac, char **av) {
    if (ac < 2)
    {
        std::cerr << "Error: need at least one argument" << std::endl;
        return 1;
    }
    
    PmergeMe algo;
    algo.init_cont(ac, av);
    algo.display_before(ac, av);
    
    std::deque<int> deque = algo.get_deque();
    clock_t start = clock();
    ford_johnson(deque);
    clock_t end = clock();
    double deque_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    std::vector<int> vector = algo.get_vector();
    start = clock();
    ford_johnson(vector);
    end = clock();
    double vector_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    algo.display_after(deque);
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << deque_time << " us" << std::endl;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << vector_time << " us" << std::endl;
    return 0;
}