#ifndef NOBLEDESKTOP_H
#define NOBLEDESKTOP_H

#include "../NobleVM/VirtualMachineGraphics.h"
#include <SFML/Graphics.hpp>

namespace Noble::Desktop
{
    class NobleDesktop final : public VM::VirtualMachineGraphics
    {
    public:
        NobleDesktop();
        void Initialise() override;
        void Update() override;
        void SetPixel(int x, int y, bool value) override;
        bool GetPixel(int x, int y) override;
    protected:
        sf::RenderWindow renderWindow;
        sf::RenderTexture bufferTexture;
        sf::Sprite bufferSprite;
    };
} // Noble::Desktop

#endif //NOBLEDESKTOP_H
