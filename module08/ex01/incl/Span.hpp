/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:03:52 by nbonnet           #+#    #+#             */
/*   Updated: 2025/09/04 15:42:05 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>


class Span {
    private:
        unsigned int _N;
        std::vector<int> _cont;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span& src);
        Span& operator=(const Span& rhs);
        ~Span();

        void addNumber(int n);
        int shortestSpan();
        int longestSpan();

        template <typename T>
        void addNumbers(T first, T last);
};