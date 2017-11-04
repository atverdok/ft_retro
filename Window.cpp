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
	move(30, 35);

	std::string text = "Rush00";

	for (size_t i = 0; i < text.size(); ++i)
	{
		addch(text[i]);
		addch(' ');
	}
	refresh();
	while (true) ;
}

