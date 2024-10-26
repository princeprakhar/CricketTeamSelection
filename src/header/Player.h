#pragma once
#include <string>
using namespace std;

class Player {
private:
    string name;
    int age;
    string batting_style;
    string bowling_type;
    int performance_rating;
    int experience_level;
    float strike_rate;
    float economy_rate;
    int fitness_level;
    string role;
    float average_score;
    int catches_taken;

public:
    Player(const string& name, int age, const string& batting_style,
           const string& bowling_type, int performance_rating,
           int experience_level, float strike_rate, float economy_rate,
           int fitness_level, const string& role, 
           float average_score, int catches_taken);

    string getName() const;
    int getAge() const;
    string getBattingStyle() const;
    string getBowlingType() const;
    int getPerformanceRating() const;
    int getExperienceLevel() const;
    float getStrikeRate() const;
    float getEconomyRate() const;
    int getFitnessLevel() const;
    string getRole() const;
    float getAverageScore() const;
    int getCatchesTaken() const;
};

