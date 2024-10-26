#pragma once
#include "Player.h"
#include "Team.h"
#include <vector>
#include <string>

class TeamSelector {
public:
    static Team select_team(const std::string& team_name, const std::vector<Player>& available_players);
};

