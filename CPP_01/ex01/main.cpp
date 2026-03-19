/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:24:20 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/08 20:57:07 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>
#include <climits>

// I need to code manually the ft_atoi to avoid overflow and underflow in my program

static int ft_atoi(const char *nptr)
{
	long result = 0;

	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\f' || *nptr == '\v'
		|| *nptr == '\a' || *nptr == '\b' || *nptr == '\r')
		++nptr;
	while (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			return (-1);
		++nptr;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result *= 10;
		if (result > INT_MAX)
			return (-1);
		result += *nptr - '0';
		++nptr;
	}
	return (result);
}

int	main(void)
{
	std::string num_of_zombies;
	std::string	name;
	Zombie*	MyZombies;
	int	real_number;

	std::cout << std::endl;
	std::cout << "🧙: How many zombies do you want? ";
	std::getline(std::cin, num_of_zombies);
	if (num_of_zombies.empty())
	{
		std::cout << std::endl << RED << "🧙: You need to pass something to continue!" << RESET << std::endl;
		return (1);
	}
	real_number = ft_atoi(num_of_zombies.c_str());
	if (real_number > 10000 || real_number <= 0)
	{
		std::cout << std::endl;
		std::cout << RED << "🧙: Invalid number of zombies, man! D=" << RESET << std::endl;
		std::cout << std::endl;
		return (1);
	}
	std::cout << std::endl;
	std::cout << "🧙: Ok, I also need to know what name do you want to give them: ";
	std::getline(std::cin, name);
	if (name.empty())
	{
		std::cout << std::endl;
		std::cout << RED << "🧙: You need to choose a name for your children =D" << RESET << std::endl;
		return (1);
	}
	MyZombies = Zombie::zombieHorde(real_number, name);
	std::cout << std::endl << std::endl;
	std::cout << GREEN << "🧙: Your zombies are made!!!" << RESET << std::endl;
	delete[] MyZombies; // Yes, that is the unique difference, it is simple, is it not simple?
	std::cout << std::endl;
	return (0);
}
