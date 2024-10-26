#include "header/Player.h"
#include "header/Team.h"
#include "header/TeamSelector.h"
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void run_tests() {
    try {
        Player player1("Sandeep Rathi", 30, "Right", "Pace", 7, 50, 130.0f, 6.5f, 8, "Batsman", 34.0f, 22);
        Player player2("Rajesh Gupta", 22, "Right", "Pace", 8, 48, 135.0f, 6.5f, 7, "Bowler", 35.0f, 19);
        Player player3("Neel Kumar", 26, "Left", "Spin", 9, 56, 100.0f, 6.0f, 10, "All-rounder", 30.0f, 22);
        Player player4("Vijay Rathi", 30, "Right", "Pace", 8, 45, 120.0f, 7.0f, 9, "Batsman", 34.0f, 24);
        Player player5("Rohan Mehta", 24, "Left", "Spin", 8, 52, 115.0f, 6.0f, 6, "Bowler", 31.0f, 28);
        Player player6("Tarun Sethi", 28, "Right", "Pace", 7, 53, 130.0f, 5.5f, 8, "All-rounder", 29.0f, 20);
        Player player7("Anup Verma", 22, "Left", "Spin", 9, 54, 110.0f, 6.0f, 7, "Batsman", 36.0f, 23);
        Player player8("Deepak Yadav", 31, "Right", "Pace", 8, 55, 130.0f, 6.0f, 9, "All-rounder", 32.0f, 24);
        Player player9("Shiv Kumar", 24, "Left", "Spin", 8, 50, 100.0f, 6.0f, 10, "All-rounder", 35.0f, 28);
        Player player10("Kunal Kumar", 25, "Right", "Pace", 9, 50, 125.0f, 5.0f, 8, "Batsman", 30.0f, 21);
        Player player11("Tarun Verma", 24, "Left", "Spin", 8, 55, 120.0f, 6.5f, 10, "All-rounder", 33.0f, 19);

        Team team("Rampur");
        team.add_player(player1);
        team.add_player(player2);
        team.add_player(player3);
        team.add_player(player4);
        team.add_player(player5);
        team.add_player(player6);
        team.add_player(player7);
        team.add_player(player8);
        team.add_player(player9);
        team.add_player(player10);
        team.add_player(player11);

        // Example assertions to validate the team's composition
        assert(team.calculate_team_rating() == (7 + 8 + 9 + 8 + 8 + 7 + 9 + 8 + 8 + 9 + 8) / 11.0f);
       
        auto [left_count, right_count] = team.get_batting_style_count();
        assert(left_count == 5 && right_count == 6);  // Corrected assertion

        assert(team.calculate_average_experience() == (50 + 48 + 56 + 45 + 52 + 53 + 54 + 55 + 50 + 50 + 55) / 11.0f);
        assert(team.calculate_fitness_level() == (8 + 7 + 10 + 9 + 6 + 8 + 7 + 9 + 10 + 8 + 10) / 11.0f);

        cout << "All tests passed!" << endl;
    } catch (const exception& e) {
        cerr << "Test failed: " << e.what() << endl;
    }
}

int main() {
    run_tests();
    return 0;
}
