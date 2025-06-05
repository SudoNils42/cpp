/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:28:13 by nbonnet           #+#    #+#             */
/*   Updated: 2025/06/05 15:18:05 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class WrongCat : public Animal {
    public:
        WrongCat();
        WrongCat(WrongCat& src);
        WrongCat& operator=(WrongCat& rhs);
        ~WrongCat();
        void makeSound(void) const;
        std::string getType(void) const;
};