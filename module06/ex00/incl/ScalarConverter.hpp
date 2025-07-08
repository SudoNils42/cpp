/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:33:35 by nbonnet           #+#    #+#             */
/*   Updated: 2025/07/08 15:57:59 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class ScalarConverter {
    private:   
        char* _input;

    public:
        ScalarConverter(char* input);
        ScalarConverter(const ScalarConverter& src);
        ScalarConverter& operator=(const ScalarConverter& rhs);
        ~ScalarConverter();
        
        std::string getInput() const;
        char toChar();
        // int toInt(char* input);
        // int toFloat(char* input);
        // int toDouble(char* input);
};