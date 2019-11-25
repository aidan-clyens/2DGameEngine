#include "GameObject.h"

GameObject::GameObject(const std::string &name):
m_texture_name(name),
m_position(sf::Vector2f(0, 0))
{
    texture_manager->load_texture(m_texture_name);
}

GameObject::GameObject(const std::string &name, sf::Vector2f pos):
m_texture_name(name),
m_position(pos)
{
    texture_manager->load_texture(m_texture_name);
}

GameObject::~GameObject() {
    //  Empty
}

void GameObject::update() {

}

void GameObject::render(sf::RenderWindow &render_window) {
    sf::Texture texture = texture_manager->get_texture(m_texture_name);
    sf::Sprite sprite(texture);

    sprite.setPosition(m_position);
    render_window.draw(sprite);
}