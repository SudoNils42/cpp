/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:10:48 by nbonnet           #+#    #+#             */
/*   Updated: 2025/09/05 16:43:36 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Span.hpp"

int main() {
    try {
        Span sp = Span(10);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        int arr[2];
        arr[0] = -100;
        arr[1] = -110;
        sp.addNumbers(arr, arr + 2);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan()<< std::endl;

    } catch (const std::exception &e) {}

    try {
        Span bigSp = Span(10000);
        int big[10000];
        for (int i = 0; i < 10000; i++) {
            big[i] = i;
        }
        bigSp.addNumbers(big, big + 10000);
        std::cout << "Shortest span: " << bigSp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSp.longestSpan()<< std::endl;
    } catch (std::exception &e) {}
    
    return 0;
}