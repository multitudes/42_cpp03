/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:41:00 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/09 17:14:45 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) 
	: ClapTrap("claptrap_clap_name"), hitPoints(100), energyPoints(50), attackDamage(20) {
	std::cout << "ScavTrap default constructor called" << std::endl;
	std::cout << "ScavTrap" << this->name << " has " << this->hitPoints << " hitPoints, " << this->energyPoints << " energy points and " << this->attackDamage << " attack damage" << std::endl;
}

ScavTrap::ScavTrap( std::string const name )
	:  ClapTrap(name + "_clap_name"), hitPoints(100), energyPoints(50), attackDamage(20) {
	std::cout << "ScavTrap constructor called" << std::endl;
	std::cout << "ScavTrap" << this->name << " has " << this->hitPoints << " hitPoints, " << this->energyPoints << " energy points and " << this->attackDamage << " attack damage" << std::endl;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& assign) {
	std::cout << "ScavTrap assignation operator called" << std::endl;
	if (this != &assign) {
		this->name = assign.name;
		this->hitPoints = assign.hitPoints;
		this->energyPoints = assign.energyPoints;
		this->attackDamage = assign.attackDamage;
	}
	return *this;
}

void ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap" << this->name << " has entered in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (this->energyPoints == 0 || this->hitPoints == 0) {
		std::cout << "ScavTrap" << this->name << " is out of energy!" << std::endl;
	} else {
	std::cout << "ScavTrap" << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints -= 1;
	}
}

void ScavTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints >= amount) {
		this->hitPoints -= amount;
		std::cout << "ScavTrap" << this->name << " takes " << amount << " points of damage!" << std::endl;
	} else {
		this->hitPoints = 0;
		std::cout << "ScavTrap" << this->name << " has no more hitPoints!" << std::endl;
	}
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints == 0) {
		std::cout << "ScavTrap" << this->name << " is out of energy!" << std::endl;
	} else if (this->hitPoints == 0) {
		std::cout << "ScavTrap" << this->name << " has no more hitPoints and cannot be repaired!" << std::endl;
	} else if (this->hitPoints + amount < 100) {
		std::cout << "ScavTrap" << this->name << " is being repaired for " << amount << " points!" << std::endl;
		this->hitPoints += amount;
	}  else if (this->hitPoints + amount > 100 ) {
		std::cout << "ScavTrap" << this->name << " cannot be repaired for more than 100 hitPoints!" << std::endl;
	} else if (this->hitPoints + amount == 100) {
		std::cout << "ScavTrap" << this->name << " has full hitPoints!" << std::endl;
		this->hitPoints = 100;
	}
}