/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:24:54 by oshudria          #+#    #+#             */
/*   Updated: 2017/11/04 21:07:07 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
# define WINDOW_HPP

#include <ncurses.h>
#include "Player.hpp"
#include "Enemy.hpp"

const int	numEnemies = 60;

class Window
{
	private:
		WINDOW	*_window;
		Player	_player;
		Enemy	*_enemies[numEnemies];

	private:
		Window(Window const & src);
		Window & operator=(Window const & rhs);

		void	createEnemies();

	public:
		Window();
		~Window();

		void	gameProcess();
};

#endif // WINDOW_HPP
