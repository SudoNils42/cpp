/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:10:48 by nbonnet           #+#    #+#             */
/*   Updated: 2025/09/04 17:13:06 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Span.hpp"

int main() {
try {
        Span sp(4);
        sp.addNumber(4);
        sp.addNumber(3);
        sp.addNumber(1);
        sp.addNumber(10);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan()<< std::endl;

    } catch (const std::exception& e) {}

    return 0;
}