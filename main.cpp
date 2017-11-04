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
	Window	window;
	signal(SIGWINCH, &handlerResize);
	window.gameProcess();
	return 0;
}
