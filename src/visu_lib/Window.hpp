#pragma once

#include <vector>
#include "entity/Vector.hpp"

struct SDL_Window;
struct SDL_Renderer;
namespace path{ class Entity;}

class Window
{
    public:
        Window(double const & worldScale_p, std::vector<path::Entity*> const & vEntity_p);
        ~Window();

        /**
         * @brief Initialize window
         **/
        bool init(int width_p, int height_p, bool fullscreen_p=false);
        /**
         * @brief display the window, reset the canvas
         **/
        void display();
        /**
         * @brief handle events : q for quit, f for fullscreen
         * @return false if exit event has been called. true otherwise.
         **/
        bool handleEvents();

private:
    void drawEntity(path::Entity const * entity_p);

    void createMove(int x_p, int y_p);

    SDL_Window* _window;
    SDL_Renderer *_renderer;
    bool _fullscreen;
    double _worldScale;
    std::vector<path::Entity*> const & _vEntities;
};