/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:53:02 by nbonnet           #+#    #+#             */
/*   Updated: 2025/07/08 16:00:32 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ScalarConverter.hpp"

int main(int ac, char** av) {
    if (ac != 2)
    {
        std::cout << "please provide 1 argument" << std::endl;
        return 0;
    }
    ScalarConverter test(av[1]);
    std::cout << "char: " << test.toChar() << std::endl;
    return 0;
}