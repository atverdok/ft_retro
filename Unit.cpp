/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unit.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:10:12 by oshudria          #+#    #+#             */
/*   Updated: 2017/11/05 19:10:33 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Unit.hpp"


Unit::Unit()  
{
}

Unit::Unit(int x, int y, char view) 
	: _posX(x), _posY(y), _level(0), _view(view)
{
}

Unit::Unit(Unit const & src)
{
	*this = src;
}

Unit::~Unit()
{
}

Unit & Unit::operator=(Unit const & rhs)
{
	_posX = rhs.getX();
	_posY = rhs.getY();
	_level = rhs.getLevel();
	_view = rhs.getView();
	return *this;
}

int		Unit::getX() const
{
	return _posX;
}

int 	Unit::getY() const
{
	return _posY;
}

int 	Unit::getLevel() const
{
	return _level;
}

int		Unit::getCHP() const
{
	return _currentHP;
}

int		Unit::getMHP() const
{
	return _maximumHP;
}

char	Unit::getView() const
{
	return _view;
}

void	Unit::setX(int x)
{
	_posX = x;
}

void	Unit::setY(int y)
{
	_posY = y;
}

void	Unit::setCHP(int chp)
{
	if (chp >= 0 && chp <= _maximumHP)
		_currentHP = chp;
}

void	Unit::setPosition(int x, int y)
{
	_posX = x;
	_posY = y;
}

void	Unit::incrX()
{
	++_posX;
}

void	Unit::decrX()
{
	--_posX;
}

void	Unit::incrY()
{
	++_posY;
}

void	Unit::decrY()
{
	--_posY;
}

void	Unit::incrLvl()
{
	++_level;
}

bool	Unit::isLive()
{
	return _currentHP > 0;
}
