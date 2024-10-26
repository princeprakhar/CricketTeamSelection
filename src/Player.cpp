#include "header/Player.h"
#include <stdexcept>
using namespace std;

Player::Player(const string& name, int age, const string& batting_style,
               const string& bowling_type, int performance_rating,
               int experience_level, float strike_rate, float economy_rate,
               int fitness_level, const string& role, 
               float average_score, int catches_taken) 
    : name(name), age(age), batting_style(batting_style), 
      bowling_type(bowling_type), performance_rating(performance_rating), 
      experience_level(experience_level), strike_rate(strike_rate), 
      economy_rate(economy_rate), fitness_level(fitness_level), 
      role(role), average_score(average_score), catches_taken(catches_taken) {
    
    if (performance_rating < 1 || performance_rating > 10) {
        throw invalid_argument("Performance rating must be between 1 and 10.");
    }
    if (age < 15 || age > 45) {
        throw invalid_argument("Player age must be between 15 and 45.");
    }
}

string Player::getName() const { return name; }
int Player::getAge() const { return age; }
string Player::getBattingStyle() const { return batting_style; }
string Player::getBowlingType() const { return bowling_type; }
int Player::getPerformanceRating() const { return performance_rating; }
int Player::getExperienceLevel() const { return experience_level; }
float Player::getStrikeRate() const { return strike_rate; }
float Player::getEconomyRate() const { return economy_rate; }
int Player::getFitnessLevel() const { return fitness_level; }
string Player::getRole() const { return role; }
float Player::getAverageScore() const { return average_score; }
int Player::getCatchesTaken() const { return catches_taken; }

