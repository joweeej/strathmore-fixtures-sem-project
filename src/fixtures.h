//
// Created by warig on 03/09/2024.
//

#ifndef SEMPROJ_FIXTURES_H
#define SEMPROJ_FIXTURES_H


#include <vector>
#include <string>
#include "teams.h"

struct Fixture{
    std::string homeTeam;
    std::string awayTeam;
    std::string stadium;
    std::string localTown;
    int leg;
    int weekend;
};

std::vector<Fixture> generateFixtures(const std::vector<Team> & teams);
std::vector<Fixture> scheduleFixtures(const std::vector<Fixture> & fixtures);
void outputFixtures(const std::vector<Fixture> & fixtures);

#endif //SEMPROJ_FIXTURES_H