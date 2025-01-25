// 2126. Destroying Asteroids
// https://leetcode.com/problems/destroying-asteroids/

class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

    // Process each asteroid
    for (int asteroid : asteroids) {
        if (mass >= asteroid) {
            // Destroy the asteroid and increase the planet's mass
            mass += asteroid;
        } else {
            // The planet is destroyed if it cannot destroy this asteroid
            return false;
        }
    }

    // If all asteroids are destroyed, return true
    return true; 
    }
};