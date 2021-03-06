#include "NameGenerator.h"
#include "RandomNumberGenerator.h"
#include <fstream>
#include <sstream>
#include <iostream>

NameGenerator::NameGenerator()
{
	loadFromFile();
}

void NameGenerator::loadFromFile()
{
	std::string filename = "data/firstnames.csv";		// TODO: �ber Konfiguration laden
	std::ifstream csvread;
	std::string line;

	csvread.open(filename, std::ios::in);
	if (!csvread.is_open())
	{
		std::cout << "Error while reading " + filename << std::endl;
		csvread.close();
		return;
	}
	while (std::getline(csvread, line))
	{
		if (line.empty())				// skip empty lines:
			continue;

		std::istringstream iss(line);
		std::string lineStream;

		std::getline(iss, lineStream, ',');	// index
		std::getline(iss, lineStream, ','); // name
		firstname.push_back(lineStream);
		std::getline(iss, lineStream, ','); // male
		std::getline(iss, lineStream, ','); // female
		std::getline(iss, lineStream, ','); // language

	}
	csvread.close();

	filename = "data/lastnames.csv";					// TODO: �ber Konfiguration laden
	csvread.open(filename, std::ios::in);
	if (!csvread.is_open())
	{
		std::cout << "Error while reading " + filename << std::endl;
		csvread.close();
		return;
	}
	while (std::getline(csvread, line))
	{
		if (line.empty())				// skip empty lines:
			continue;

		std::istringstream iss(line);
		std::string lineStream;

		std::getline(iss, lineStream, ',');	// index
		std::getline(iss, lineStream, ','); // name
		lastname.push_back(lineStream);
		std::getline(iss, lineStream, ','); // language

	}
	csvread.close();
}

std::tuple<std::string, std::string> NameGenerator::createName()
{
	std::string firstname;
	std::string lastname;

	firstname = this->firstname[RandomNumberGenerator::randomNumber(0, static_cast<int>(this->firstname.size()))];
	lastname = this->lastname[RandomNumberGenerator::randomNumber(0, static_cast<int>(this->lastname.size()))];

	return std::make_tuple(firstname, lastname);
}