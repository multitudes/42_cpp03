/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:14:41 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/09 17:31:39 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

/*
The Diamond Problem is a common issue that arises in object-oriented 
programming languages that support multiple inheritance. 
It's named after the shape of the class diagram that illustrates 
the problem, which looks like a diamond.
  	A
   / \
  B   C
   \ /
    D

In the diagram above, class D inherits from both B and C.
If B and C have a member function with the same name,
which one does D inherit?
C++ allows multiple inheritance but it has its own way of solving the 
diamond problem: through the use of virtual inheritance. 
By declaring the inheritance from A to B and C as virtual, 
C++ ensures that only one copy of A's members is included in D. 
This means that there's only one possible implementation of the method in D, 
which avoids the ambiguity.
*/

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
		DiamondTrap( void );
		DiamondTrap(std::string const name);
		virtual ~DiamondTrap( void );
		DiamondTrap(const DiamondTrap& copy);
		DiamondTrap &operator=(const DiamondTrap& assign);

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void whoAmI( void );
		
	private:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
};

#endif  // DIAMONDTRAP_HPP_
