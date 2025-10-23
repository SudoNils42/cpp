/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:11:04 by nbonnet           #+#    #+#             */
/*   Updated: 2025/10/23 13:39:37 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <deque>
#include <string>
#include <iostream>
#include <stdexcept>


class RPN {
    private:
        std::string _input;

    public:
        RPN();
        RPN(const RPN &src);
        RPN& operator=(const RPN &rhs);
        ~RPN();

        void parse_input(std::string input);
        
    
};