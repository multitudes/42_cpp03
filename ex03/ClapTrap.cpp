/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:21:58 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/15 09:51:09 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/**
 * @brief Default Constructor
 * 
 * By default every claptrap will have 10 hitPoints, 10 energyPoints and 0 attackDamage
 */
ClapTrap::ClapTrap( void ) : name("claptrap"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
	std::cout << "ClapTrap " << this->name << " has " << this->hitPoints << " hitPoints, " << this->energyPoints << " energy points and " << this->attackDamage << " attack damage" << std::endl;
}

/**
 * @brief Constructor with name
 * 
 * By default every claptrap will have 10 hitPoints, 10 energyPoints and 0 attackDamage
 */
ClapTrap::ClapTrap( std::string const name ) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap constructor called" << std::endl;
	std::cout << "ClapTrap " << this->name << " has " << this->hitPoints << " hitPoints, " << this->energyPoints << " energy points and " << this->attackDamage << " attack damage" << std::endl;
}

/**
 * @brief Destructor
 * 
 * Destroy the ClapTrap object
 */
ClapTrap::~ClapTrap ( void ) {
	std::cout << "ClapTrap destructor called" << std::endl;
}

/**
 * @brief Copy Constructor
 * 
 * Copy the ClapTrap object
 */
ClapTrap::ClapTrap(const ClapTrap& copy) : name(copy.name), hitPoints(copy.hitPoints), energyPoints(copy.energyPoints), attackDamage(copy.attackDamage) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

/**
 * @brief Assignment operator
 * 
 * Assign the ClapTrap object
 */
ClapTrap &ClapTrap::operator=(const ClapTrap& assign) {
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &assign) {
		this->name = assign.name;
		this->hitPoints = assign.hitPoints;
		this->energyPoints = assign.energyPoints;
		this->attackDamage = assign.attackDamage;
	}
	return *this;
}

/**
 * @brief Attack function
 * 
 * If the ClapTrap has no energyPoints or hitPoints, it will not be able to attack
 * If the ClapTrap has energyPoints, it will attack the target and decrease the energyPoints by 1
 * 
 * @param target The target to attack
 * 
 * This function will be overridden in the derived classes
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
 * @brief Take Damage function
 * 
 * If the ClapTrap has hitPoints greater than the amount of damage, it will take the damage
 * If the ClapTrap has hitPoints less than the amount of damage, it will have no more hitPoints
 * 
 * @param amount The amount of damage to take
 */
void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints >= amount) {
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	} else {
		this->hitPoints = 0;
		std::cout << "ClapTrap " << this->name << " has no more hitPoints!" << std::endl;
	}
}

/**
 * @brief Be Repaired function
 * 
 * If the ClapTrap has no energyPoints, it will not be able to be repaired
 * If the ClapTrap has hitPoints, it will be repaired for the amount of points
 * If the ClapTrap has full hitPoints, it will not be able to be repaired
 * If the ClapTrap is repaired for more than 10 hitPoints, it will not be able to be repaired
 * 
 * @param amount The amount of hitPoints to repair
 */
void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints == 0) {
		std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
	} else if (this->hitPoints == 0) {
		std::cout << "ClapTrap " << this->name << " has no more hitPoints!" << std::endl;
	} else if (this->hitPoints + amount < 10) {
		std::cout << "ClapTrap " << this->name << " is being repaired for " << amount << " points!" << std::endl;
		this->hitPoints += amount;
		this->energyPoints -= 1;
	} else if (this->hitPoints + amount == 10) {
		std::cout << "ClapTrap " << this->name << " has full hitPoints!" << std::endl;
		this->hitPoints = 10;
		this->energyPoints -= 1;
	} else if (this->hitPoints + amount > 10) {
		std::cout << "ClapTrap " << this->name << " cannot be repaired for more than 10 hitPoints!" << std::endl;
	}
}