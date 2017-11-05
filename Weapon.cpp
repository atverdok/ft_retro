/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:04:23 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/05 12:13:12 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Weapon.hpp"
#include <ncurses.h>

Weapon::Weapon(int direction) : _direction(direction), _indexBull(0) { }

Weapon::Weapon( void ) : _indexBull(0), _direction(0) {}


void	Weapon::shut(int x, int y)
{
	if (_indexBull < _maxBull)
	{
		_bullArr[_indexBull].setActiv(true);
		_bullArr[_indexBull].setPosition(x + 1 * _direction, y);
		++_indexBull;
	}
}

void	Weapon::updateBullet( void )
{
	for (int i = 0; i < _maxBull; i++)
	{
		if (_bullArr[i].isActiv())
		{
			_bullArr[i].setX(_bullArr[i].getX() + _direction);
			if (_bullArr[i].getX() < 1 || _bullArr[i].getX()  > (COLS - 1 ))
				_bullArr[i].setActiv(false);
		}
	}
}

Weapon::~Weapon( void ) {}

Bullet	& Weapon::getBull( int index )
{
	return _bullArr[index];
}










