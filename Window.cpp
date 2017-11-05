/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:30:14 by oshudria          #+#    #+#             */
/*   Updated: 2017/11/05 20:29:15 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.hpp"
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

Window::Window() : _numDeadth(0), _time(0)
{
	_window = initscr();
	cbreak();
	noecho();
	keypad(_window, true);
	nodelay(_window, true);
	curs_set(0);
	start_color();
	attron(A_BOLD);
	init_pair(1, COLOR_BLACK, COLOR_YELLOW);
	wbkgd(_window, COLOR_PAIR(1));
	_ticks = std::clock();

	_player = Player(getmaxy(_window) / 2);
	std::srand(std::time(0));

	createEnemies();
}

Window::~Window()
{
	for (int i = 0; i < numEnemies; ++i)
		delete _enemies[i];
   	attroff(A_BOLD);
	endwin();
}

Window::Window(Window const & src)
{
	*this = src;
}

Window & Window::operator=(Window const & rhs)
{
	(void)rhs;
	return *this;
}

void	Window::gameProcess()
{
	int count = 0;
	while(userInput()) // chek key codes
	{
    	box(_window, 0, 0);
		if (_player.isLive())
		{
			printStat();   // statistics on top of Window
			mvaddch(_player.getY(), _player.getX(), _player.getView()); // draw player

			drawBullet();

			for (int i = 0; i < numEnemies; ++i)
			{
				killEnemy(i);
				moveEnemy(i, count);

				if (_player.getX() == _enemies[i]->getX() &&
					_player.getY() == _enemies[i]->getY())
				{
					_player.setCHP(_player.getCHP() - 1);
					_enemies[i]->setX(getmaxx(_window) + 10 + (rand() % 40));
					if (_player.getCHP() == 0)
						break;
				}

			}
			_player.getWeapon().updateBullet();
			_frameWait();
			refresh();
			++count;
		}
		else
		{
			clear();
    		box(_window, 0, 0);
			break;
		}
    }
	while(userInput())
   	{
		printStat();
		mvprintw((COLS / 3), (LINES / 2), "GAME OVER!!!");
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


void Window::_frameWait(void)
{
	time_t now;

	while (1) {
		now = std::clock();
		double t = ((double)(now - _ticks) / CLOCKS_PER_SEC) * 1000;
		if (t >= FPS_DFLT_MSEC)
			break;
		usleep(1);
	};
	_ticks = std::clock();
	_time++;
}

bool	Window::userInput()
{
	int in_char = wgetch(_window);
	
	mvaddch(_player.getY(), _player.getX(), ' ');

	switch(in_char)
	{
		case 27       :  return false;
		case KEY_UP   : _player.decrY(); break;
		case KEY_DOWN : _player.incrY(); break;
		case KEY_LEFT : _player.decrX(); break;
		case KEY_RIGHT: _player.incrX(); break;
		case ' '	  : _player.getWeapon().shut(_player.getX() + 1, _player.getY()); break;
		default: break;
	}

	if (_player.getX() < 1)
		_player.setX(1);
	if (_player.getY() < 1)
		_player.setY(1);
	if (_player.getX() > (COLS - 2))
		_player.setX((COLS - 2));
	if (_player.getY() > (LINES - 2))
		_player.setY((LINES - 2));

	return true;
}

void	Window::printStat()
{
	mvprintw(0, (COLS / 4),
		   	"Current HP: %d | #%d of dead | Time: %d ",
			_player.getCHP(), _numDeadth, _time / FPS );
}

void	Window::drawBullet()
{
	for (int i = 0; i < _maxBull; i++)
	{
		if (_player.getWeapon().getBull(i).isActiv())
		{
			mvaddch(_player.getWeapon().getBull(i).getY(),
					_player.getWeapon().getBull(i).getX(),
					_player.getWeapon().getBull(i).getView());
			mvaddch(_player.getWeapon().getBull(i).getY(),
					_player.getWeapon().getBull(i).getX() - 1 * _player.getWeapon().getDirection(),
					' ');
		}
	}
}

void	Window::killEnemy(int index)
{
	for (int j = 0; j < _maxBull; ++j)
	{
		if (_player.getWeapon().getBull(j).isActiv())
		{
			if (_player.getWeapon().getBull(j).getY() == _enemies[index]->getY()
				&& _player.getWeapon().getBull(j).getX() == _enemies[index]->getX())
			{
				mvaddch(_player.getWeapon().getBull(j).getY(),
						_player.getWeapon().getBull(j).getX(),
						' ');
				_player.getWeapon().getBull(j).setActiv(false);
				_player.getWeapon().minusBull();
				++_numDeadth;
				_enemies[index]->setX(getmaxx(_window) + 10 + (rand() % 40));
			}
		}
	}
}

void	Window::moveEnemy(int index, int count)
{
	if ((count % ((rand() % 9) + 7)) == 0)
	{
		mvaddch(_enemies[index]->getY(), _enemies[index]->getX(), ' ');
		_enemies[index]->decrX();
	}
	if (_enemies[index]->getX() < 1)
		_enemies[index]->setX(getmaxx(_window) + 10 + (rand() % 40));

	mvaddch(_enemies[index]->getY(),
		   	_enemies[index]->getX(),
		   	_enemies[index]->getView());		
}
