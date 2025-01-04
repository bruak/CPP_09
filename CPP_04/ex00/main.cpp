#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{	
	{
    	const Animal* meta = new Animal();
    	const Animal* j = new Dog();
    	const Animal* i = new Cat();
    	std::cout << j->get_type() << " " << std::endl;
    	std::cout << i->get_type() << " " << std::endl;
    	i->makeSound();
    	j->makeSound();
    	meta->makeSound();
    	delete meta;
		delete i;
		delete j;
	}

    {
	    std::cout << "-----------------------TESTING ANIMAL--------------------------------" << std::endl;

        std::cout << "\033[34mConstructing\033[0m" << std::endl;
	    const Animal	*meta = new Animal();
	    std::cout << std::endl;
	    std::cout << "\033[34mTesting\033[0m" << std::endl;

	    std::cout << "Animal _type: " << meta->get_type() << std::endl;
	    meta->makeSound();
	    std::cout << std::endl;

	    std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	    delete meta;
	    std::cout << std::endl;

	    std::cout << "------------------------TESTING CAT-------------------------------" << std::endl;

	    std::cout << std::endl;
	    std::cout << "\033[34mConstructing\033[0m" << std::endl;
	    const Animal	*catto = new Cat();
	    std::cout << std::endl;

	    std::cout << "\033[34mTesting\033[0m" << std::endl;
	    std::cout << "Cat _type: " << catto->get_type() << std::endl;
	    catto->makeSound();
	    std::cout << std::endl;

	    std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	    delete catto;
	    std::cout << std::endl;

	    std::cout << "------------------------TESTING DOG-------------------------------" << std::endl;

	    std::cout << std::endl;
	    std::cout << "\033[34mConstructing\033[0m" << std::endl;
	    const Animal	*doggo = new Dog();
	    std::cout << std::endl;
	    std::cout << "\033[34mTesting\033[0m" << std::endl;
	    std::cout << "Dog _type: " << doggo->get_type() <<std::endl;
	    doggo->makeSound();
	    std::cout << std::endl;
	    std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	    delete doggo;
	    std::cout << std::endl;

	    std::cout << "-------------------------TESTING WRONGANIMAL------------------------------" << std::endl;

	    std::cout << std::endl;
	    std::cout << "\033[34mConstructing\033[0m" << std::endl;
	    const WrongAnimal	*wrong_meta = new WrongAnimal();
	    std::cout << std::endl;

	    std::cout << "\033[34mTesting\033[0m" << std::endl;
	    std::cout << "Animal _type: " << wrong_meta->get_type() << std::endl;
	    wrong_meta->makeSound();
	    std::cout << std::endl;

	    std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	    delete wrong_meta;
	    std::cout << std::endl;

	    std::cout << "-------------------------TESTING WRONGCAT------------------------------" << std::endl;

	    std::cout << "\033[34mConstructing\033[0m" << std::endl;
	    const WrongAnimal	*wrong_catto = new WrongCat();
	    std::cout << std::endl;

	    std::cout << "\033[34mTesting\033[0m" << std::endl;
	    std::cout << "WrongCat _type: " << wrong_catto->get_type() <<std::endl;
	    wrong_catto->makeSound();
	    std::cout << std::endl;

	    std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	    delete wrong_catto;
	    std::cout << std::endl;

	    std::cout << "----------------------------TESTING WROGCAT---------------------------" << std::endl;

	    std::cout << "\033[34mConstructing\033[0m" << std::endl;
	    const WrongCat	*wrong_catta = new WrongCat();
	    std::cout << std::endl;

	    std::cout << "\033[34mTesting\033[0m" << std::endl;
	    std::cout << "WrongCat _type: " << wrong_catta->get_type() <<std::endl;
	    wrong_catta->makeSound();
	    std::cout << std::endl;

	    std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	    delete wrong_catta;
	    std::cout << std::endl;

		{

	    std::cout << "----------------------------TESTING WRONG POLIMORHISM(ANIMAL)---------------------------" << std::endl;
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
	    const Animal	*test = new Cat();
	    std::cout << std::endl;

	    std::cout << "\033[34mTesting\033[0m" << std::endl;
		//test->test_funciton();
	    std::cout << std::endl;

	    std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	    delete test;
	    std::cout << std::endl;

		}

		{

	    std::cout << "----------------------------TESTING TRUE POLIMORHISM(CAT)---------------------------" << std::endl;
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
	    const Cat	*test = new Cat();
	    std::cout << std::endl;

	    std::cout << "\033[34mTesting\033[0m" << std::endl;
		//test->test_funciton();
	    std::cout << std::endl;

	    std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	    delete test;
	    std::cout << std::endl;
		}



}

    return 0;
}
