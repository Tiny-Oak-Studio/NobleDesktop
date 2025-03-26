#include "NobleDesktop.h"

namespace Noble::Desktop
{
    NobleDesktop::NobleDesktop() :
        renderWindow(sf::VideoMode({640, 360}), "NobleDesktop"),
        bufferTexture({64, 36}),
        bufferSprite(bufferTexture.getTexture())
    {
        renderWindow.setView(sf::View(sf::Vector2f(32, 18), sf::Vector2f(64 , 36)));
    }

    void NobleDesktop::Initialise()
    {

    }

    void NobleDesktop::Update()
    {
        if (renderWindow.isOpen())
        {
            while (const std::optional<sf::Event> event = renderWindow.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                {
                    renderWindow.close();
                }

                bufferTexture.clear();
                //Draw stuff here
                bufferTexture.display();

                renderWindow.clear();
                renderWindow.draw(bufferSprite);
                renderWindow.display();
            }
        }

    }

    void NobleDesktop::SetPixel(int x, int y, bool value)
    {

    }

    bool NobleDesktop::GetPixel(int x, int y)
    {
        return false;
    }

} // Noble::Desktop