#ifndef PLAYER_H
#define PLAYER_H

#include "global.h"
#include "GameObject.h"

class Player : public GameObject {
    public:
        Player(const std::string &name);
        virtual ~Player();

        virtual void update();

        void up();
        void down();
        void left();
        void right();
    
    // private:
};

#endif // PLAYER_H