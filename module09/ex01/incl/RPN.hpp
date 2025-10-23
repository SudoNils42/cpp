/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:11:04 by nbonnet           #+#    #+#             */
/*   Updated: 2025/10/23 14:41:23 by nbonnet          ###   ########.fr       */
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

template <typename T>
void calculation(std::string input) {
    std::deque<int> stack;
    int i = 0;
    int last = 0;
    int penultimate = 0;
    
    while (input[i])
    {
        if (std::isdigit(input[i]))
            stack.push_back(input[i] - '0');
        else if (input[i] == '+')
        {
            last = stack.back();
            stack.pop_back();
            penultimate = stack.back();
            stack.pop_back();
            stack.push_back(penultimate + last);
        }
        else if (input[i] == '-')
        {
            last = stack.back();
            stack.pop_back();
            penultimate = stack.back();
            stack.pop_back();
            stack.push_back(penultimate - last);
        }
        else if (input[i] == '/')
        {
            last = stack.back();
            stack.pop_back();
            penultimate = stack.back();
            stack.pop_back();
            stack.push_back(penultimate / last);
        }
        else if (input[i] == '*')
        {
            last = stack.back();
            stack.pop_back();
            penultimate = stack.back();
            stack.pop_back();
            stack.push_back(penultimate * last);
        }
        i++;
    }
    std::cout << stack.back() << std::endl;
}