//
// Created by warig on 03/09/2024.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include  "../include/teams.h"
std::vector<Team> readTeamsFromCSV(const std::string & filename){
    std::vector<Team> teams;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << filename << std::endl;
        return teams;
    }

    std::getline(file, line); // Skip header line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, localTown, stadium;

        std::getline(ss, name, ',');
        std::getline(ss, localTown, ',');
        std::getline(ss, stadium, ',');

        teams.push_back({name, localTown, stadium});
    }

    // Debug output
    std::cout << "Read " << teams.size() << " teams from CSV file." << std::endl;
    for (const auto& team : teams) {
        std::cout << team.name << ", " << team.localTown << ", " << team.stadium << std::endl;
    }

    return teams;
}
