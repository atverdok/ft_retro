/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:08:02 by oshudria          #+#    #+#             */
/*   Updated: 2017/11/04 19:48:47 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "Unit.hpp"

class Enemy : public Unit
{
	protected:
		Enemy();
	public:
		Enemy(int x, int y);
		Enemy(Enemy const & src);
		~Enemy();

		Enemy & operator=(Enemy const & hrs);
};

#endif // ENEMY_HPP
