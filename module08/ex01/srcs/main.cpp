/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:10:48 by nbonnet           #+#    #+#             */
/*   Updated: 2025/09/04 18:37:13 by nbonnet          ###   ########.fr       */
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

    } catch (const std::exception& e) {}

    return 0;
}