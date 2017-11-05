/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:36:24 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/05 11:51:24 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BULLET_HPP
# define BULLET_HPP

# include "Unit.hpp"

class	Bullet : public Unit {

private:
	bool _isActiv;

public:
	
	Bullet( void );
	Bullet(int x, int y, char c);
	~Bullet( void );

	bool	isActiv( void );
	void	setActiv(bool);

};

#endif
