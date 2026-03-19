/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:30:14 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/08 20:30:54 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string	name;

	std::cout << std::endl;
	std::cout << "🧙: What is the name of the persistent zombie: ";
	std::getline(std::cin, name);
	if (name.empty())
	{
		std::cout << std::endl;
		std::cout << RED << "🧙: You need to choose a name, man! D=" << RESET << std::endl;
		return (1);
	}

	/* We allocate memory if we need to use the Zombie in other part of our project, putting it on heap */

	Zombie *myZombie = new Zombie(name); // allocating memory, we need to delete it after the use.
	std::cout << std::endl;
	std::cout << GREEN << "🧙: persistent zombie " << GOLD << name <<  GREEN << " created!" << RESET << std::endl;
	myZombie->announce();
	delete(myZombie);
	std::cout << std::endl;
	std::cout << "🧙: Now, I need to know about the second name for the temporary zombie: ";
	std::getline(std::cin, name);
	if (name.empty())
	{
		std::cout << std::endl;
		std::cout <<  RED << "🧙: Oh, man, you cannot forget to give a name to your zombie!" << RESET << std::endl;
		return (1);
	}
	/* In that part, the Zombie only lives inside the function, if we do not need it, put it on stack only.*/
	myZombie->randomChump(name);
	std::cout << std::endl;
	return (0);
}
