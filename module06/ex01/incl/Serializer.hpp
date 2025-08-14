/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:56:42 by nbonnet           #+#    #+#             */
/*   Updated: 2025/08/11 15:00:28 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer& src);
        Serializer& operator=(const Serializer& rhs);
        ~Serializer();
    public:
        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
};