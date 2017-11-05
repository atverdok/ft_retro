/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:04:23 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/05 16:58:49 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Weapon.hpp"
#include <ncurses.h>

Weapon::Weapon(int direction) : _indexBull(0), _direction(direction)
{
}	

Weapon::Weapon( void ) : _indexBull(0), _direction(0) {}


void	Weapon::shut(int x, int y)
{
	if (_indexBull < _maxBull)
	{
		++_indexBull;
		for (int i = 0; i < _maxBull; ++i)
		{
			if (!_bullArr[i].isActiv())
			{
				_bullArr[i].setActiv(true);
				_bullArr[i].setPosition(x + 1 * _direction, y);
				break;
			}
		}
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
			{
				_bullArr[i].setActiv(false);
				--_indexBull;
			}
		}
	}
}

Weapon::~Weapon( void ) {}

Bullet	& Weapon::getBull( int index )
{
	return _bullArr[index];
}

int		Weapon::getDirection( void )
{
	return _direction;
}

void	Weapon::minusBull( void )
{
	--_indexBull;
}









