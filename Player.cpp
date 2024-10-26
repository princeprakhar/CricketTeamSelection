
#include "Player.h"
#include <stdexcept>

Player::Player(const std::string& name, int age, const std::string& batting_style,
               const std::string& bowling_type, int performance_rating,
               int experience_level, float strike_rate, float economy_rate,
               int fitness_level, const std::string& role, 
               float average_score, int catches_taken) 
    : name(name), age(age), batting_style(batting_style), 
      bowling_type(bowling_type), performance_rating(performance_rating), 
      experience_level(experience_level), strike_rate(strike_rate), 
      economy_rate(economy_rate), fitness_level(fitness_level), 
      role(role), average_score(average_score), catches_taken(catches_taken) {
    
    if (performance_rating < 1 || performance_rating > 10) {
        throw std::invalid_argument("Performance rating must be between 1 and 10.");
    }
    if (age < 15 || age > 45) {
        throw std::invalid_argument("Player age must be between 15 and 45.");
    }
}

std::string Player::getName() const { return name; }
int Player::getAge() const { return age; }
std::string Player::getBattingStyle() const { return batting_style; }
std::string Player::getBowlingType() const { return bowling_type; }
int Player::getPerformanceRating() const { return performance_rating; }
int Player::getExperienceLevel() const { return experience_level; }
float Player::getStrikeRate() const { return strike_rate; }
float Player::getEconomyRate() const { return economy_rate; }
int Player::getFitnessLevel() const { return fitness_level; }
std::string Player::getRole() const { return role; }
float Player::getAverageScore() const { return average_score; }
int Player::getCatchesTaken() const { return catches_taken; }

