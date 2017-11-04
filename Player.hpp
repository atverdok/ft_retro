/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:18:59 by atverdok          #+#    #+#             */
/*   Updated: 2017/11/04 19:32:10 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "Unit.hpp"

class Player : public Unit
{
	public:
		Player();
		Player(int verticalPos);
		Player(Player const & src);
		~Player();

		Player & operator=(Player const & hrs);
};

#endif
