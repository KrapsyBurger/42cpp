#include "WrongAnimal.hpp"

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

class WrongCat : public WrongAnimal
{
	private:
	public:
		WrongCat();
		WrongCat(const WrongCat &obj);
		~WrongCat();
};

#endif