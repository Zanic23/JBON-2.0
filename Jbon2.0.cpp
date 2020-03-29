// Jbon2.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Parser.h"
#include "object.h"
#include "GenericClass.h"
#include <vector>
#include "Array.h"
#include "ValueRegistration.h"
#include<chrono>
//finish array
//figure out how Vaue will work:
//make a variant that has all derived types and allow it to be created with that. OR
//make ValueTypes use custom template specialization to see if its derived and if so, make new T(value)
void rec(jbon::Object& add, jbon::Object cookiecutter) {

	static int i = 10000;
	add.emplace("obj", cookiecutter);
	//std::cout << i << std::endl;
	i--;
	if (i != 0) {
		rec(add, add);
	}
}

int main()
{
	jbon::Parser file("Dog{age,color,owner}","Dog:Scruffles(20, \"yellow\", {x= 2, y = 4})");
	jbon::GenericClass& dogClass = file.getClass("Dog");
	auto scruffles = dogClass.find("Scruffles");
	
	jbon::Object temp, other;
	temp.emplace("x", 10);
	temp.emplace("y", 20);
	other.emplace("a", 0);
	other.emplace("b", 50);


	other.emplace("c", temp);
	std::vector<int> insertime;
	auto begin = std::chrono::steady_clock::now();
	insertime.push_back(123);
	auto end = std::chrono::steady_clock::now();
	std::cout << "Elapsed Time in microseconds: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " ms" << std::endl;

	//other.print();
}
