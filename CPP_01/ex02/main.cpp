/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:02:18 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/21 15:55:06 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

# define GOLD "\033[93m"
# define TURQUOISE "\033[96m"
# define METAL_BLUE "\033[38;5;111m"
# define PURPLE "\033[1;95m"
# define BLUE "\033[34m"
# define RED "\033[1;91m"
# define GREEN "\033[1;92m"
# define RESET "\033[0m"

int	main(void)
{
	std::string	the_brain = "HI THIS IS BRAIN";

	std::cout << GREEN << "===========  MAIN TESTS ===========" << RESET << std::endl;
	std::cout << GOLD << "[TEST 1] STRING VARIABLE" << RESET << std::endl << std::endl;
	std::cout << "Memory address of variable the_brain: " << TURQUOISE << static_cast<const void*>(the_brain.c_str()) << RESET << std::endl;
	std::cout << "Content of the variable the_brain: " << TURQUOISE << the_brain << std::endl << RESET << std::endl;

	std::string *ptr_to_brain = &the_brain;

	std::cout << GOLD << "[TEST 2] STRING POINTER" << RESET << std::endl << std::endl;
	std::cout << "Pointer address to variable the_brain: " << TURQUOISE << ptr_to_brain << RESET << std::endl;
	std::cout << "Content of the Pointer address: " << TURQUOISE << *ptr_to_brain << RESET << std::endl << std::endl;

	std::string &ref_to_brain = the_brain;

	std::cout << GOLD << "[TEST 3] STRING REFERENCE" << RESET << std::endl << std::endl;
	std::cout << "Reference address to variable the_brain: " << TURQUOISE << &ref_to_brain << RESET << std::endl;
	std::cout << "Content of the Reference address: " << TURQUOISE << ref_to_brain << RESET << std::endl;
	std::cout << GREEN << "===========  END TESTS ===========" << RESET << std::endl << std::endl;

	std::cout << GREEN << "===========  EXTRA TESTS ===========" << RESET << std::endl;
	std::cout << GOLD << "[TEST 4] CHANGE THE VARIABLE" << RESET << std::endl << std::endl;

	the_brain = "HI, THIS IS HEART";
	std::cout << "Memory address of variable the_brain: " << TURQUOISE << static_cast<const void*>(the_brain.c_str()) << RESET << std::endl;
	std::cout << "Content of the variable the_brain: " << TURQUOISE << the_brain << std::endl << RESET << std::endl;
	std::cout << "Pointer address to variable the_brain: " << TURQUOISE << ptr_to_brain << RESET << std::endl;
	std::cout << "Content of the Pointer address: " << TURQUOISE << *ptr_to_brain << RESET << std::endl << std::endl;
	std::cout << "Reference address to variable the_brain: " << TURQUOISE << &ref_to_brain << RESET << std::endl;
	std::cout << "Content of the Reference address: " << TURQUOISE << ref_to_brain << RESET << std::endl << std::endl;

	std::cout << GOLD << "[TEST 5] CHANGE THE VARIABLE BY POINTER" << RESET << std::endl << std::endl;

	*ptr_to_brain = "NEW IDEA";
	std::cout << "Memory address of variable the_brain: " << TURQUOISE << static_cast<const void*>(the_brain.c_str()) << RESET << std::endl;
	std::cout << "Content of the variable the_brain: " << TURQUOISE << the_brain << std::endl << RESET << std::endl;
	std::cout << "Pointer address to variable the_brain: " << TURQUOISE << ptr_to_brain << RESET << std::endl;
	std::cout << "Content of the Pointer address: " << TURQUOISE << *ptr_to_brain << RESET << std::endl << std::endl;
	std::cout << "Reference address to variable the_brain: " << TURQUOISE << &ref_to_brain << RESET << std::endl;
	std::cout << "Content of the Reference address: " << TURQUOISE << ref_to_brain << RESET << std::endl << std::endl;

	std::cout << GOLD << "[TEST 6] CHANGE THE VARIABLE BY REFERENCE" << RESET << std::endl << std::endl;

	ref_to_brain = "HELLO, THIS IS ANOTHER BRAIN!";

	std::cout << "Memory address of variable the_brain: " << TURQUOISE << static_cast<const void*>(the_brain.c_str()) << RESET << std::endl;
	std::cout << "Content of the variable the_brain: " << TURQUOISE << the_brain << std::endl << RESET << std::endl;
	std::cout << "Pointer address to variable the_brain: " << TURQUOISE << ptr_to_brain << RESET << std::endl;
	std::cout << "Content of the Pointer address: " << TURQUOISE << *ptr_to_brain << RESET << std::endl << std::endl;
	std::cout << "Reference address to variable the_brain: " << TURQUOISE << &ref_to_brain << RESET << std::endl;
	std::cout << "Content of the Reference address: " << TURQUOISE << ref_to_brain << RESET << std::endl << std::endl;
	std::cout << GOLD << "[TEST 7] CHANGE THE TARGET OF POINTER" << RESET << std::endl << std::endl;

	std::string other = "I am the intruder!";
	ptr_to_brain = &other;

	ref_to_brain = "HELLO, THIS IS ANOTHER BRAIN!";

	std::cout << "Memory address of variable the_brain: " << TURQUOISE << static_cast<const void*>(the_brain.c_str()) << RESET << std::endl;
	std::cout << "Content of the variable the_brain: " << TURQUOISE << the_brain << std::endl << RESET << std::endl;
	std::cout << "Pointer address to variable the_brain: " << TURQUOISE << ptr_to_brain << RESET << std::endl;
	std::cout << "Content of the Pointer address: " << TURQUOISE << *ptr_to_brain << RESET << std::endl << std::endl;
	std::cout << "Reference address to variable the_brain: " << TURQUOISE << &ref_to_brain << RESET << std::endl;
	std::cout << "Content of the Reference address: " << TURQUOISE << ref_to_brain << RESET << std::endl << std::endl;
	std::cout << GOLD << "[TEST 8] CHANGE THE TARGET OF REFERENCE" << RESET << std::endl << std::endl;

	std::cout << RED << "The reference makes a copy of the value and substitute the original content of the variable. Be careful!!!" << RESET << std::endl << std::endl;

	ref_to_brain = other;
	
	std::cout << "Memory address of variable the_brain: " << TURQUOISE << static_cast<const void*>(the_brain.c_str()) << RESET << std::endl;
	std::cout << "Content of the variable the_brain: " << TURQUOISE << the_brain << std::endl << RESET << std::endl;
	std::cout << "Pointer address to variable the_brain: " << TURQUOISE << ptr_to_brain << RESET << std::endl;
	std::cout << "Content of the Pointer address: " << TURQUOISE << *ptr_to_brain << RESET << std::endl << std::endl;
	std::cout << "Reference address to variable the_brain: " << TURQUOISE << &ref_to_brain << RESET << std::endl;
	std::cout << "Content of the Reference address: " << TURQUOISE << ref_to_brain << RESET << std::endl << std::endl;
	std::cout << GOLD << "[TEST 9] THE POINTER HAS A REFERENCE AND VICE-VERSA" << RESET << std::endl << std::endl;

	std::cout << METAL_BLUE << "Pointers can be NULL and references never NULL, references are alias to other objects. If you want to guarantee, reference to the object of a pointer" << RESET << std::endl << std::endl;
	ptr_to_brain = &ref_to_brain;
	ref_to_brain = *ptr_to_brain;

	ref_to_brain = "NEW IDEA AGAIN!";
	
	std::cout << "Memory address of variable the_brain: " << TURQUOISE << static_cast<const void*>(the_brain.c_str()) << RESET << std::endl;
	std::cout << "Content of the variable the_brain: " << TURQUOISE << the_brain << std::endl << RESET << std::endl;
	std::cout << "Pointer address to variable the_brain: " << TURQUOISE << ptr_to_brain << RESET << std::endl;
	std::cout << "Content of the Pointer address: " << TURQUOISE << *ptr_to_brain << RESET << std::endl << std::endl;
	std::cout << "Reference address to variable the_brain: " << TURQUOISE << &ref_to_brain << RESET << std::endl;
	std::cout << "Content of the Reference address: " << TURQUOISE << ref_to_brain << RESET << std::endl << std::endl;
		
	std::cout << GREEN << "===========  FINAL TESTS ===========" << RESET << std::endl;

	return (0);
}
