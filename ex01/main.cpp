/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:57:51 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/09 16:54:42 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

/**
 * 
 * @brief main function
 * 
 * NB:
 * Constructor Order
 * The base class constructor is always called before the derived class constructor.
 * This order ensures that the base class is fully initialized before the derived class 
 * starts its construction. This is crucial because the derived class often relies on the base class's members and functions.
 * 
 * Destructor Order - Destructors are called in the reverse order of constructors.
 * This means the derived class destructor is called first, followed by the base class destructor. 
 * This order is necessary for proper cleanup. The derived class might need to use base class members during its destruction, 
 * so it makes sense to destroy the derived class first.
 * Why This Order? 
 * Constructors: Building an object is like assembling a building. 
 * You start with the foundation (base class) and then add the upper floors (derived class).
 * Destructors: Destroying an object is like dismantling a building. 
 * You start from the top (derived class) and work your way down to the foundation (base class).
 */
int main( void )
{
	ScavTrap scavtrap = ScavTrap();
	ClapTrap claptrap = ClapTrap("claptrap");

	scavtrap.guardGate();
	claptrap.attack("scavTrap");
	claptrap.attack("scavTrap");	
	claptrap.attack("scavTrap");	
	claptrap.attack("scavTrap");	
	claptrap.attack("scavTrap");	
	claptrap.attack("scavTrap");	
	claptrap.attack("scavTrap");	
	claptrap.attack("scavTrap");	
	claptrap.attack("scavTrap");	
	claptrap.attack("scavTrap"); 	
	claptrap.attack("scavTrap");

	scavtrap.attack("claptrap");

	claptrap.takeDamage(20);
	claptrap.beRepaired(10);
	
	scavtrap.beRepaired(10);
	scavtrap.takeDamage(120);
	scavtrap.takeDamage(120);
	scavtrap.beRepaired(120);
	
	return 0;
}
