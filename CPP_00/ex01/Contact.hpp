#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>


class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        Contact();
        ~Contact();

        std::string getInput(const std::string& prompt);
        void Get_contact_from_cin();

        std::string getFirstName() { return firstName; }
        std::string getLastName() { return lastName; }
        std::string getNickName() { return nickName; }
        std::string getPhoneNumber() { return phoneNumber; }
        std::string getDarkestSecret() { return darkestSecret; }
};


#endif
