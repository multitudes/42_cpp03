/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:14:11 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/15 10:11:59 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

/**
 * @brief Create a derived robot.
 * It will be named FragTrap and will inherit the constructors and destructor from ClapTrap. 
 * However, its constructors, destructor and attack() will print different messages. 
 * After all, ClapTraps are aware of their individuality.
 * Since the DiamondTrap will inherit from both ScavTrap and FragTrap, the member variables hitPoints, energyPoints and attackDamage
 * have to be declared in the FragTrap class. But the name will be inherited from the ClapTrap class.
 * The important thing is that the FragTrap class is a virtual class, so that the DiamondTrap class can inherit
 * from both the ScavTrap and FragTrap classes without having multiple instances of the ClapTrap class.
 */
class FragTrap : virtual public ClapTrap {
	public:
		FragTrap( void );
		FragTrap(std::string const name);
		virtual ~FragTrap( void );
		FragTrap(const FragTrap& copy);
		FragTrap &operator=(const FragTrap& assign);

		// member functions
		void highFivesGuys(void);
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
};

#endif  // FRAGTRAP_HPP_
