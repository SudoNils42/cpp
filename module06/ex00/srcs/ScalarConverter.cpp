/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:33:49 by nbonnet           #+#    #+#             */
/*   Updated: 2025/07/24 14:32:33 by nbonnet          ###   ########.fr       */
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
    if (input.empty()) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    if (input == "nan" || input == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (input == "+inf" || input == "+inff" || input == "inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return;
    }
    if (input == "-inf" || input == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }
    if (input.length() == 1 && !std::isdigit(input[0])) {
        char c = input[0];
        if (std::isprint(c)) {
            std::cout << "char: '" << c << "'" << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
        return;
    }
    
    double value = std::atof(input.c_str());
    if (value == 0.0 && input != "0" && input != "0.0" && input != "0.0f") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    if (value == static_cast<int>(value) && value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max()) {
        char c = static_cast<char>(value);
        if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;
    if (value == static_cast<int>(value) && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    if (value >= -std::numeric_limits<float>::max() && value <= std::numeric_limits<float>::max())
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    else
        std::cout << "float: impossible" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}