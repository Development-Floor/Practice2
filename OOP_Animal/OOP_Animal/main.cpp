#include <iostream>
#include <string>

using namespace std;

class Zoo {

};

class Animal {
public:
	string name;

	Animal() : name("����") {};

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
		cout << name << "�� �۸�!" << endl;
	}

	~Dog() {};
};

class Cat : public Animal {
public:
	Cat() : Animal() {};

	Cat(string name) : Animal(name) {};

	void makeSound() {
		cout << name << "�� �Ŀ�~" << endl;
	}

	~Cat() {};
};

class Cow : public Animal {
public:
	Cow() : Animal() {};

	Cow(string name) : Animal(name) {};

	void makeSound() {
		cout << name << "�� ���޿�" << endl;
	}

	~Cow() {};
};

int main() {
	Animal* animal[3];

	Dog dog("�����");
	Cat cat("������");
	Cow cow("�뷩��");

	animal[0] = &dog;
	animal[1] = &cat;
	animal[2] = &cow;

	for (int i = 0; i < 3; i++) {
		animal[i]->makeSound();
	}

	return 0;
}