#include "Player.h"

Player::Player(const std::string &name):
GameObject(name)
{
    // Empty
}

Player::~Player() {

}

void Player::update() {
    if (input_manager->get_key_pressed()) {
        switch (input_manager->get_last_key_pressed()) {
            case sf::Keyboard::W:
                m_position.y += 2;
                break;
            case sf::Keyboard::S:
                m_position.y -= 2;
                break;
            case sf::Keyboard::A:
                m_position.x += 2;
                break;
            case sf::Keyboard::D:
                m_position.x -= 2;
                break;
            default:
                break;
        }
    }
}