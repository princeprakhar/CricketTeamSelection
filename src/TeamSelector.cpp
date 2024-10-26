#include "header/TeamSelector.h"
#include <algorithm>
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

    auto sortByPerformance = [](const Player& a, const Player& b) {
        return a.getPerformanceRating() > b.getPerformanceRating();
    };
    
    sort(batsmen.begin(), batsmen.end(), sortByPerformance);
    sort(bowlers.begin(), bowlers.end(), sortByPerformance);
    sort(all_rounders.begin(), all_rounders.end(), sortByPerformance);

    int count = 0;
    // Add top batsmen (e.g., 5 batsmen)
    for (int i = 0; i < min(5, (int)batsmen.size()); ++i) {
        selected_team.add_player(batsmen[i]);
        count++;
    }

    

    // Add top all-rounders (e.g., 3 all-rounders)
    for (int i = 0; i < min(3, (int)all_rounders.size()); ++i) {
        selected_team.add_player(all_rounders[i]);
        count++;
    }


    // Add top bowlers (e.g., 3 bowlers)
    for (int i = 0; i < min(3, (int)bowlers.size()); ++i) {
        selected_team.add_player(bowlers[i]);
        count++;
    }

    // If we still need players, fill with remaining top players from any role
    if (count < 11) {
        // Combine remaining players and sort again
        vector<Player> remaining_players;
        remaining_players.insert(remaining_players.end(), batsmen.begin() + 5, batsmen.end());
        remaining_players.insert(remaining_players.end(), bowlers.begin() + 3, bowlers.end());
        remaining_players.insert(remaining_players.end(), all_rounders.begin() + 3, all_rounders.end());
        
        sort(remaining_players.begin(), remaining_players.end(), sortByPerformance);

        // Add remaining players until we have 11
        for (int i = 0; count < 11 && i < remaining_players.size(); ++i) {
            selected_team.add_player(remaining_players[i]);
            count++;
        }
    }

    return selected_team;
}

