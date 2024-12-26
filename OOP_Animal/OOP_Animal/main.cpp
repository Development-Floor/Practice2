#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

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

class Zoo {
private:
	Animal* animals[10];
	int animalCount = 0;
	
public:
	void addAnimal(Animal* animal) {
		if (animalCount >= 10) {
			cout << "�������� �������� ���� �� �����ϴ�." << endl;
			return;
		}

		cout << animal->name << "�� �������� ���Դ�." << endl;

		animals[animalCount] = animal;

		animalCount++;
	}

	void performActions() {
		for (int i = 0; i < animalCount; i++) {
			animals[i]->makeSound();
		}
	}

	~Zoo() {
		for (int i = 0; i < animalCount; i++) {
			delete animals[i];
			animals[i] = NULL;
		}
	}
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

Animal* createRandomAnimal() {
	Animal* animal = NULL;

	int random = rand() % 3;

	if (random == 0) {
		Dog* dog = new Dog("������");

		animal = dog;
	}

	else if (random == 1) {
		Cat* cat = new Cat("�����");

		animal = cat;
	}

	else if (random == 2) {
		Cow* cow = new Cow("��");

		animal = cow;
	}

	return animal;
}

int main() {
	srand(time(NULL));

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

	cout << "\n-------------\n" << endl;

	Zoo zoo;

	Animal* random_animal1 = createRandomAnimal();
	Animal* random_animal2 = createRandomAnimal();
	Animal* random_animal3 = createRandomAnimal();

	zoo.addAnimal(random_animal1);
	zoo.addAnimal(random_animal2);
	zoo.addAnimal(random_animal3);

	cout << endl;

	zoo.performActions();

	return 0;
}