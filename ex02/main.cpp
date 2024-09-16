#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cmath>
#include <ctime>
#include <iostream>

Base *generate(void)
{
	srand(time(NULL));
    int	res = rand() % 3;

	switch (res)
	{
	case 0:
		return new A();
		break;
	case 1:
		return new B();
		break;
	case 2:
		return new C();
		break;
	default:
		break;
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "p is pointing A object" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "p is pointing B object" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "p is pointing C object" << std::endl;
	else
		std::cout << "p is not pointing a Base derived object" << std::endl;
}

void identify(Base& p)
{
	try {
		A& aRef = dynamic_cast<A&>(p);
		std::cout << "p is a reference to A object" << std::endl;
	} catch (std::bad_cast& e) {
		try {
			B& bRef = dynamic_cast<B&>(p);
			std::cout << "p is a reference to B object" << std::endl;
		} catch (std::bad_cast& e) {
			try {
				C& bRef = dynamic_cast<C&>(p);
				std::cout << "p is a reference to C object" << std::endl;
			} catch (std::bad_cast& e) {
				std::cout << "p is a reference to an unknown object" << std::endl;
			}
		}
	}
}

int	main()
{
	Base *randomDerived = generate();
	identify(randomDerived);
	identify(*randomDerived);
}
