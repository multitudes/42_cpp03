/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:20:03 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/09 16:45:12 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

/**
 * @brief ClapTrap class
 */
class ClapTrap {
	public:
		ClapTrap( void );
		ClapTrap(std::string const name);
		~ClapTrap( void );
		ClapTrap(const ClapTrap& copy);
		ClapTrap &operator=(const ClapTrap& assign);

		// member functions
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
	private:
		std::string name;
		unsigned int hitpoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
};

#endif  // CLAPTRAP_HPP_
