/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:46:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/21 13:43:17 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	index = 0;
	total = 0;
}

bool	PhoneBook::show_add_error(const std::string message, std::string temp) const
{
	int	index;

	if (temp.empty())
        {
		std::cout << std::endl << std::endl;
		std::cout << RED << "╔══════════════════════════════════════════════╗" << RESET << std::endl;
		std::cout << RED << "║           Fill the camp, please !            ║" << RESET << std::endl;
		std::cout << RED << "╠══════════════════════════════════════════════╣" << RESET << std::endl;

		std::cout << message;
		std::cin.clear();
		clearerr(stdin);
		return (1);
        }
	index = 0;
	while (temp[index] != '\0')
	{
		if (temp[index] < 32 || temp[index] > 126)
		{
			std::cout << std::endl;
			std::cout << RED << "╔══════════════════════════════════════════════╗" << RESET << std::endl;
			std::cout << RED << "║             Only ASCII Chars !!!             ║" << RESET << std::endl;
			std::cout << RED << "╠══════════════════════════════════════════════╣" << RESET << std::endl;

			return (1);
		}
		index++;
	}
	if (message == "PHONE NUMBER")
	{
		index = 0;
		while (temp[index] != '\0')
		{
			if ((temp[index] >= '0' && temp[index] <= '9'))
				index++;
			else
			{
				std::cout << std::endl;
		 		std::cout << RED << "╔══════════════════════════════════════════════╗" << RESET << std::endl;
				std::cout << RED << "║            Only Numbers Please !!            ║" << RESET << std::endl;
				std::cout << RED << "╠══════════════════════════════════════════════╣" << RESET << std::endl;

				return (1);
			}
		}
		if (temp.length() > 16)
		{
			std::cout << std::endl;
			std::cout << RED << "╔══════════════════════════════════════════════╗" << RESET << std::endl;
			std::cout << RED << "║          16 digits limit reached!            ║" << RESET << std::endl;
			std::cout << RED << "╠══════════════════════════════════════════════╣" << RESET << std::endl;

			return (1);
		}
	}
	index = 0;
	while (temp[index] != '\0')
	{
		if (!std::isspace(temp[index]))
			return (0);
		index++;
	}

	std::cout << std::endl;
	std::cout << RED << "╔══════════════════════════════════════════════╗" << RESET << std::endl;
        std::cout << RED << "║         Only spaces is forbidden !!          ║" << RESET << std::endl;
        std::cout << RED << "╠══════════════════════════════════════════════╣" << RESET << std::endl;

	return (1);
}

void	PhoneBook::correct_str(std::string &temp) const
{
	if (temp.length() > 9)
		temp = temp.substr(0,9) + '.';
	else
		temp = std::string(10 - temp.length(), ' ') + temp;
}

std::string PhoneBook::format_str_to_inline(std::string temp) const
{
	temp.erase(0, temp.find_first_not_of(" \t\n\r\f\v"));
    	temp.erase(temp.find_last_not_of(" \t\n\r\f\v") + 1);
	return (temp);
}

void	PhoneBook::add_new_contact(void)
{
	Contact	new_contact;
	std::string	temp;

	std::cout << std::endl;
	std::cout << "What is the First Name? ";
	std::getline(std::cin, temp);
	if (show_add_error("FIRST NAME", temp))
		return ;
	correct_str(temp);
	new_contact.set_first_name(temp);
	std::cout << std::endl;

	std::cout << "What is the Last Name? ";
	std::getline(std::cin, temp);
	if (show_add_error("LAST NAME", temp))
                return ;
	correct_str(temp);
	new_contact.set_last_name(temp);
	std::cout << std::endl;

	std::cout << "What is the Nickname? ";
	std::getline(std::cin, temp);
	if (show_add_error("NICKNAME", temp))
                return ;
	correct_str(temp);
	new_contact.set_nickname(temp);
	std::cout << std::endl;

	std::cout << "What is your Phone Number? ";
	std::getline(std::cin, temp);
	if (show_add_error("PHONE NUMBER", temp))
                return ;
	//correct_str(temp);
	temp.erase(0, temp.find_first_not_of(" \t\n\r\f\v"));
	temp.erase(temp.find_last_not_of(" \t\n\r\f\v") + 1);
	new_contact.set_phone_number(temp);
	std::cout << std::endl;

	std::cout << "What is the Darkest Secret? ";
	std::getline(std::cin, temp);
	if (show_add_error("DARKEST SECRET", temp))
                return ;
	//correct_str(temp);
	temp.erase(0, temp.find_first_not_of(" \t\n\r\f\v"));
	temp.erase(temp.find_last_not_of(" \t\n\r\f\v") + 1);
	new_contact.set_darkest_secret(temp);

	phonebook[index % 8] = new_contact;
	index = (index + 1) % 8;
	if (total < 8)
		total++;
	std::cout << std::endl;
	std::cout << GREEN << "╔══════════════════════════════════════════════╗" << RESET << std::endl;
        std::cout << GREEN << "║            Success adding (+1) =D            ║" << RESET << std::endl;
        std::cout << GREEN << "╠══════════════════════════════════════════════╣" << RESET << std::endl;

}

void	PhoneBook::show_all_contacts(void) const
{
	int	num;

	num = 0;
	while (num < total)
	{
		show_specif_contact(num);
		num++;
	}
}

int	PhoneBook::get_total(void) const
{
	return (total);
}

void	PhoneBook::show_inLine_contact(int index) const
{
	if (index >= total)
        {
                std::cout << std::endl;
                std::cerr << RED << "The index surpass the total of contacts" << RESET;
                return ;
        }
        if (total == 0)
        {
                std::cout << std::endl;
                std::cerr << RED << "Doesn't exist a contact" << RESET;
                return ;
        }
	if (index < 0 || index > 7)
	{
		std::cout << std::endl;
		std::cerr << RED << "Invalid index. Only from 1 to 8, please!" << RESET;
		return ;
	}

	std::cout << std::endl;
	std::cout << GOLD << "╔══════════════════════════════════════════════╗" << RESET << std::endl;
	std::cout << GOLD << "║            That is the contact =D            ║" << RESET << std::endl;
	std::cout << GOLD << "╠══════════════════════════════════════════════╣" << RESET << std::endl;
	std::cout << GOLD << "║ " << "Index: " << TURQUOISE << index + 1 << RESET << std::endl;
	std::cout << GOLD << "║ " << "Firstname: " << TURQUOISE << format_str_to_inline(phonebook[index].get_first_name()) << RESET << std::endl;
	std::cout << GOLD << "║ " << "Lastname: " << TURQUOISE << format_str_to_inline(phonebook[index].get_last_name()) << RESET << std::endl;
	std::cout << GOLD << "║ " << "Nickname: " << TURQUOISE << format_str_to_inline(phonebook[index].get_nickname()) << RESET << std::endl;
	std::cout << GOLD << "║ " << "Phone Number: " << TURQUOISE << phonebook[index].get_phone_number() << RESET << std::endl;
	std::cout << GOLD << "║ " << "Darkest Secret: " << TURQUOISE << phonebook[index].get_darkest_secret() << RESET << std::endl;
	std::cout << GOLD << "╚══════════════════════════════════════════════╝" << RESET << std::endl;
}

void	PhoneBook::show_specif_contact(int index) const
{
	if (index < 0 || index > 7)
	{
		std::cout << std::endl;
		std::cerr << RED << "Invalid index. Only from 1 to 8, please!" << RESET;
		return ;
	}
	if (index >= total)
	{
		std::cout << std::endl;
		std::cerr << RED << "The index surpass the total of contacts" << RESET;
		return ;
	}
	if (total == 0)
	{
		std::cout << std::endl;
		std::cerr << RED << "Doesn't exist a contact" << RESET;
		return ;
	}
	std::cout << std::endl;
	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "Index";
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "FirstName";
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "LastName";
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "NickName";
	std::cout << "|";
	std::cout << std::endl;
	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(10) << index + 1 << "|" 
	<< phonebook[index].get_first_name()
	<< "|" << std::setfill(' ') << std::setw(10) << phonebook[index].get_last_name()
	<< "|" << std::setfill(' ') << std::setw(10) << phonebook[index].get_nickname()
	<< "|" << std::endl;
	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
}
