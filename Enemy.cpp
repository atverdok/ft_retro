/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:11:46 by oshudria          #+#    #+#             */
/*   Updated: 2017/11/04 19:49:32 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy() : Unit(0, 0, '@')
{
	_currentHP = 1;
	_maximumHP = 3;
}

Enemy::Enemy(int x, int y) : Unit(x, y, '@')
{
	_currentHP = 1;
	_maximumHP = 3;
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
}

Enemy::~Enemy()
{
}

Enemy & Enemy::operator=(Enemy const & rhs)
{
	if (this != &rhs)
	{
		_posX = rhs.getX();
		_posY = rhs.getY();
		_level = rhs.getLevel();
		_view = rhs.getView();
	}
	return *this;
}
