/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:14:26 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/09 17:11:20 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "debug.h"

/**
 * @brief Construct a new Frag Trap:: Frag Trap object
 * 
 * Default constructor
 */
FragTrap::FragTrap( void ) : ClapTrap("fragtrap") {
	debug("FragTrap default constructor called");
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

/**
 * @brief Construct a new Frag Trap:: Frag Trap object
 * 
 * @param name 
 */
FragTrap::FragTrap( std::string const name ) : ClapTrap(name) {
	debug("FragTrap constructor called");
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

/**
 * @brief Destroy the Frag Trap:: Frag Trap object
 */
FragTrap::~FragTrap( void ) {
	debug("FragTrap destructor called");
}

/**
 * @brief Copy Constructor
 * 
 * @param copy
 * Used to create a new object as a copy of an existing object.
 */
FragTrap::FragTrap( const FragTrap& copy ) {
	debug("FragTrap copy constructor called");
	*this = copy;
}

/**
 * @brief Assignment operator
 * 
 * @param assign 
 * @return FragTrap&
 */
FragTrap& FragTrap::operator=( const FragTrap& assign ) {
	debug("FragTrap assignation operator called");
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
 */
void FragTrap::attack(const std::string &target) {
	if (this->energyPoints == 0 || this->hitPoints == 0) {
		std::cout << "FragTrap " << this->name << " is out of energy!" << std::endl;
	} else {
	std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints -= 1;
	}
}

/**
 * @brief FragTrap specific member function
 */
void FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << this->name << " says: High five guys!" << std::endl;
}