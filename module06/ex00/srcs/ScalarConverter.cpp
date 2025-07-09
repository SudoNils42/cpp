/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:33:49 by nbonnet           #+#    #+#             */
/*   Updated: 2025/07/09 14:11:45 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "[ScalarConverter] constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
    std::cout << "[ScalarConverter] copy constructor called" << std::endl;
    (void)src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
    std::cout << "[ScalarConverter] operator= called" << std::endl;
    (void)rhs;
    return *this;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "[ScalarConverter] destructor called" << std::endl;
}

void ScalarConverter::convert(std::string input) {
    if (input == "nan" || input == "nanf" || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff" || input == "inff")
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    if (input.length() == 1 && !std::isdigit(input[0]))
    {
        char c = input[0];
        if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        return;
    }
    
    int value = std::atoi(input.c_str());
    if (value == 0 && input != "0")
        std::cout << "char: impossible" << std::endl;
    else if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max())
    {
        char c = static_cast<char>(value);
        if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;
}