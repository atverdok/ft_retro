/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:24:54 by oshudria          #+#    #+#             */
/*   Updated: 2017/11/05 20:14:43 by oshudria         ###   ########.fr       */
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
		bool	userInput();
		void	printStat();
		void	drawBullet();
		void	killEnemy(int index);
		void	moveEnemy(int index, int count);
		void	_frameWait(void);

	public:
		Window();
		~Window();

		void	gameProcess();
		int		get_numDeadth();
		int		get_time();
};

#endif // WINDOW_HPP
