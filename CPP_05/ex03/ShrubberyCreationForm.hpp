#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

#include <iostream>

#define ASCII_TREE "        *        \n" \
                   "       ***       \n" \
                   "      *****      \n" \
                   "     *******     \n" \
                   "    *********    \n" \
                   "   ***********   \n" \
                   "  *************  \n" \
                   " *************** \n" \
                   "*****************\n" \
                   "       |||       \n" \
                   "       |||       \n"

class Form;

class ShrubberyCreationForm : public Form {
    public: 
        ShrubberyCreationForm(std::string name);
        ShrubberyCreationForm(const ShrubberyCreationForm &src);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

        const std::string getTarget() const;

        void execute(Bureaucrat const & executor) const;

    private:
        ShrubberyCreationForm();
        const std::string _target;
};

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm *obj);

#endif