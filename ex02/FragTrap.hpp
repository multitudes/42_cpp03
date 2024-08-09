/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:14:11 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/09 17:06:37 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap( void );
		FragTrap(std::string const name);
		~FragTrap( void );
		FragTrap(const FragTrap& copy);
		FragTrap &operator=(const FragTrap& assign);

		// member functions
		void highFivesGuys(void);
		//inherited:
		void attack(const std::string &target);
};

#endif  // FRAGTRAP_HPP_
