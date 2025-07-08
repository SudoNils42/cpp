/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:33:49 by nbonnet           #+#    #+#             */
/*   Updated: 2025/07/08 16:39:10 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(char* input) : _input(input) {
    std::cout << "[ScalarConverter] constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src) : _input(src._input) {
    std::cout << "[ScalarConverter] copy constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
    std::cout << "[ScalarConverter] operator= called" << std::endl;
    if (this != &rhs)
        _input = rhs._input;
    return *this;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "[ScalarConverter] destructor called" << std::endl;
}

std::string ScalarConverter::getInput() const {
    return _input;
}

char ScalarConverter::toChar() {
    char c;
    c = static_cast<char>(_input[0]);
    return c;
}

// int ScalarConverter::toInt(std::string input) {
//     int i;
//     i = static_cast<int>(_input);
//     return i;
// }