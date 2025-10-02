/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:09:28 by nbonnet           #+#    #+#             */
/*   Updated: 2025/10/02 18:19:33 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/BitcoinExchange.hpp"

bool is_valid_format(std::string line) {
    int i = 0;
    int year;
    int month;
    int day;
    while (i < 4)
    {
        if (!isdigit(line[i]))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            return false;
        }
        i++;
    }
    year = atoi((line.substr(0, 4)).c_str());
    if (line[i] != '-')
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return false;
    }
    i++;
    while (i < 7)
    {
        if (!isdigit(line[i]))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            return false;
        }
        i++;
    }
    month = atoi((line.substr(5, 7)).c_str());
    if (line[i] != '-')
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return false;
    }
    i++;
    while (i < 10)
    {
        if (!isdigit(line[i]))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            return false;
        }
        i++;
    }
    day = atoi((line.substr(8, 10)).c_str());
    if (line[i] != ' ' || line[i + 1] != '|' || line[i + 2] != ' ')
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return false;
    }
    i += 2;
    double value;
    value = std::atof((line.substr(i ,line.size() - i).c_str()));
    if (value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 2147483647)
    {
        std::cout << "Error: too large number." << std::endl;
        return false;
    }
    else if (value > 1000)
    {
        std::cout << "Error: value too high." << std::endl;
        return false;
    }
    std::cout << year << "-" << month << "-" << day << " => " << value << " = " << std::endl;
    return true;
}


int main (int ac, char **av) {
    if (ac != 2)
    {
        std::cout << "Error: need one argument" << std::endl;
        return 1;
    }
    std::ifstream file;
    file.open (av[1]);
    if (!file.is_open())
    {
        std::cout << "Error: can't open file '" << av[1] << "'" << std::endl;
        return 1;
    }
    std::string line;
    while (getline(file, line))
        is_valid_format(line); 
    return 0;
}