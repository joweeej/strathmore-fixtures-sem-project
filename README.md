# ABC Premier League Fixture Generator

## Overview

The ABC Premier League Fixture Generator is a program designed to create a schedule for a 10-team football league. The fixtures are generated based on specific rules to ensure fair play and adherence to the league's requirements.

## Features

1. **Double Round-Robin Scheduling**: Each team plays every other team twice—once at home and once away.
2. **Local Town Scheduling**: Teams from the same local town play against each other only after they have played teams from other towns.
3. **Weekend Matches**: Only 4 teams can play in each weekend, ensuring a balanced schedule.
4. **Detailed Fixture Information**: The program outputs detailed fixture information, including local town, stadium, leg (home or away), and weekend number.

## Rules for Fixture Generation

1. **Home and Away Matches**: Each team plays every other team twice, once at home and once away.
2. **Local Town Matches**: Teams from the same local town will play against each other after playing against teams from other towns.
3. **Weekend Limitations**: Only 4 teams are scheduled to play per weekend. The fixtures for each weekend are grouped accordingly.

## Usage

To run the fixture generator, follow these steps:

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/abc-premier-league-fixture-generator.git
