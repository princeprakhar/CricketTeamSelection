
#pragma once
#include <string>

class Player {
private:
    std::string name;
    int age;
    std::string batting_style;
    std::string bowling_type;
    int performance_rating;
    int experience_level;
    float strike_rate;
    float economy_rate;
    int fitness_level;
    std::string role;
    float average_score;
    int catches_taken;

public:
    Player(const std::string& name, int age, const std::string& batting_style,
           const std::string& bowling_type, int performance_rating,
           int experience_level, float strike_rate, float economy_rate,
           int fitness_level, const std::string& role, 
           float average_score, int catches_taken);

    std::string getName() const;
    int getAge() const;
    std::string getBattingStyle() const;
    std::string getBowlingType() const;
    int getPerformanceRating() const;
    int getExperienceLevel() const;
    float getStrikeRate() const;
    float getEconomyRate() const;
    int getFitnessLevel() const;
    std::string getRole() const;
    float getAverageScore() const;
    int getCatchesTaken() const;
};

