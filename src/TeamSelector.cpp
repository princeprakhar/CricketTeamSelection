#include "header/TeamSelector.h"
using namespace std;


Team TeamSelector::select_team(const string& team_name, const vector<Player>& available_players) {
    Team selected_team(team_name);
    vector<Player> batsmen;
    vector<Player> bowlers;
    vector<Player> all_rounders;

    for (const auto& player : available_players) {
        if (player.getRole() == "Batsman") batsmen.push_back(player);
        else if (player.getRole() == "Bowler") bowlers.push_back(player);
        else if (player.getRole() == "All-rounder") all_rounders.push_back(player);
    }

    if (!batsmen.empty()) selected_team.add_player(batsmen[0]);
    if (!bowlers.empty()) selected_team.add_player(bowlers[0]);
    if (!all_rounders.empty()) selected_team.add_player(all_rounders[0]);

    return selected_team;
}

