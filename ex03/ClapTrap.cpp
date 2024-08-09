/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:21:58 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/09 17:14:22 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : name("claptrap"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
	std::cout << "ClapTrap " << this->name << " has " << this->hitPoints << " hitPoints, " << this->energyPoints << " energy points and " << this->attackDamage << " attack damage" << std::endl;
}

ClapTrap::ClapTrap( std::string const name ) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap constructor called" << std::endl;
	std::cout << "ClapTrap " << this->name << " has " << this->hitPoints << " hitPoints, " << this->energyPoints << " energy points and " << this->attackDamage << " attack damage" << std::endl;
}

ClapTrap::~ClapTrap ( void ) {
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copy;
}

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

void ClapTrap::attack(const std::string &target) {
	if (this->energyPoints == 0 || this->hitPoints == 0) {
		std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
	} else {
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints -= 1;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints >= amount) {
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	} else {
		this->hitPoints = 0;
		std::cout << "ClapTrap " << this->name << " has no more hitPoints!" << std::endl;
	}
}

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