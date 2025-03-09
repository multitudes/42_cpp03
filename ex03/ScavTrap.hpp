/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:41:11 by lbrusa            #+#    #+#             */
/*   Updated: 2025/02/19 14:19:27 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

/*

create a derived robot.
It will be named ScavTrap and will inherit the constructors and destructor from
ClapTrap. However, its constructors, destructor and attack() will print
different messages. After all, ClapTraps are aware of their individuality. NB
the virtual public keyword is used to avoid the diamond problem.
*/
class ScavTrap : virtual public ClapTrap {
public:
  ScavTrap(void);
  ScavTrap(std::string const name);
  ~ScavTrap(void);
  ScavTrap(const ScavTrap &copy);
  ScavTrap &operator=(const ScavTrap &assign);

  // member functions specific to ScavTrap
  void guardGate(void);
  // inherited:
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

protected:
  unsigned int hitPoints;
  unsigned int energyPoints;
  unsigned int attackDamage;
};

#endif // SCAVTRAP_HPP_
