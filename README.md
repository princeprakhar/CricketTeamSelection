# Cricket Team Selection Engine

## Overview
The Cricket Team Selection Engine is designed to select the best 11 players for a cricket team based on various performance parameters. The engine takes input for each player, including attributes such as name, age, batting style, bowling type, performance rating, experience level, strike rate, economy rate, fitness level, role, average score, and catches taken all of these for the engine takes data from a file `players.txt`.

## Features
- **Player Management**: Create and manage player profiles with detailed statistics.
- **Team Selection**: Automatically selects the best performing players based on defined criteria.
- **Performance Metrics**: Calculates team ratings, average experience, and fitness levels.
- **File Input**: Reads player data from a text file for ease of use.

## System Design
![System Design Diagram](https://drive.google.com/uc?id=1QcnJ8DnSj9r4vVM9sCHF2l-KWrS7LLUB)

## Classes
### 1. Player Class
Represents a cricket player with attributes such as:
- `name`: The name of the player.
- `age`: The age of the player.
- `batting_style`: The batting style (e.g., left, right).
- `bowling_type`: The type of bowling (e.g., pace, spin).
- `performance_rating`: A numeric rating of performance.
- `experience_level`: Years of experience in cricket.
- `strike_rate`: The strike rate of the player.
- `economy_rate`: The economy rate of the bowler.
- `fitness_level`: The fitness level of the player.
- `role`: The role of the player (e.g., batsman, bowler, all-rounder).
- `average_score`: The average score of the player.
- `catches_taken`: The number of catches taken by the player.

### 2. Team Class
Manages a collection of players and provides methods to:
- Add players to the team.
- Calculate the team rating based on individual performance ratings.
- Retrieve statistics such as average experience and batting style counts.

### 3. TeamSelector Class
Contains logic to select the best team from a given list of players based on specified criteria.

## Getting Started

### Prerequisites
- C++ Compiler (g++, clang++, etc.)
- CMake (optional for build configuration)
- Basic knowledge of C++ programming and object-oriented concepts.

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/CricketTeamSelection.git
   cd CricketTeamSelection

## Author
**[Prakhar Deep](https://github.com/princeprakhar)**  

## Contact

If you have any questions, feel free to reach out or open an issue in the GitHub repository.

Happy coding!
