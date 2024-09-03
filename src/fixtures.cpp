//
// Created by warig on 03/09/2024.
//
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include "fixtures.h"


std::vector<Fixture> generateFixtures(const std::vector<Team>& teams) {
    std::vector<Fixture> fixtures;
    int weekend = 1;

    // Ensure no team plays more than once per weekend
    for (size_t i = 0; i < teams.size(); i++) {
        for (size_t j = i + 1; j < teams.size(); j++) {
            if (teams[i].localTown != teams[j].localTown) {
                fixtures.push_back({teams[i].name, teams[j].name, teams[i].stadium, teams[i].localTown, 1, weekend});
                fixtures.push_back({teams[j].name, teams[i].name, teams[j].stadium, teams[j].localTown, 2, weekend});
            }
        }
    }

    // Add local town matches
    for (size_t i = 0; i < teams.size(); i++) {
        for (size_t j = i + 1; j < teams.size(); j++) {
            if (teams[i].localTown == teams[j].localTown) {
                fixtures.push_back({teams[i].name, teams[j].name, teams[i].stadium, teams[i].localTown, 1, weekend});
                fixtures.push_back({teams[j].name, teams[i].name, teams[j].stadium, teams[j].localTown, 2, weekend});
            }
        }
    }

    return fixtures;
}

std::vector<Fixture> scheduleFixtures(std::vector<Fixture>& fixtures) {
    std::vector<Fixture> scheduledFixtures;
    std::map<int, int> weekendMatchCount; // Weekend to count of matches

    for (auto& fixture : fixtures) {
        if (weekendMatchCount[fixture.weekend] < 2) {
            scheduledFixtures.push_back(fixture);
            weekendMatchCount[fixture.weekend]++;
        } else {
            fixture.weekend++; // Move to next weekend if current is full
            weekendMatchCount[fixture.weekend]++;
            scheduledFixtures.push_back(fixture);
        }
    }

    return scheduledFixtures;
}

void outputFixtures(const std::vector<Fixture>& fixtures) {
    std::ofstream outFile("output/fixtures.csv");
    outFile << "Home Team,Away Team,Stadium,Local Town,Leg,Weekend\n";

    for (const auto& fixture : fixtures) {
        std::cout << "Weekend #" << fixture.weekend << ": " << fixture.homeTeam << " vs " << fixture.awayTeam
                  << " at " << fixture.stadium << ", " << fixture.localTown << " - Leg " << fixture.leg << std::endl;
        outFile << fixture.homeTeam << "," << fixture.awayTeam << "," << fixture.stadium << "," << fixture.localTown
                << "," << fixture.leg << "," << fixture.weekend << "\n";
    }

    outFile.close();
}