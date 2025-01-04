#include <iostream>
#include <string>

#define NON_ARG_MESSAGE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"


void    megaphone(char *str)
{
    int i = 0;
    while (str[i])
        std::cout << (char)toupper(str[i++]);
    std::cout << std::endl;
}

void append_all_av(int ac, std::string &mystring, char **av)
{
    for (int i = 1; i < ac; i++)
        mystring.append(std::string(av[i]));
}

int main(int ac, char **av)
{
    std::string mystring ;

   if (ac == 1)
       std::cout << NON_ARG_MESSAGE << std::endl;
   else
       append_all_av(ac, mystring, av);
    megaphone(&mystring[0]);
    return 0;
}
