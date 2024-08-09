/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:41:00 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/09 17:07:50 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "debug.h"

/**
 * @brief Construct a new Scav Trap:: Scav Trap object
 * 
 * In cpp98 I cannot initialize the inherited properties in same row as the class name.
 * I need to do it in the constructor.
 */
ScavTrap::ScavTrap( void ) : ClapTrap("anon scavtrap") {
	debug("Anon ScavTrap default constructor called");
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

/**
 * @brief Construct a new Scav Trap:: Scav Trap object
 * 
 * @param name 
 */
ScavTrap::ScavTrap( std::string const name ): ClapTrap(name) {
	debug("ScavTrap constructor called");
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

/**
 * @brief Destroy the Scav Trap:: Scav Trap object
 */
ScavTrap::~ScavTrap( void ) {
	debug("ScavTrap destructor called");
}

/**
 * @brief Copy Constructor
 * 
 * @param copy
 * Used to create a new object as a copy of an existing object.
 */
ScavTrap::ScavTrap(const ScavTrap& copy) {
	debug("ScavTrap copy constructor called");
	*this = copy;
}

/**
 * @brief Assignment operator
 */
ScavTrap& ScavTrap::operator=(const ScavTrap& assign) {
	debug("ScavTrap assignation operator called");
	if (this != &assign) {
		this->name = assign.name;
		this->hitPoints = assign.hitPoints;
		this->energyPoints = assign.energyPoints;
		this->attackDamage = assign.attackDamage;
	}
	return *this;
}

/**
 * @brief member function specific to ScavTrap
 */
void ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap " << this->name << " has entered in Gate keeper mode" << std::endl;
}

/**
 * @brief inherited member function
 * 
 * @param target 
 */
void ScavTrap::attack(const std::string &target) {
	if (this->energyPoints == 0 || this->hitPoints == 0) {
		std::cout << "ScavTrap " << this->name << " is out of energy!" << std::endl;
	} else {
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints -= 1;
	}
}