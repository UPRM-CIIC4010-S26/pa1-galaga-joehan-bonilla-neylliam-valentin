#pragma once
#include "Enemy.hpp"

class DyEnemy : public Enemy {
    private: 
        float angle = 135;
        float aimAngle = 225;
        bool loop = false;
        Rectangle enemyTexture; // Variable created to store the enemy texture

    public:
        DyEnemy(float x, float y) : Enemy(x, y) { 
            this->cooldown = GetRandomValue(90, 300);
            this->health = 1; 

               if (GetRandomValue(0, 1)) {     // Randomly select one of two possible textures so that enemies don't always look the same
                this->enemyTexture = Rectangle{2, 130, 10, 20};
            } else {
                this->enemyTexture = Rectangle{2, 140, 13, 18};
            }
        }

        void draw() override;
        void update(std::pair<float, float> pos, HitBox target) override;
        void attack(HitBox target) override;
};