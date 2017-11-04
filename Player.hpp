/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:18:59 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/04 13:19:06 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <ncurses.h>

struct vec2si
{
	short int x;
	short int y;

	vec2si();
	vec2si( short int x, short int y );
	
};

class Player
{

private:

	vec2si		_pos;
	char		_disp_char;
	short int	_level;

public:
	Player( void );
	Player( vec2si pos );
	Player( Player const & );
	~Player( void );

	Player & operator=(Player const & );

	vec2si getPosition( void );
	char 	getDispChar( void );
	short int	getX();
	short int	getY();
	void 		setX(short int);
	void		setY(short int);


	
};

#endif