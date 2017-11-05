/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:23:24 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/05 12:01:00 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player() : Unit(0, 0, '>'), _weapon(1)
{
	_currentHP = 3;
	_maximumHP = 3;
}

Player::Player(int verticalPos) : Unit(1, verticalPos, '>'), _weapon(1)
{
	_currentHP = 3;
	_maximumHP = 3;
}

Player::Player(Player const & src)
{
	*this = src;
}

Player::~Player()
{
}

Player & Player::operator=(Player const & rhs)
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

Weapon & Player::getWeapon( void )
{
	return _weapon;
}


