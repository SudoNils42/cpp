/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:38:54 by nbonnet           #+#    #+#             */
/*   Updated: 2025/08/14 18:55:43 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Serializer.hpp"

int main() {
    Data d;
    std::cout << "&d = " << &d << std::endl;

    uintptr_t raw = Serializer::serialize(&d);
    std::cout << "serialize \"d\" " << std::endl;
    std::cout << "raw = 0x" << std::hex << raw << std::dec << std::endl;
    
    Data* d2 = Serializer::deserialize(raw);
    std::cout << "deserialize \"raw\"" << std::endl;
    
    std::cout << "&d = " << &d << "   d2 = " << d2 << std::endl;
    if (d2 == &d)
        std::cout << "d2 = &d --> OK" << std::endl;
    else
        std::cout << "Error, d2 != &d" << std::endl;

    return 0;
}