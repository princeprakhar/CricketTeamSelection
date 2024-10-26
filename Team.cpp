#include "Team.h"
#include <numeric>

Team::Team(const std::string& name) : name(name) {}

void Team::add_player(const Player& player) {
    players.push_back(player);
}

float Team::calculate_team_rating() const {
    if (players.empty()) return 0.0f;
    float total_rating = std::accumulate(players.begin(), players.end(), 0.0f,
        [](float sum, const Player& p) { return sum + p.getPerformanceRating(); });
    return total_rating / players.size();
}

std::pair<int, int> Team::get_batting_style_count() const {
    int left_count = 0, right_count = 0;
    for (const auto& player : players) {
        if (player.getBattingStyle() == "Left") left_count++;
        else right_count++;
    }
    return {left_count, right_count};
}

float Team::calculate_average_experience() const {
    if (players.empty()) return 0.0f;
    float total_experience = std::accumulate(players.begin(), players.end(), 0.0f,
        [](float sum, const Player& p) { return sum + p.getExperienceLevel(); });
    return total_experience / players.size();
}

float Team::calculate_fitness_level() const {
    if (players.empty()) return 0.0f;
    float total_fitness = std::accumulate(players.begin(), players.end(), 0.0f,
        [](float sum, const Player& p) { return sum + p.getFitnessLevel(); });
    return total_fitness / players.size();
}

