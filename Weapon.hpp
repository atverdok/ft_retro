/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 10:41:01 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/05 11:39:46 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include "Bullet.hpp"

const int	_maxBull = 100;

class Weapon
{

private:
	int		_indexBull;
	Bullet	_bullArr[_maxBull];
	int		_direction;

public:
	Weapon( void );
	Weapon(int direction);
	Weapon(Weapon const &);
	~Weapon( void );

	Weapon &	operator=(Weapon const &);
	
	Bullet &	getBull( int index );

	void		shut( int x, int y);
	void		updateBullet( void );
};


#endif
