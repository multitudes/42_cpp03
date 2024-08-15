/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:57:51 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/15 10:05:17 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
	    // Create a DiamondTrap object
    DiamondTrap original("Original");

    // Create another DiamondTrap object using the copy constructor
    DiamondTrap copy(original);

	copy.whoAmI();
	// DiamondTrap diamondtrap_def; // = DiamondTrap();
	// diamondtrap_def.whoAmI();
	// DiamondTrap diamondtrap = DiamondTrap("diamondtrap");
	// diamondtrap.attack("target");
	// diamondtrap.guardGate();
	// diamondtrap.highFivesGuys();
	// diamondtrap.takeDamage(10);
	// diamondtrap.beRepaired(10);
	// diamondtrap.whoAmI();

	// ScavTrap scavtrap = ScavTrap("scavvy");
	// FragTrap fragtrap = FragTrap("fraggy");
	// ClapTrap claptrap = ClapTrap("clappy");
	// fragtrap.highFivesGuys();
	// scavtrap.guardGate();
	// claptrap.attack("enemy");
	// claptrap.takeDamage(5);
	// ScavTrap anonScavTrap = ScavTrap();
	// anonScavTrap.guardGate();
	// FragTrap anonFragTrap = FragTrap();
	// anonFragTrap.highFivesGuys();
	return 0;
}