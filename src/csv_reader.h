//
// Created by warig on 03/09/2024.
//

#ifndef SEMPROJ_CSV_READER_H
#define SEMPROJ_CSV_READER_H


#include <vector>
#include <string>
#include  "../include/teams.h"

std::vector<Team> readTeamsFromCSV(const std::string & filename);
#endif //SEMPROJ_CSV_READER_H