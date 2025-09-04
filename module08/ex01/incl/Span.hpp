/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:03:52 by nbonnet           #+#    #+#             */
/*   Updated: 2025/09/04 15:12:45 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


class Span {
    private:
        unsigned int _N;

    public:
        Span(unsigned int N);
        Span(Span& src);
        Span& operator=(Span& rhs);
        ~Span();

        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
};