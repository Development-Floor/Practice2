#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
	string name;

	Animal() : name("¾øÀ½") {};

	Animal(string name) {
		this->name = name;
	}

	virtual void makeSound() = 0;

	~Animal() {};
};

class Dog : public Animal {
public:
	Dog() : Animal() {};

	Dog(string name) : Animal(name) {};

	void makeSound() {
		cout << name << "°¡ ¸Û¸Û!" << endl;
	}

	~Dog() {};
};

class Cat : public Animal {
public:
	Cat() : Animal() {};

	Cat(string name) : Animal(name) {};

	void makeSound() {
		cout << name << "°¡ ³Ä¿Ë~" << endl;
	}

	~Cat() {};
};

class Cow : public Animal {
public:
	Cow() : Animal() {};

	Cow(string name) : Animal(name) {};

	void makeSound() {
		cout << name << "°¡ À½¸Þ¿¡" << endl;
	}

	~Cow() {};
};

int main() {


	return 0;
}