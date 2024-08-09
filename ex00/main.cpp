/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:14:34 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/09 16:50:35 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{

	ClapTrap clappy = ClapTrap("clappy");
	ClapTrap clappy2 = ClapTrap("clappy2");

	clappy.attack("clappy2");
	clappy2.takeDamage(0);
	clappy2.beRepaired(10);

	// ClapTrap claptrap = ClapTrap("claptrap");
	// ClapTrap claptrap2 = ClapTrap("claptrap2");

	// std::cout << "Claptrap: " << &claptrap << std::endl;
	// std::cout << "Claptrap2: " << &claptrap2 << std::endl;

	// // copy constructor
	// ClapTrap claptrap3 = claptrap;
	// std::cout << "Claptrap3: " << &claptrap3 << std::endl;

	// // assignment operator
	// claptrap2 = claptrap;
	// std::cout << "Claptrap2: " << &claptrap2 << std::endl;
	
	// // void* ptr = &claptrap;
	// // std::cout << "Pointer value: " << static_cast<void*>(ptr) << std::endl;
	
	// claptrap.attack("claptrap2");
	// claptrap.attack("claptrap2");
	// claptrap.attack("claptrap2");
	// claptrap.attack("claptrap2");
	// claptrap.attack("claptrap2");
	// claptrap.attack("claptrap2");
	// claptrap.attack("claptrap2");
	// claptrap.attack("claptrap2");
	// claptrap.attack("claptrap2");
	// claptrap.attack("claptrap2");
	
	// claptrap.attack("claptrap2"); // out of energy!
	// claptrap2.takeDamage(0); // no damage!

	// // recharge but cannot because no energy points
	// claptrap.beRepaired(10);

	// claptrap2.beRepaired(10); // too many hitpoints already
	// claptrap2.attack("claptrap"); 
	// claptrap2.takeDamage(9);
	// claptrap2.beRepaired(9);
	

	return 0;
}
