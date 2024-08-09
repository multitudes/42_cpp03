/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:57:51 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/09 15:53:13 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

/**
 * @brief main function
 */
int main( void )
{
	ScavTrap scavtrap = ScavTrap("scavvy");
	FragTrap fragtrap = FragTrap("fraggy");
	ClapTrap claptrap = ClapTrap("clappy");
	fragtrap.highFivesGuys();
	scavtrap.guardGate();
	claptrap.attack("enemy");
	scavtrap.attack("enemy");
	claptrap.takeDamage(5);
	claptrap.beRepaired(5);
	claptrap.attack("enemy");
	fragtrap.attack("enemy");
	

	return 0;
}
