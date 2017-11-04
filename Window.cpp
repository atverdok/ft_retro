/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:30:14 by oshudria          #+#    #+#             */
/*   Updated: 2017/11/04 21:48:08 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.hpp"
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

Window::Window()  
{
	_window = initscr();
	cbreak();
	noecho();
	keypad(_window, true);
	nodelay(_window, true);
	curs_set(0);
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_YELLOW);
	wbkgd(_window, COLOR_PAIR(1));

	_player = Player(getmaxy(_window) / 2);
	std::srand(std::time(0));

	createEnemies();
}

Window::~Window()
{
	for (int i = 0; i < numEnemies; ++i)
		delete _enemies[i];
	endwin();
}

Window::Window(Window const & src)
{
	*this = src;
}

Window & Window::operator=(Window const & rhs)
{
	return *this;
}


void Window::gameProcess()
{
	bool	exit_requested = false;
	int in_char;

	int count = 0;
    while(!exit_requested) {
        in_char = wgetch(_window);

        mvaddch(_player.getY(), _player.getX(), ' ');

        attron(A_BOLD);
    	box(_window, 0, 0);
    	attroff(A_BOLD);

        mvprintw(0, (COLS / 2), " X=%d Y=%d ", _player.getX(), _player.getY() );
        
        switch(in_char) {
        	case 27       :  exit_requested = true; break;
            case KEY_UP   : _player.decrY(); break;
            case KEY_DOWN : _player.incrY(); break;
            case KEY_LEFT : _player.decrX(); break;
            case KEY_RIGHT: _player.incrX(); break;
            default: break;
        }
	
        mvaddch(_player.getY(), _player.getX(), _player.getView());
		for (int i = 0; i < numEnemies; ++i)
		{
        	mvaddch(_enemies[i]->getY(),
				   	_enemies[i]->getX(),
				   	_enemies[i]->getView());
		
		

			if ((count % ((rand() % 9) + 7)) == 0)
			{
				mvaddch(_enemies[i]->getY(), _enemies[i]->getX(), ' ');
				_enemies[i]->decrX();
			}

			if (_enemies[i]->getX() < 0)
				_enemies[i]->setX(getmaxx(_window) + 10);
			if (_player.getX() == _enemies[i]->getX() &&
				_player.getY() == _enemies[i]->getY())
			{
				_enemies[i]->setX(60);
				mvaddch(_enemies[i]->getY(), _enemies[i]->getX(), '+');

			}

		}
        usleep(10000); // 10 ms

        refresh();
		++count;
    }
}

void	Window::createEnemies()
{
	for (int i = 0; i < numEnemies; ++i)
	{
		int	tmp, y = 0;
		while ((tmp = (rand() % (getmaxy(_window) - 2)) + 1) == y)
			;
		y = tmp;
		_enemies[i] = new Enemy(getmaxx(_window) + 10 + (rand() % 40), y);
	}
}
