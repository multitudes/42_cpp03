/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:14:26 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/15 10:03:08 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/**
 * @brief Default Constructor
 */
FragTrap::FragTrap( void ) : ClapTrap("anonymous_fragtrap"), hitPoints(100), energyPoints(100), attackDamage(30) {
	std::cout << "FragTrap default constructor called" << std::endl;
	std::cout << "FragTrap " << this->name << " has " << this->hitPoints << " hitPoints, " << this->energyPoints << " energy points and " << this->attackDamage << " attack damage" << std::endl;
}

/**
 * @brief Constructor with name
 * 
 * Using an initiaization list to call the ClapTrap constructor is better, but also it is in this case
 * necessary to declare the member variables like hitPoints energyPoints and attackDamage in the ScavTrap and FrgTrap classes
 * because the DiamondTrap will inherit them.
 */
FragTrap::FragTrap( std::string const name ) : ClapTrap(name), hitPoints(100), energyPoints(100), attackDamage(30) {
		std::cout << "FragTrap constructor called" << std::endl;
		std::cout << "FragTrap " << this->name << " has " << this->hitPoints << " hitPoints, " << this->energyPoints << " energy points and " << this->attackDamage << " attack damage" << std::endl;
}

/**
 * @brief Destructor
 */
FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap destructor called" << std::endl;
}

/**
 * @brief Copy Constructor
 */
FragTrap::FragTrap( const FragTrap& copy ) : ClapTrap(copy), hitPoints(copy.hitPoints), energyPoints(copy.energyPoints), attackDamage(copy.attackDamage) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

/** 
 * @brief Assignment operator
 */
FragTrap &FragTrap::operator=( const FragTrap& assign ) {
	std::cout << "FragTrap assign operator called" << std::endl;
	if (this != &assign) {
		this->name = assign.name;
		this->hitPoints = assign.hitPoints;
		this->energyPoints = assign.energyPoints;
		this->attackDamage = assign.attackDamage;
	}
	return *this;
}

/**
 * @brief Member function
 * 
 * This function will print a message and is specific to the FragTrap class
 */
void FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << this->name << " says: High five guys!" << std::endl;
}

/**
 * @brief attack function
 * 
 * This function is overridden from the ClapTrap class and will print a different message
 */
void FragTrap::attack( const std::string &target) {
	if (this->energyPoints == 0 || this->hitPoints == 0) {
		std::cout << "FragTrap " << this->name << " is out of energy!" << std::endl;
	} else {
		std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints -= 1;
	}
}

/**
 * @brief takeDamage function
 */
void FragTrap::takeDamage( unsigned int amount ) {
	if (this->hitPoints >= amount) {
		this->hitPoints -= amount;
		std::cout << "FragTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	} else {
		this->hitPoints = 0;
		std::cout << "FragTrap " << this->name << " has no more hitPoints!" << std::endl;
	}
}

/**
 * @brief beRepaired function
 */
void FragTrap::beRepaired( unsigned int amount ) {
	if (this->energyPoints == 0) {
		std::cout << "FragTrap " << this->name << " is out of energy!" << std::endl;
	} else {
		std::cout << "FragTrap " << this->name << " is being repaired for " << amount << " points!" << std::endl;
		this->hitPoints += amount;
		this->energyPoints -= 1;
	}
}