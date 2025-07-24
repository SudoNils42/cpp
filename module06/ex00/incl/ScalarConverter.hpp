/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:33:35 by nbonnet           #+#    #+#             */
/*   Updated: 2025/07/24 14:29:53 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& src);
        ScalarConverter& operator=(const ScalarConverter& rhs);
        ~ScalarConverter();
        
    public:   
        static void convert(std::string input);
};