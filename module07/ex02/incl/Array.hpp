/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:06:38 by nbonnet           #+#    #+#             */
/*   Updated: 2025/08/22 14:49:58 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <class T>
class Array {
  private:
    T* _data;
    unsigned int _len;
    
  public:
    Array();
    Array(unsigned int n);
    Array(const Array& src);
    Array& operator=(const Array& rhs);
    ~Array();

};

template <class T>
Array<T>::Array() : _data(0), _len(0) {}

template <class T>
Array<T>::Array(unsigned int n) : _data(new T[n]), _len(n) {
	for (int i = 0; i < _len; i++)
		_data[i] = T();
}

template <class T>
Array<T>::Array(const Array& src) {
	_data = new(T[src._data]);
	_len = src._len;
	for (int i = 0; i < src._len; i++)
		_data[i] = src._data[i];
}

template <class T>
Array<T>& Array<T>::operator=(const Array& rhs) {
    if (this != rhs)
    {
    	_len = rhs._len;
        _data = new T[_len];
        for (int i = 0; i < _len; i++)
            _data[i] = rhs._data[i];   
    }
    return *this;
}

template <class T>
Array<T>::~Array() {
    delete[] _data;
}