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
#include <ctime>
#include "Player.hpp"
#include "Enemy.hpp"

#define FPS 60
#define FPS_DFLT_SEC (1. / FPS)
#define FPS_DFLT_MSEC (FPS_DFLT_SEC * 1000)

const int	numEnemies = 60;

class Window
{
	private:
		WINDOW	*_window;
		Player	_player;
		Enemy	*_enemies[numEnemies];
		int		_numDeadth;
		time_t	_ticks;
		int		_time;

	private:
		Window(Window const & src);
		Window & operator=(Window const & rhs);

		void	createEnemies();

	public:
		Window();
		~Window();

		void	gameProcess();
		void	_frameWait(void);
};

#endif // WINDOW_HPP
