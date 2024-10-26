#pragma once
#include "Player.h"
#include "Team.h"
#include <vector>
#include <string>
using namespace std;



class TeamSelector {
public:
    static Team select_team(const string& team_name, const vector<Player>& available_players);
};

