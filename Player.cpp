/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:23:24 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/04 13:23:33 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Player.hpp"

vec2si::vec2si() : x(10), y(10) {}

vec2si::vec2si( short int x, short int y )
{
	this->x = x;
	this->y = y;
}


Player::Player( vec2si pos ) : _pos(pos), _disp_char('0'), _level(1) { }

Player::Player( void ) { }

Player::Player(Player const & src)
{
	*this = src;
}

Player & Player::operator=(Player const & rhs)
{
	return *this;
}

Player::~Player( void ) {}

vec2si Player::getPosition( void )
{
	return _pos;
}

char 	Player::getDispChar( void )
{
	return _disp_char;
}

short int	Player::getX()
{
	return _pos.x;
}

short int	Player::getY()
{
	return _pos.y;
}

void 		Player::setX(short int n) 
{
	if (n > 0 && n < (COLS - 1))
		_pos.x = n;
}

void 		Player::setY(short int n)
{
	if (n > 0 && n < (LINES - 1))
		_pos.y = n;
}

