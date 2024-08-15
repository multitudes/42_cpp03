/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:15:21 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/15 10:06:16 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/**
 * @brief Default Constructor
 */
DiamondTrap::DiamondTrap( void ): ClapTrap("anon_DiamondTrap_clap_name"), ScavTrap(), FragTrap() {
	this->name = "anon_DiamondTrap";
	std::cout << "DiamondTrap default constructor called" << std::endl;
	std::cout << "DiamondTrap " << this->name << " has " << FragTrap::hitPoints << " hitPoints, " << ScavTrap::energyPoints << " energy points and " << FragTrap::attackDamage << " attack damage" << std::endl;
}

/**
 * @brief Constructor with name
 */
DiamondTrap::DiamondTrap( std::string const name ): ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap() {
	this->name = name;
	std::cout << "DiamondTrap constructor called" << std::endl;
	std::cout << "DiamondTrap " << this->name << " has " << FragTrap::hitPoints << " hitPoints, " << ScavTrap::energyPoints << " energy points and " << FragTrap::attackDamage << " attack damage" << std::endl;
}

/**
 * @brief Destructor
 */
DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

/**
 * @brief Copy Constructor
 */
DiamondTrap::DiamondTrap( const DiamondTrap& copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy), name(copy.name) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	std::cout << "DiamondTrap " << this->name << " has " << FragTrap::hitPoints << " hitPoints, " << ScavTrap::energyPoints << " energy points and " << FragTrap::attackDamage << " attack damage" << std::endl;
}

/**
 * @brief Assignment operator
 */
DiamondTrap &DiamondTrap::operator=( const DiamondTrap& assign) {
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &assign) {
 		this->name = assign.name;
        this->FragTrap::hitPoints = assign.FragTrap::hitPoints;
        this->ScavTrap::energyPoints = assign.ScavTrap::energyPoints;
        this->FragTrap::attackDamage = assign.FragTrap::attackDamage;
	}
	return *this;
}

/**
 * @brief Attack function
 * 
 * This function will call the attack function from the ScavTrap class
 */
void DiamondTrap::attack( const std::string &target) {
	ScavTrap::attack(target);
}

/**
 * @brief Take damage function
 * 
 * This function will call the takeDamage function from the FragTrap class
 */
void DiamondTrap::takeDamage( unsigned int amount ) {
	FragTrap::takeDamage(amount);
}

/**
 * @brief Be repaired function
 * 
 * This function will call the beRepaired function from the FragTrap class
 */
void DiamondTrap::beRepaired( unsigned int amount ) {
	FragTrap::beRepaired(amount);
}

/**
 * @brief Who am I function
 * 
 * This function will print the name of the DiamondTrap and the name of the ClapTrap
 */
void DiamondTrap::whoAmI( void ) {
	std::cout << "I am " << this->name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}