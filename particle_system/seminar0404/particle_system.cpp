#include "particle_system.h"
#include <SFML/Graphics.hpp>

extern const sf::Vector2u WINDOW_SIZES;

Particle::Particle(const sf::Vector2f position,
    const sf::Vector2f velocity, 
    const sf::Vector2f acceleration,
    const float radius)
    : position_(position)
    , velocity_(velocity)
    , acceleration_(acceleration)
    , radius_(radius)
{
    shape_.setRadius(radius);
    shape_.setFillColor(sf::Color::Yellow);
    shape_.setOrigin(sf::Vector2f(radius, radius));
    shape_.setPosition(sf::Vector2f(position));
}

const int ParticleSystem::GetSize()
{
    return particles_.size();
}

void Particle::Update(const float dt)
{
    position_ += velocity_ * dt;
    velocity_ += acceleration_ * dt;

    if (position_.x < radius_)
    {
        position_.x = radius_;
        velocity_.x = -velocity_.x / 2.0f;
    }

    if (position_.x > WINDOW_SIZES.x)
    {
        position_.x = WINDOW_SIZES.x - radius_;
        velocity_.x = -velocity_.x / 2.0f;
    }

    if (position_.y < radius_)
    {
        position_.y = radius_;
        velocity_.y = -velocity_.y / 2.0f;
    }
    const float bottom_gap = 50.0f;

    if (position_.y + radius_ + bottom_gap > WINDOW_SIZES.y)
    {
        position_.y = WINDOW_SIZES.y - radius_ - bottom_gap;
        velocity_.y= -velocity_.y / 2.0f;
    }
}


void Particle::Render(sf::RenderWindow& window)
{
    shape_.setPosition(position_);
    shape_.setRadius(radius_);

    window.draw(shape_);
    
}


void Particle::Push(const sf::Vector2f delta_velocity)
{
    velocity_ += delta_velocity;
}

using ParticleID = size_t;

ParticleID ParticleSystem::AddParticle(
    sf::Vector2f position, sf::Vector2f velocity,
    sf::Vector2f acceleration, float radius)
{
    Particle new_particle(position, velocity, acceleration, radius);
    particles_.push_back(new_particle);
    return particles_.size();
}

void ParticleSystem::RemoveParticle(const ParticleID particle_id)
{
    if (particle_id <= particles_.size())
    {
        particles_.erase(particle_id);
    }
}


const Particle& ParticleSystem::GetParticleByID(const ParticleID particle_id)
{
    return particles_[particle_id];
}


void ParticleSystem::Push(const sf::Vector2f delta_velocity)
{
    for (int i = 0; i < particles_.size(); i++)
    {
        particles_[i].Push(delta_velocity);
    }
}


void ParticleSystem::Update(const float dt)
{
    for (int i = 0; i < particles_.size(); i++)
    {
        particles_[i].Update(dt);
    }
}

void ParticleSystem::Render(sf::RenderWindow& window)
{
    for (int i = 0; i < particles_.size(); i++)
    {
        particles_[i].Render(window);
    }
}