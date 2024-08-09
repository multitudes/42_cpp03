/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:41:11 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/09 16:55:33 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

/**
 * @brief ScavTrap class
 * 
 * Derived class from ClapTrap
 * create a derived robot. 
 * It will be named ScavTrap and will inherit the constructors and destructor from ClapTrap. 
 * Its constructors, destructor and attack() will print different messages. 
 * After all, ClapTraps are aware of their individuality.
 */
class ScavTrap : public ClapTrap {
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
};  


#endif  // SCAVTRAP_HPP_
