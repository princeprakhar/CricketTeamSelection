#include "Player.h"
#include "Team.h"
#include "TeamSelector.h"
#include <iostream>
#include <vector>
#include <cassert>

void run_tests() {
    try {
        Player player1("John Doe", 30, "Right", "Pace", 8, 50, 120.0f, 6.5f, 9, "Batsman", 40.0f, 30);
        Player player2("Jane Smith", 28, "Left", "Spin", 7, 40, 100.0f, 7.0f, 8, "Bowler", 25.0f, 40);
        Player player3("Mike Brown", 25, "Right", "Pace", 9, 60, 110.0f, 6.0f, 10, "All-rounder", 35.0f, 20);
        
        Team team("Amranagar");
        team.add_player(player1);
        team.add_player(player2);
        team.add_player(player3);

        assert(team.calculate_team_rating() == (8 + 7 + 9) / 3.0f);
        auto [left_count, right_count] = team.get_batting_style_count();
        assert(left_count == 1 && right_count == 2);
        assert(team.calculate_average_experience() == (50 + 40 + 60) / 3.0f);
        assert(team.calculate_fitness_level() == (9 + 8 + 10) / 3.0f);

        std::cout << "All tests passed!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
    }
}

int main() {
    run_tests();
    return 0;
}

