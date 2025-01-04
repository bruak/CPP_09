#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define ABORT_MSG "\033[31mAborting..\033[0m"
#define ADD "ADD"
#define SEARCH "SEARCH"
#define EXIT "EXIT"
#define WELCOME_TO_PHONEBOOK "\033[38;5;208m\n📞----------------- WELCOME TO PHONEBOOK -----------------📞\033[0m"

#include "Contact.hpp"
#include <string>
#include <iostream>

class PhoneBook
{
private:
    Contact peoples_info[8];
    int current_index;
public:
    PhoneBook();
    ~PhoneBook();

    void print_all_contacts();

    void print_all_contacts_but_with_table_format();
    void print_short_if_too_long(std::string str);
    int is_peopleinfos_empty(int i);
    void contact_saved_messages();
    void Welcome_print();
    void search_contact();
    void init_Start(void);

    void add_person_to_phonebook(Contact& person);
};

#endif
