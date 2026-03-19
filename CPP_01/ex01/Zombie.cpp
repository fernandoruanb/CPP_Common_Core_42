/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:04:14 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/08 20:52:22 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::set_name(std::string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	std::cout << std::endl;
	std::cout << BLUE << "🧟" << name << GOLD << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

Zombie::Zombie(void) {}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout << std::endl;
	std::cout << "🧟The zombie " << BLUE << name << RESET << " was killed successfully👮⚔️ 🧟";
}
