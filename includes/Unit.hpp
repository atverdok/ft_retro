/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unit.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:05:28 by oshudria          #+#    #+#             */
/*   Updated: 2017/11/05 19:10:00 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_HPP
# define UNIT_HPP

class Unit
{
	protected:
		int		_posX;
		int		_posY;
		int		_level;
		int		_currentHP;
		int		_maximumHP;
		char	_view;

	protected:
		Unit();

	public:
		Unit(int x, int y, char view);
		Unit(Unit const & src);
		virtual ~Unit();

		Unit & operator=(Unit const & hrc);

		int		getX()		const;
		int		getY()		const;
		int		getLevel()	const;
		int		getCHP()	const;
		int		getMHP()	const;
		char	getView()	const;

		void	setX(int x);
		void	setY(int y);
		void	setCHP(int chp);
		void	setPosition(int x, int y);

		void	incrX();
		void	decrX();
		void	incrY();
	   	void	decrY();
		void	incrLvl();
		bool	isLive();
};

#endif // UNIT_HPP
