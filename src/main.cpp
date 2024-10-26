#include "header/player.h"
#include "header/Team.h"
#include "header/TeamSelector.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip> 
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

void printTeamPlayers(const string& team_name, const vector<Player>& team_players) {
    cout << "Team name: " << team_name << endl << endl;

    cout << left << setw(20) << "Player Name"
         << setw(15) << "Role"
         << setw(20) << "Performance Rating"
         << setw(20) << "Experience Level"
         << setw(15) << "Batting Style" << endl;

    cout << string(90, '-') << endl; // Print a separator line

    for (const Player& tp : team_players) {
        cout << left << setw(20) << tp.getName()
             << setw(15) << tp.getRole()
             << setw(20) << tp.getPerformanceRating()
             << setw(20) << tp.getExperienceLevel()
             << setw(15) << tp.getBattingStyle() << endl;
    }
}

int main() {
    vector<Player> players;
    loadPlayersFromFile("../data/player.txt", players);

    if (players.empty()) {
        cerr << "No players loaded. Exiting." << endl;
        return 1; 
    }


    Team selected_team = TeamSelector::select_team("Dream Team", players);
    string s= selected_team.get_team_name();
    vector<Player> team_players = selected_team.get_team_player();
    printTeamPlayers(s, team_players);

    cout << "Selected team rating: " << selected_team.calculate_team_rating() << endl;

    return 0;
}

