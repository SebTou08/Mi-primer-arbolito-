#pragma once
#include<string>
using namespace std;
string names[10] = { "Juan", "Rosa","Sebastian","Ariana","Nicolle","Rita","Piero","Carlos","Almendra","Leao" };
string careers[5] = { "Ingenieria Civil", "Psicologia","Nutricion","Derecho","Arquitectura" };
class Person {
private:
	unsigned short age;
	string name;
	string career;
public:
	Person() {
		age = rand() % 20 + 22;
		name = names[rand() % 10];
		career = careers[rand() % 5];
	}
	Person(unsigned short age, string name, string career) {
		this->age = age;
		this->name = name;
		this->career = career;
	}
	unsigned short getage() { return age; }
	string getname() { return name; }
	string getcareer() { return career; }
};