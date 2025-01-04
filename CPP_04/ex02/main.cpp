#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#define Animal_N 10

int main()
{

std::cout << "\033[34mConstructing\033[0m" << std::endl;

	{
		const Animal	*Animal_pointer_array[Animal_N];
		for (int i = 0; i < Animal_N; i++)
			if (i < Animal_N / 2)
				Animal_pointer_array[i] = new Cat();
			else
				Animal_pointer_array[i] = new Dog();

		std::cout << "\033[34m***************TESTING ANIMAL TYPE*****************\033[0m" << std::endl;
		for (int i = 0; i < Animal_N; i++){

		 	std::cout << "Animal version-> " << Animal_pointer_array[i]->get_type() << std::endl;
			Animal_pointer_array[i]->makeSound();
			std::cout << std::endl;
		}
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		for (int i = 0; i < Animal_N; i++)
			delete Animal_pointer_array[i];
	}

	{

		std::cout << "\033[34m*******************TESTING BRAIN*********************\033[0m" << std::endl;
		Brain *a = new Brain();

			a->setIdea(0, "dog idea");
			a->setIdea(2, "stupid dog idea");
			a->setIdea(101, "too much");

			std::cout << a->getIdea(0) << std::endl;
			std::cout << a->getIdea(2) << std::endl;
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
	}

	{

		std::cout << "\033[34m*******************TESTING DOG*********************\033[0m" << std::endl;
		Dog *a = new Dog();

			a->setIdea(0, "dog idea");
			a->setIdea(2, "stupid dog idea");

			a->getIdea(0);
			a->getIdea(2);
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
	
	}

	{
		
		std::cout << "\033[34m*******************TESTING CAT*********************\033[0m" << std::endl;
		Cat *a = new Cat();

			a->setIdea(0, "dog idea");
			a->setIdea(2, "stupid dog idea");

			a->getIdea(0);
			a->getIdea(2);
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;	
		delete a;
	
	}

	std::cout << "\033[34m*******************CHECKING DEEP DOG*****************\033[0m" << std::endl;
	{

		Dog basic;
			{
				Dog tmp = basic;
				std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
			}

	
	}


	std::cout << "\033[34m*******************CHECKING DEEP CAT*****************\033[0m" << std::endl;
	{

		Cat basic;
			{
				Cat tmp = basic;
				std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
			}

	}
	
	std::cout << "\033[34m*******************CHECKING DOUBLE FREE PROBLEM*****************\033[0m" << std::endl;


	{
        Dog dog1;

        Dog dog2 = dog1;

        dog1 = dog2;

        dog2 = dog1;
	    std::cout << "\033[34mDeconstructing\033[0m" << std::endl;

    }

	{
		std::cout << "\033[34m*******************TESTING ANIMAL*********************\033[0m" << std::endl;
		//Animal test;

	}


	return 0;
}