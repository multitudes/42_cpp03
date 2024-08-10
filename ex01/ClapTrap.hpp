/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:20:03 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/10 12:25:45 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

/**
 * @brief ClapTrap class
 * 
 * Base class for the ClapTrap family
 * I need virtual functions if I intend to have subclasses 
 * that override the behavior of these functions.
 * I need a virtual destructor if I intend to delete a derived class object
 * through a pointer to a base class.  
 * If you don't declare the base class destructor as virtual and delete a 
 * derived object through a base class pointer, the behavior is undefined. 
 * The base class destructor will be called, but the derived class's destructor won't, 
 * leading to memory leaks and potential crashes.
 */
class ClapTrap {
	public:
		ClapTrap( void );
		ClapTrap(std::string const name);
		virtual ~ClapTrap( void );
		ClapTrap(const ClapTrap& copy);
		ClapTrap &operator=(const ClapTrap& assign);

		// member functions
		virtual void attack(const std::string &target);
		virtual void takeDamage(unsigned int amount);
		virtual void beRepaired(unsigned int amount);
		
	protected:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
};

#endif  // CLAPTRAP_HPP_
