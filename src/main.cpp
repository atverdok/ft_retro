/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:27:22 by oshudria          #+#    #+#             */
/*   Updated: 2017/11/04 11:54:34 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <csignal>
#include <iostream>
#include "Window.hpp"

void		handlerResize(int sig)
{
	if ( sig == SIGWINCH)
	{
		endwin();
	    refresh();
	    clear();
	}
}

int	main( void )
{
	Window * window = new Window();
	signal(SIGWINCH, &handlerResize);
	window->gameProcess();
	delete window;
	std::cout << std::endl << "GAME OVER!!!" << std::endl;
	std::cout << "You survived " << (window->get_time() / 60) << " seconds and killed " << window->get_numDeadth() << " enemies!" << std::endl;
	std::cout << std::endl;
	return 0;
}
