#pragma once

#include <SFML/Graphics.hpp>
#include "window.h"
#include "particle_system.h"


class Game
{
public:
    Game();
    virtual ~Game() = default;

    void Run();
    void HandleInput();
    void Update(const float dt);
    void Render();


private:
    Window main_window_;
    ParticleSystem particles_;

};