#include "Player.h"
#include "Team.h"
#include "TeamSelector.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

void loadPlayersFromFile(const std::string& filename, std::vector<Player>& players) {
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return;
    }

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string name, battingStyle, bowlingType, role;
        int age, performanceRating, experienceLevel;
        double strikeRate, economyRate, fitnessLevel, averageScore, catchesTaken;

        // Read and parse player data from the line
        getline(ss, name, ',');
        ss >> age;
        ss.ignore(); // Ignore the comma
        getline(ss, battingStyle, ',');
        getline(ss, bowlingType, ',');
        ss >> performanceRating;
        ss.ignore();
        ss >> experienceLevel;
        ss.ignore();
        ss >> strikeRate;
        ss.ignore();
        ss >> economyRate;
        ss.ignore();
        ss >> fitnessLevel;
        ss.ignore();
        getline(ss, role, ',');
        ss >> averageScore;
        ss.ignore();
        ss >> catchesTaken;

        // Create a Player object and add it to the vector
        Player player(name, age, battingStyle, bowlingType, performanceRating, experienceLevel, strikeRate, economyRate, fitnessLevel, role, averageScore, catchesTaken);
        players.push_back(player);
    }

    file.close();
}

int main() {
    std::vector<Player> players;
    loadPlayersFromFile("player.txt", players);

    if (players.empty()) {
        std::cerr << "No players loaded. Exiting." << std::endl;
        return 1; // Exit if no players were loaded
    }

    Team selected_team = TeamSelector::select_team("Dream Team", players);
    std::cout << "Selected team rating: " << selected_team.calculate_team_rating() << std::endl;

    return 0;
}

