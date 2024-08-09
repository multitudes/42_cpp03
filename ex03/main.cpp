/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:57:51 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/09 17:51:52 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
	DiamondTrap diamondtrap_def; // = DiamondTrap();
	diamondtrap_def.whoAmI();
	DiamondTrap diamondtrap = DiamondTrap("diamondtrap");
	diamondtrap.attack("target");
	diamondtrap.guardGate();
	diamondtrap.highFivesGuys();
	diamondtrap.takeDamage(10);
	diamondtrap.beRepaired(10);
	diamondtrap.whoAmI();
	return 0;
}