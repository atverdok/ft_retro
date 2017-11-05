/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:42:52 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/05 11:52:12 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

Bullet::Bullet() : Unit(0, 0, '*'), _isActiv(false) {}

Bullet::Bullet(int x, int y, char c) : Unit(x, y, c), _isActiv(false)
{
}

Bullet::~Bullet() {}

bool    Bullet::isActiv( void )
{
    return _isActiv;
}

void    Bullet::setActiv( bool isActiv) {
    _isActiv = isActiv;
}
