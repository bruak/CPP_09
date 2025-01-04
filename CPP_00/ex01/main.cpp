#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook Pb;
    
    std::cout << WELCOME_TO_PHONEBOOK << std::endl;
    std::string command;
    std::cout << "> ";
    
    while (getline(std::cin, command))
    {
        std::cout << "> ";
        if (command == ADD)
            Pb.init_Start();
        else if (command == SEARCH)
        {
            Pb.print_all_contacts_but_with_table_format();
            Pb.search_contact();
        }
        else if (command == EXIT)
        {
            std::cout << ABORT_MSG << std::endl;
            break;
        }
    }
    return 0;
}
