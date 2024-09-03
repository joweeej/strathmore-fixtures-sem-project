
#include <vector>
#include "csv_reader.h"
#include "fixtures.h"


using namespace std;
int main() {
    std::vector<Team> teams = readTeamsFromCSV("data/teams.csv");
    std::vector<Fixture> fixtures = generateFixtures(teams);
    std::vector<Fixture> scheduledFixtures = scheduleFixtures(fixtures);
    outputFixtures(scheduledFixtures);


    return 0;
}
