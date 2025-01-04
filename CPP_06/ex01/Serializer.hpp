#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

#define JUST_NEW_LINE std::cout << std::endl;

struct Data
{
	std::string car;
};

class Serializer {

	public:
		Serializer(const Serializer &src);

		~Serializer();

		Serializer &operator=(const Serializer &src);


		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);

    private:
		Serializer();

};

#endif