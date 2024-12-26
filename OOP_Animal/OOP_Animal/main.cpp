#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Animal {
public:
	string name;

	Animal() : name("없음") {};

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
			cout << "동물원이 가득차서 받을 수 없습니다." << endl;
			return;
		}

		cout << animal->name << "가 동물원에 들어왔다." << endl;

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
		cout << name << "가 멍멍!" << endl;
	}

	~Dog() {};
};

class Cat : public Animal {
public:
	Cat() : Animal() {};

	Cat(string name) : Animal(name) {};

	void makeSound() {
		cout << name << "가 냐옹~" << endl;
	}

	~Cat() {};
};

class Cow : public Animal {
public:
	Cow() : Animal() {};

	Cow(string name) : Animal(name) {};

	void makeSound() {
		cout << name << "가 음메에" << endl;
	}

	~Cow() {};
};

Animal* createRandomAnimal() {
	Animal* animal = NULL;

	int random = rand() % 3;

	if (random == 0) {
		Dog* dog = new Dog("강아지");

		animal = dog;
	}

	else if (random == 1) {
		Cat* cat = new Cat("고양이");

		animal = cat;
	}

	else if (random == 2) {
		Cow* cow = new Cow("소");

		animal = cow;
	}

	return animal;
}

int main() {
	srand(time(NULL));

	Animal* animal[3];

	Dog dog("흰둥이");
	Cat cat("깜둥이");
	Cow cow("노랭이");

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