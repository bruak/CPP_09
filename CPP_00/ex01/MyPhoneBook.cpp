#include "PhoneBook.hpp"

#include "Contact.hpp"
#include <iomanip>
#include <limits>
#include <stdlib.h>

#define EMTY_FIRST_NAME "\033[31mThere is't a First Name saved.\033[0m"
#define EMTY_LAST_NAME "\033[31mThere is't a Last Name saved.\033[0m"
#define EMTY_NICK_NAME "\033[31mThere is't a Nick Name saved.\033[0m"
#define EMTY_PHONE_NUMBER "\033[31mThere is't a Phone Number saved.\033[0m"
#define EMTY_DARKEST_SECRET "\033[31mThere is't a Darkest secret saved.\033[0m"
#define PRINT_MSG "\033[38;5;208m\n----------------- PHONBOOK CONTACTS -----------------\033[0m"
#define PRINT_MSG2 "\033[38;5;208m\n-----------------------------------------------------\033[0m"

PhoneBook::PhoneBook(){
    current_index = 0;
    Welcome_print();
}

PhoneBook::~PhoneBook(){
}

#define MAX_CONTACTS 8
void PhoneBook::add_person_to_phonebook(Contact& person)
{
    peoples_info[current_index % MAX_CONTACTS] = person;
    if (current_index < MAX_CONTACTS){
        current_index++;
    }
}

void PhoneBook::init_Start(void){
    peoples_info[current_index].Get_contact_from_cin();
    add_person_to_phonebook(peoples_info[current_index]);
    contact_saved_messages();
    Welcome_print();
}

void PhoneBook::Welcome_print()
{
        std::string commands[] = {"ADD", "SEARCH", "EXIT"};
        std::string colors[] = {"\033[31m", "\033[32m", "\033[33m"};

        std::cout << "\033[34mPlease enter a command: \033[0m";
        for (int i = 0; i < 3; i++) {
            std::cout << colors[i % 6] << commands[i] << "\033[0m" << " ";
        }
        std::cout << std::endl;
}

void PhoneBook::contact_saved_messages()
{
    std::cout << "\033[38;5;208m\nProccess loading...\033[0m" << std::endl;
    std::cout << "\033[36m\nContact added\033[0m" << std::endl;
}


void PhoneBook::print_all_contacts()
{
    std::cout << "Printing all contacts" << std::endl;
    for (int i = 0; i < current_index; i++)
    {
        std::cout << "Contact " << i << std::endl;
        std::cout << "First name: " << peoples_info[i].getFirstName() << std::endl;
        std::cout << "Last name: " << peoples_info[i].getLastName() << std::endl;
        std::cout << "Nick name: " << peoples_info[i].getNickName() << std::endl;
        std::cout << "Phone number: " << peoples_info[i].getPhoneNumber() << std::endl;
        std::cout << "Darkest secret: " << peoples_info[i].getDarkestSecret() << std::endl;
    }
}

void PhoneBook::print_short_if_too_long(std::string str)
{
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << "." << "|";
    else
        std::cout << std::setw(10) << str << "|";
}

int PhoneBook::is_peopleinfos_empty(int i)
{
    if (peoples_info[i].getFirstName().length() == 0)
        return (std::cout << EMTY_FIRST_NAME << std::endl), (1);
    else if (peoples_info[i].getLastName().length() == 0)
        return (std::cout << EMTY_LAST_NAME << std::endl), (1);
    else if (peoples_info[i].getNickName().length() == 0)
        return (std::cout << EMTY_NICK_NAME << std::endl), (1);
    else if (peoples_info[i].getPhoneNumber().length() == 0)
        return (std::cout << EMTY_PHONE_NUMBER << std::endl), (1);
    else if (peoples_info[i].getDarkestSecret().length() == 0)
        return (std::cout << EMTY_DARKEST_SECRET << std::endl), (1);
    return 0;
}

void PhoneBook::print_all_contacts_but_with_table_format()
{
    std::cout << PRINT_MSG << std::endl;
    for (int i = 0; i < current_index; i++)
    {
        if(is_peopleinfos_empty(i))
            std::cout << "you should write a name" << std::endl, exit(1);

        std::cout << "| " << std::setw(10) << i << " | ";
        print_short_if_too_long(peoples_info[i].getFirstName());
        print_short_if_too_long(peoples_info[i].getLastName());
        print_short_if_too_long(peoples_info[i].getNickName());
        std::cout << std::endl;
    }
    std::cout << PRINT_MSG2 << std::endl;
}

void PhoneBook::search_contact()
{
    int index;

    std::cout << "\033[34mEnter the index of the contact you want to search: \033[0m";
    while (!(std::cin >> index))
    {
        if (std::cin.eof())
            exit(0);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index. Please enter a valid index: ";
    }
        if (index < 0 || index >= current_index) {
            std::cout << "\033[31mError: Index out of range.\033[0m" << std::endl;
            } 
        else {

            std::cout << "\033[35m---->> CONTACT #" << index << " <<----\033[0m" << std::endl;
            if (!peoples_info[index].getFirstName().empty())
                std::cout << "\033[38;5;208mFirst name: " << peoples_info[index].getFirstName() << std::endl;
            if (!peoples_info[index].getLastName().empty())
                std::cout << "Last name: " << peoples_info[index].getLastName() << std::endl;
            if (!peoples_info[index].getNickName().empty())
                std::cout << "Nick name: " << peoples_info[index].getNickName() << std::endl;
            if (!peoples_info[index].getPhoneNumber().empty())
                std::cout << "Phone number: " << peoples_info[index].getPhoneNumber() << std::endl;
            if (!peoples_info[index].getDarkestSecret().empty())
                std::cout << "Darkest secret: " << peoples_info[index].getDarkestSecret() << std::endl;
        }

    Welcome_print();
}
