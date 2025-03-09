/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:15:21 by lbrusa            #+#    #+#             */
/*   Updated: 2025/02/19 14:14:06 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) 
	: ClapTrap("anon_DiamondTrap_clap_name"), 
	hitPoints(FragTrap::hitPoints), 
	energyPoints(ScavTrap::energyPoints), 
	attackDamage(FragTrap::attackDamage),
	name("anon_DiamondTrap")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	std::cout << "DiamondTrap " << this->name << " has " << this->hitPoints << " hitPoints, " << this->energyPoints << " energy points and " << this->attackDamage << " attack damage" << std::endl;
}

DiamondTrap::DiamondTrap( std::string const name ) 
	: ClapTrap(name + "_clap_name"),  
	hitPoints(FragTrap::hitPoints), 
	energyPoints(ScavTrap::energyPoints), 
	attackDamage(FragTrap::attackDamage),
	name(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	std::cout << "DiamondTrap " << this->name << " has " << this->hitPoints << " hitPoints, " << this->energyPoints << " energy points and " << this->attackDamage << " attack damage" << std::endl;
}
	  
void DiamondTrap::attack( const std::string &target) {
	ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this=copy;
}

DiamondTrap &DiamondTrap::operator=( const DiamondTrap& assign) {
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &assign) {
		this->name = assign.name;
		this->hitPoints = assign.hitPoints;
		this->energyPoints = assign.energyPoints;
		this->attackDamage = assign.attackDamage;
	}
	return *this;
}

void DiamondTrap::takeDamage( unsigned int amount ) {
	FragTrap::takeDamage(amount);
}

void DiamondTrap::beRepaired( unsigned int amount ) {
	FragTrap::beRepaired(amount);
}

void DiamondTrap::whoAmI( void ) {
	std::cout << "I am " << this->name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}