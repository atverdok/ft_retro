/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:30:14 by oshudria          #+#    #+#             */
/*   Updated: 2017/11/04 12:31:44 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.hpp"
#include <string>

Window::Window() : _player(vec2si(10, 10))
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
}

Window::~Window()
{
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

	bool exit_requested = false;
	int in_char;

    while(1) {
        in_char = wgetch(_window);

        mvaddch(_player.getY(), _player.getX(), ' ');

        attron(A_BOLD);
    	box(_window, 0, 0);
    	attroff(A_BOLD);

        mvprintw(0, (COLS / 2), " X=%d Y=%d ", _player.getX(), _player.getY() );
        
        switch(in_char) {
        	case 27: exit_requested = true; break;
            case 'w': _player.setY(_player.getY() - 1); break;
            case 's': _player.setY(_player.getY() + 1); break;
            case 'a': _player.setX(_player.getX() - 1); break;
            case 'd': _player.setX(_player.getX() + 1); break;
            default: break;
        }

        mvaddch(_player.getY(), _player.getX(), _player.getDispChar());

        if(exit_requested) break;
        usleep(10000); // 10 ms

        refresh();
    }

	// std::string text = "Rush00";

	// for (size_t i = 0; i < text.size(); ++i)
	// {
	// 	addch(text[i]);
	// 	addch(' ');
	// }
	// refresh();
	// while (true) ;
}

