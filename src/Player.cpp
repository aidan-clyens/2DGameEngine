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
        for (sf::Keyboard::Key key : input_manager->get_last_keys_pressed()) {
            switch (key) {
                case sf::Keyboard::W:
                    up();
                    break;
                case sf::Keyboard::S:
                    down();
                    break;
                case sf::Keyboard::A:
                    left();
                    break;
                case sf::Keyboard::D:
                    right();
                    break;
                default:
                    break;
            }
        }
    }
}

void Player::up() {
    m_position.y -= PLAYER_SPEED;
}

void Player::down() {
    m_position.y += PLAYER_SPEED;
}

void Player::left() {
    m_position.x -= PLAYER_SPEED;
}

void Player::right() {
    m_position.x += PLAYER_SPEED;
}