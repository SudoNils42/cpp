/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:12:33 by nbonnet           #+#    #+#             */
/*   Updated: 2025/05/22 17:44:15 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/replace.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
        return (1);
    Replace file;
    file.setNames(av[1], av[2], av[3]);
    file.process();
    return (0);
}