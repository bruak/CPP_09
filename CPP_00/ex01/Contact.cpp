#include "Contact.hpp"
#include <iostream>

Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::getInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    
    if (prompt == "Enter phone number: ") {
        while (std::getline(std::cin, input) && !isdigit(input[0]))
            std::cout << "Please enter a valid phone number: ";
        return input;
    }

    if (!std::getline(std::cin, input) && std::cin.eof())
        exit(0);
    return input;
}

void Contact::Get_contact_from_cin() {
    this->firstName = getInput("Enter first name: ");
    this->lastName = getInput("Enter last name: ");
    this->nickName = getInput("Enter nickname: ");
    this->phoneNumber = getInput("Enter phone number: ");
    this->darkestSecret = getInput("Enter darkest secret: ");
}
