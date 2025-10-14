/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:09:28 by nbonnet           #+#    #+#             */
/*   Updated: 2025/10/14 18:54:31 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/BitcoinExchange.hpp"

bool is_valid_format(std::string line, std::map<std::string, double> &input) {
    int i = 0;
    int year = 0;
    int month = 0;
    int day = 0;
    while (i < 4)
    {
        if (!isdigit(line[i]))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            return false;
        }
        i++;
    }
    year = atoi((line.substr(0, 4)).c_str());
    if (line[i] != '-')
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }
    i++;
    while (i < 7)
    {
        if (!isdigit(line[i]))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            return false;
        }
        i++;
    }
    month = atoi((line.substr(5, 2)).c_str());
    if (line[i] != '-')
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }
    i++;
    while (i < 10)
    {
        if (!isdigit(line[i]))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            return false;
        }
        i++;
    }
    day = atoi((line.substr(8, 2)).c_str());
    if (line[i] != ' ' || line[i + 1] != '|' || line[i + 2] != ' ')
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }
    i += 2;
    double value;
    value = std::atof((line.substr(i ,line.size() - i).c_str()));
    i++;
    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 2147483647)
    {
        std::cerr << "Error: too large number." << std::endl;
        return false;
    }
    else if (value > 1000)
    {
        std::cerr << "Error: value too high." << std::endl;
        return false;
    }
    int flag = 0;
    while (line[i] != '\0')
    {   
        if (!isdigit(line[i]) && (line[i] != '.' || flag == 1))
        {
            std::cerr << "Error: bad value." << std::endl;
            return false;
        }
        if (line[i] == '.')
            flag = 1;
        i++;
    }
    if (year < 2009 || year > 2025)
    {
        std::cerr << "Error: bad date." << std::endl;
        return false;
    }
    if (month < 1 || month > 12)
    {
        std::cerr << "Error: bad date." << std::endl;
        return false;
    }
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day < 1 || day > 31)
        {
            std::cerr << "Error: bad date." << std::endl;
            return false;
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day < 1 || day > 30)
        {
            std::cerr << "Error: bad date." << std::endl;
            return false;
        }
    }
    if (month == 2)
    {
        if (year % 4 == 0)
        {
            if (day < 1 || day > 29)
            {
                std::cerr << "Error: bad date." << std::endl;
                return false;
            }

        }
        else if (day < 1 || day > 28)
        {
            std::cerr << "Error: bad date." << std::endl;
            return false;
        }
    }
    std::string date_str = "";
    char buffer[5];
    sprintf(buffer, "%d", year);
    date_str += buffer;
    date_str += "-";
    memset(buffer, 0, sizeof(buffer));
    if (month < 10) date_str += "0";
    sprintf(buffer, "%d", month);
    date_str += buffer;
    date_str += "-";
    memset(buffer, 0, sizeof(buffer));
    if (day < 10) date_str += "0";
    sprintf(buffer, "%d", day);
    date_str += buffer;
    input[date_str] = value;
    return true;
}

bool data_to_map(std::map<std::string, double>  &data) {
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cerr << "Error: can't open data.csv" << std::endl;
        return false;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::string date = line.substr(0, 10);
        double rate = std::atof(line.substr(11).c_str());
        data[date] = rate;
    }
    return true;
}

void result(const std::string& date, double value, const std::map<std::string, double>& data) {
    std::map<std::string, double>::const_iterator data_it = data.lower_bound(date);
    if (data_it != data.end() && data_it->first != date)
    data_it--;
    double final_result = value * data_it->second;
    std::cout << date << " => " << value << " = " << final_result << std::endl;
}

int main (int ac, char **av) {
    if (ac != 2)
    {
        std::cerr << "Error: need one argument" << std::endl;
        return 1;
    }
    std::ifstream file;
    file.open (av[1]);
    if (!file.is_open())
    {
        std::cerr << "Error: can't open file '" << av[1] << "'" << std::endl;
        return 1;
    }
    std::string line;
    std::map<std::string, double> input;
    std::map<std::string, double> data;
    data_to_map(data);
    while (getline(file, line))
    {
        if (is_valid_format(line, input))
        {
            std::map<std::string, double>::iterator input_it = input.end();
            input_it--;
            result(input_it->first, input_it->second, data);
        }
    }
    return 0;
}