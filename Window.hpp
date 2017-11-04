/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:24:54 by oshudria          #+#    #+#             */
/*   Updated: 2017/11/04 12:16:31 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
# define WINDOW_HPP

#include <ncurses.h>

class Window
{
	private:
		WINDOW	*_window;

	private:
		Window(Window const & src);
		Window & operator=(Window const & rhs);

	public:
		Window();
		~Window();

		void	gameProcess();
};

#endif
