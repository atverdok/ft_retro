/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:18:59 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/05 11:58:14 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "Unit.hpp"
#include "Weapon.hpp"

class Player : public Unit
{

	private:
		Weapon	_weapon;

	public:
		Player();
		Player(int verticalPos);
		Player(Player const & src);
		~Player();

		Player & operator=(Player const & hrs);

		Weapon & getWeapon();
};

#endif
