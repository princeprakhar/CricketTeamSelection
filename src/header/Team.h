#pragma once
#include "Player.h"
#include <vector>
#include <string>
#include <utility>
using namespace std;

class Team {
private:
    string name;
    vector<Player> players;

public:
    Team(const string& name);
    vector<Player> get_team_player() const; 
    string get_team_name()const;
    void add_player(const Player& player);
    float calculate_team_rating() const;
    pair<int, int> get_batting_style_count() const;
    float calculate_average_experience() const;
    float calculate_fitness_level() const;
};

