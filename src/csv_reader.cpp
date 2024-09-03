//
// Created by warig on 03/09/2024.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

std::vector<Team> readTeamsFromCSV(const std::string & filename){
    std::vector<Team> teams;
    std::ifstream file(filename);
    std::string line;

    std::getline(file,line);
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, localTown, stadium;

        std::getline(ss, name, ',');
        std::getline(ss, localTown, ',');
        std::getline(ss, stadium, ',');

        teams.push_back({name, localTown, stadium});
    }

    return teams;
}