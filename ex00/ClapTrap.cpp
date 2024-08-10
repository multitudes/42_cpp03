/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:21:58 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/10 12:33:15 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "debug.h"

/**
 * @brief Construct a new Clap Trap:: Clap Trap object
 * 
 * Default constructor
 * @return ClapTrap
 */
ClapTrap::ClapTrap( void ) : name("anon claptrap"), hitPoints(10), energyPoints(10), attackDamage(0) {
	debug("ClapTrap default constructor called");
}

/**
 * @brief Construct a new Clap Trap:: Clap Trap object
 * 
 * @param name 
 * @return ClapTrap
 */
ClapTrap::ClapTrap( std::string const name ) : name(name) ,hitPoints(10), energyPoints(10), attackDamage(0) {
	debug("ClapTrap constructor called");
}

/** 
 * @brief Destroy the Clap Trap:: Clap Trap object
 */
ClapTrap::~ClapTrap ( void ) {
	debug("ClapTrap destructor called");
}

/**
 * @brief Copy Constructor
 * 
 * @param copy
 * Used to create a new object as a copy of an existing object.
 */
ClapTrap::ClapTrap(const ClapTrap& copy) : name(copy.name), hitPoints(copy.hitPoints), energyPoints(copy.energyPoints), attackDamage(copy.attackDamage) {
	debug("ClapTrap copy constructor called");
}

/**
 * @brief Assignment operator
 * 
 * @param assign 
 * @return ClapTrap&
 * Used to assign an existing object to another existing object.
 * For clarity I write everything down but really this is 
 * the default implementation of the assignment operator already and I could just leave it 
 * blank, since I do not have any dynamically allocated memory.
 */
ClapTrap& ClapTrap::operator=(const ClapTrap& assign) {
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &assign) {
		this->name = assign.name;
		this->hitPoints = assign.hitPoints;
		this->energyPoints = assign.energyPoints;
		this->attackDamage = assign.attackDamage;
	}
	return *this;
}

/**
 * @brief ClapTrap::attack
 * 
 * @param target 
 * attack costs 1 energy point
 */
void ClapTrap::attack(const std::string &target) {
	if (this->energyPoints == 0 || this->hitPoints == 0) {
		std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
	} else {
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints -= 1;
	}
}

/**
 * @brief ClapTrap::takeDamage
 * 
 * @param amount 
 * 
 * 
 */
void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints >= amount) {
		this->hitPoints -= amount;
		std::cout << this->name << " takes " << amount << " points of damage!" << std::endl;
	} else {
		this->hitPoints = 0;
		std::cout << this->name << " has no more hitPoints!" << std::endl;
	}
}

/**
 * @brief ClapTrap::beRepaired
 * 
 * @param amount 
 * Here the various cases are handled in which the ClapTrap can be repaired or not.
 * repair costs 1 energy point
 */
void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints == 0) {
		std::cout << this->name << " is out of energy cannot repair!" << std::endl;
	} else {
		std::cout << this->name << " is being repaired for " << amount << " points!" << std::endl;
		this->hitPoints += amount;
		this->energyPoints -= 1;
	}
}
