/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:41:11 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/09 17:30:56 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

/*

create a derived robot.
It will be named ScavTrap and will inherit the constructors and destructor from ClapTrap. 
However, its constructors, destructor and attack() will print different messages. 
After all, ClapTraps are aware of their individuality.
*/

class ScavTrap : virtual public ClapTrap {
	public :
		ScavTrap( void );
		ScavTrap( std::string const name);
		virtual ~ScavTrap( void );
		ScavTrap(const ScavTrap& copy);
		ScavTrap &operator=(const ScavTrap& assign);
		
		// member functions specific to ScavTrap
		void guardGate( void );
		// inherited:
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
	protected:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
};  


#endif  // SCAVTRAP_HPP_
