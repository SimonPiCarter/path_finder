#include "Window.hpp"

#include <SDL.h>

#include "entity/Entity.hpp"

#include <iostream>

Window::Window(double const & worldScale_p, std::vector<path::Entity*> const & vEntity_p)
    : _window(nullptr)
    , _renderer(nullptr)
    , _fullscreen(false)
    , _worldScale(worldScale_p)
    , _vEntities(vEntity_p)
{
}

Window::~Window()
{
    if (_window)
    {
        SDL_DestroyWindow(_window);
    }
    if (_renderer)
    {
        SDL_DestroyRenderer(_renderer);
    }
    SDL_Quit();
}

/**
 * @brief Initialize window
 **/
bool Window::init(int width_p, int height_p, bool fullscreen_p)
{
    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        std::cout<<"Échec de l'initialisation de la SDL "<<SDL_GetError()<<std::endl;
        return false;
    }

    /* Création de la fenêtre */
    _window = SDL_CreateWindow("Ma première application SDL2", SDL_WINDOWPOS_UNDEFINED,
                                                                SDL_WINDOWPOS_UNDEFINED,
                                                                width_p,
                                                                height_p,
                                                                SDL_WINDOW_SHOWN);
    if (!_window)
    {
        std::cout<<"Erreur de création de la fenêtre: "<<SDL_GetError()<<std::endl;
        return false;
    }

    _renderer = SDL_CreateRenderer(_window,-1,SDL_RENDERER_ACCELERATED); // Création d'un SDL_Renderer utilisant l'accélération matérielle

    if (!_renderer)
    {
        std::cout<<"Erreur de création de l'afficheur: "<<SDL_GetError()<<std::endl;
        return false;
    }


    /* Plein ecran */
    _fullscreen = fullscreen_p;
    if ( fullscreen_p )
    {
        SDL_SetWindowFullscreen(_window,SDL_WINDOW_FULLSCREEN);
    }

    return true;
}

void drawEntity(path::Entity const * entity_p);

/**
 * @brief display the window, reset the canvas
 **/
void Window::display()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
    for ( path::Entity const * entity_l : _vEntities )
    {
        drawEntity(entity_l);
    }
    SDL_RenderPresent(_renderer);
}
/**
 * @brief handle events : q for quit, f for fullscreen
 * @return false if exit event has been called. true otherwise.
 **/
bool Window::handleEvents()
{
    bool quit_l(false);
    SDL_Event event;
    while (SDL_PollEvent(&event)) // Récupération des actions de l'utilisateur
    {
        switch(event.type)
        {
            case SDL_QUIT: // Clic sur la croix
                quit_l=true;
                break;
            case SDL_KEYUP: // Relâchement d'une touche
                if ( event.key.keysym.sym == SDLK_f ) // Touche f
                {
                    // Alterne du mode plein écran au mode fenêtré
                    if ( !_fullscreen )
                    {
                        SDL_SetWindowFullscreen(_window,SDL_WINDOW_FULLSCREEN);
                    }
                    else
                    {
                        SDL_SetWindowFullscreen(_window,0);
                    }
                    _fullscreen = !_fullscreen;
                }
                if ( event.key.keysym.sym == SDLK_q )
                {
                    quit_l = true;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                fprintf(stdout, "Un appuie sur un bouton de la souris :\n");
                fprintf(stdout, "\tfenetre : %d\n",event.button.windowID);
                fprintf(stdout, "\tsouris : %d\n",event.button.which);
                fprintf(stdout, "\tbouton : %d\n",event.button.button);
                fprintf(stdout, "\tposition : %d;%d\n",event.button.x,event.button.y);
                break;
        }
    }

    return !quit_l;
}

void drawCircle(SDL_Renderer *renderer_p, int x_p, int y_p, int radius)
{
   int x = radius - 1;
   int y = 0;
   int tx = 1;
   int ty = 1;
   int err = tx - (radius << 1); // shifting bits left by 1 effectively
                                 // doubles the value. == tx - diameter
   SDL_SetRenderDrawColor(renderer_p, 255, 0, 0, 255);

   while (x >= y)
   {
      //  Each of the following renders an octant of the circle
      SDL_RenderDrawPoint(renderer_p, x_p + x, y_p - y);
      SDL_RenderDrawPoint(renderer_p, x_p + x, y_p + y);
      SDL_RenderDrawPoint(renderer_p, x_p - x, y_p - y);
      SDL_RenderDrawPoint(renderer_p, x_p - x, y_p + y);
      SDL_RenderDrawPoint(renderer_p, x_p + y, y_p - x);
      SDL_RenderDrawPoint(renderer_p, x_p + y, y_p + x);
      SDL_RenderDrawPoint(renderer_p, x_p - y, y_p - x);
      SDL_RenderDrawPoint(renderer_p, x_p - y, y_p + x);

      if (err <= 0)
      {
         y++;
         err += ty;
         ty += 2;
      }
      else if (err > 0)
      {
         x--;
         tx += 2;
         err += tx - (radius << 1);
      }
   }
}

void Window::drawEntity(path::Entity const * entity_p)
{
    path::Vector<int> pxlCoord_l;
    pxlCoord_l.x = static_cast<int>(entity_p->getPosition().x*_worldScale);
    pxlCoord_l.y = static_cast<int>(entity_p->getPosition().y*_worldScale);
    int radius = static_cast<int>(entity_p->getRadius()*_worldScale);
    drawCircle(_renderer,pxlCoord_l.x,pxlCoord_l.y,radius);
}