/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:34:37 by nbonnet           #+#    #+#             */
/*   Updated: 2025/08/15 19:55:07 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Base.hpp"

int main() {
    for (int i = 0; i < 10; i++)
    {
        std::cout << "Test " << i << std::endl;
        Base* ptr = generate();
        if (ptr != NULL)
        {
            identify(ptr);
            identify(*ptr);
            delete ptr;
        }
        else
            std::cout << "Error, NULL pointer" << std::endl;
    }
}