#pragma once
#include "Player.h"
#include <vector>
#include <string>
#include <utility>

class Team {
private:
    std::string name;
    std::vector<Player> players;

public:
    Team(const std::string& name);
    void add_player(const Player& player);
    float calculate_team_rating() const;
    std::pair<int, int> get_batting_style_count() const;
    float calculate_average_experience() const;
    float calculate_fitness_level() const;
};

