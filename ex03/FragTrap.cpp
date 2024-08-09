/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:14:26 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/09 17:57:30 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap("anonymous_fragtrap")  {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
	std::cout << "FragTrap " << this->name << " has " << this->hitPoints << " hitPoints, " << this->energyPoints << " energy points and " << this->attackDamage << " attack damage" << std::endl;
}

FragTrap::FragTrap( std::string const name ) : ClapTrap(name) {
		this->hitPoints = 100;
		this->energyPoints = 100;
		this->attackDamage = 30;
		std::cout << "FragTrap constructor called" << std::endl;
		std::cout << "FragTrap " << this->name << " has " << this->hitPoints << " hitPoints, " << this->energyPoints << " energy points and " << this->attackDamage << " attack damage" << std::endl;
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap( const FragTrap& copy ) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = copy;
}

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

void FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << this->name << " says: High five guys!" << std::endl;
}

void FragTrap::attack( const std::string &target) {
	if (this->energyPoints == 0 || this->hitPoints == 0) {
		std::cout << "FragTrap " << this->name << " is out of energy!" << std::endl;
	} else {
		std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints -= 1;
	}
}

void FragTrap::takeDamage( unsigned int amount ) {
	if (this->hitPoints >= amount) {
		this->hitPoints -= amount;
		std::cout << "FragTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	} else {
		this->hitPoints = 0;
		std::cout << "FragTrap " << this->name << " has no more hitPoints!" << std::endl;
	}
}

void FragTrap::beRepaired( unsigned int amount ) {
	if (this->energyPoints == 0) {
		std::cout << "FragTrap " << this->name << " is out of energy!" << std::endl;
	} else {
		std::cout << "FragTrap " << this->name << " is being repaired for " << amount << " points!" << std::endl;
		this->hitPoints += amount;
		this->energyPoints -= 1;
	}
}