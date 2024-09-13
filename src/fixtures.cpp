//
// Created by warig on 03/09/2024.
//
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <filesystem>
#include "fixtures.h"


std::vector<Fixture> generateFixtures(const std::vector<Team>& teams) {
    std::vector<Fixture> fixtures;
    int weekend = 1;

    // First, generate inter-town matches
    for (size_t i = 0; i < teams.size(); i++) {
        for (size_t j = i + 1; j < teams.size(); j++) {
            if (teams[i].localTown != teams[j].localTown) {
                fixtures.push_back({teams[i].name, teams[j].name, teams[i].stadium, teams[i].localTown, 1, 0});
                fixtures.push_back({teams[j].name, teams[i].name, teams[j].stadium, teams[j].localTown, 2, 0});
            }
        }
    }

    // Then, generate intra-town matches
    for (size_t i = 0; i < teams.size(); i++) {
        for (size_t j = i + 1; j < teams.size(); j++) {
            if (teams[i].localTown == teams[j].localTown) {
                fixtures.push_back({teams[i].name, teams[j].name, teams[i].stadium, teams[i].localTown, 1, 0});
                fixtures.push_back({teams[j].name, teams[i].name, teams[j].stadium, teams[j].localTown, 2, 0});
            }
        }
    }

    // Debug output
    std::cout << "Generated " << fixtures.size() << " fixtures." << std::endl;
    for (const auto& fixture : fixtures) {
        std::cout << fixture.homeTeam << " vs " << fixture.awayTeam << " at " << fixture.stadium
                  << ", " << fixture.localTown << " - Leg " << fixture.leg << std::endl;
    }

    return fixtures;
}

std::vector<Fixture> scheduleFixtures(const std::vector<Fixture>& fixtures) {
    std::vector<Fixture> scheduledFixtures;
    std::map<int, int> weekendMatchCount; // Keeps track of the number of matches per weekend
    std::map<std::string, int> lastTeamWeekend; // Tracks the last weekend each team played

    int currentWeekend = 1; // Start scheduling from the first weekend

    for (auto& fixture : fixtures) {
        // Check if both teams have played this weekend
        int homeTeamLastWeekend = lastTeamWeekend[fixture.homeTeam];
        int awayTeamLastWeekend = lastTeamWeekend[fixture.awayTeam];

        // If the current weekend is filled or one of the teams played already this weekend, move to next weekend
        if (weekendMatchCount[currentWeekend] >= 2 ||
            (homeTeamLastWeekend == currentWeekend) ||
            (awayTeamLastWeekend == currentWeekend)) {
            currentWeekend++; // Move to the next weekend
        }

        // Schedule the fixture for the current weekend
        Fixture scheduledFixture = fixture;
        scheduledFixture.weekend = currentWeekend; // Assign the current weekend to the fixture

        // Update last played weekend for both teams
        lastTeamWeekend[scheduledFixture.homeTeam] = currentWeekend;
        lastTeamWeekend[scheduledFixture.awayTeam] = currentWeekend;

        // Increment match count for the current weekend
        weekendMatchCount[currentWeekend]++;

        // Add the scheduled fixture to the list
        scheduledFixtures.push_back(scheduledFixture);
    }

    // Debug output
    std::cout << "Scheduled " << scheduledFixtures.size() << " fixtures." << std::endl;
    for (const auto& fixture : scheduledFixtures) {
        std::cout << "Weekend #" << fixture.weekend << ": " << fixture.homeTeam << " vs " << fixture.awayTeam
                  << " at " << fixture.stadium << ", " << fixture.localTown << " - Leg " << fixture.leg << std::endl;
    }

    return scheduledFixtures;
}


void outputFixtures(const std::vector<Fixture>& fixtures) {
    std::filesystem::path outputDir = "output";

    try {
        if (!std::filesystem::exists(outputDir)) {
            std::filesystem::create_directories(outputDir);
            std::cout << "Output directory created at " << outputDir << "." << std::endl;
        } else {
            std::cout << "Output directory already exists at " << outputDir << "." << std::endl;
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Failed to create output directory: " << e.what() << std::endl;
        return;
    }

    std::ofstream outFile(outputDir / "fixtures.csv");
    if (!outFile.is_open()) {
        std::cerr << "Failed to open the output file at " << (outputDir / "fixtures.csv") << "!" << std::endl;
        return;
    }

    std::cout << "Writing to the output file at " << (outputDir / "fixtures.csv") << "..." << std::endl;
    outFile << "Home Team,Away Team,Stadium,Local Town,Leg,Weekend\n";

    if (fixtures.empty()) {
        std::cout << "No fixtures to write." << std::endl;
    }

    for (const auto& fixture : fixtures) {
        outFile << fixture.homeTeam << "," << fixture.awayTeam << "," << fixture.stadium << ","
                << fixture.localTown << "," << fixture.leg << "," << fixture.weekend << "\n";
    }

    outFile.close();
    std::cout << "Finished writing to the output file at " << (outputDir / "fixtures.csv") << "." << std::endl;
}

