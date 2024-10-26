#include "Player.h"
#include "Team.h"
#include "TeamSelector.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

void loadPlayersFromFile(const string& filename, vector<Player>& players) {
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        return;
    }

    while (getline(file, line)) {
        stringstream ss(line);
        string name, battingStyle, bowlingType, role;
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
    vector<Player> players;
    loadPlayersFromFile("player.txt", players);

    if (players.empty()) {
        cerr << "No players loaded. Exiting." << endl;
        return 1; 
    }

    Team selected_team = TeamSelector::select_team("Dream Team", players);
    cout << "Selected team rating: " << selected_team.calculate_team_rating() << endl;

    return 0;
}

