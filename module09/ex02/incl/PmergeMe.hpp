/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:30:04 by nbonnet           #+#    #+#             */
/*   Updated: 2025/10/24 16:25:22 by nbonnet          ###   ########.fr       */
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
        void display_after();
};