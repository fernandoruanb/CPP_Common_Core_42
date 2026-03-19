/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:03:10 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/08 20:52:05 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# define GOLD "\033[93m"
# define TURQUOISE "\033[96m"
# define METAL_BLUE "\033[38;5;111m"
# define PURPLE "\033[1;95m"
# define BLUE "\033[34m"
# define RED "\033[1;91m"
# define GREEN "\033[1;92m"
# define RESET "\033[0m"

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void	set_name(std::string name);
		void	announce(void);
		static Zombie*	zombieHorde(int N, std::string name);
};

#endif /* ZOMBIE_HPP */
