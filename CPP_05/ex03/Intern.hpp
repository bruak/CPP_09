#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Form;

class Intern {

    public:
        Intern();
        Intern(const Intern &cpy);
        ~Intern();

        Intern &operator=(const Intern &src);

        Form *makeForm(std::string form_to_create, std::string target_for_form);

};

#endif