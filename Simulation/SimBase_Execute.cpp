#include "SimBase.hpp"

void SimBase::execute()
{
    while (window.isOpen())
    {
        update();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::Resized)
            {
                camera.onResize();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Button::Left)
                {
                    camera.onClick();
                }
            }

            if (event.type == sf::Event::MouseWheelMoved)
            {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                float f1 = 2.f / 10.f;
                float f2 = 1.f - f1;

                if (event.mouseWheel.delta > 0)
                {
                    sf::Vector2f target = camera.getCrds() * f2 + mousePos * f1;
                    camera.shift(target, 1);
                }
                else
                {
                    mousePos = camera.getCrds() * 2.f - mousePos;
                    sf::Vector2f target = camera.getCrds() * f2 + mousePos * f1;
                    camera.shift(target, -1);
                }
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }

                if (event.key.code == sf::Keyboard::Space)
                {
                    paused = !paused;
                    text.simState.setString("Sim. state: " + std::string(paused ? "PAUSED" : "RUNNING"));
                }

                if (event.key.code == sf::Keyboard::G)
                {
                    gfx = !gfx;
                    text.gfx.setString("Graphics: " + std::string(gfx ? "ON" : "OFF"));
                }

                if (event.key.code == sf::Keyboard::T)
                {
                    displayText = !displayText;
                }

                if (event.key.code == sf::Keyboard::V)
                {
                    vSync = !vSync;
                    window.setVerticalSyncEnabled(vSync);
                    text.vSync.setString("V. Sync: " + std::string(vSync ? "ON" : "OFF"));
                }

                if (event.key.code == sf::Keyboard::Z)
                {
                    camera.shift(sf::Vector2f(), -2);
                }

                if (event.key.code == sf::Keyboard::F11)
                {
                    sf::ContextSettings ctx = window.getSettings();
                    std::string title = "Neural Guppies - 0.1 beta";

                    if (fullscreen)
                    {
                        fullscreen = false;
                        window.create(sf::VideoMode(prms.WIN_WIDTH, prms.WIN_HEIGHT), title, sf::Style::Default, ctx);
                        sf::Image icon;
                        icon.loadFromFile("gfx/icon.png");
                        window.setIcon(32, 32, icon.getPixelsPtr());
                    }
                    else
                    {
                        fullscreen = true;
                        window.create(sf::VideoMode::getDesktopMode(), title, sf::Style::Fullscreen, ctx);
                    }

                    window.setVerticalSyncEnabled(vSync);
                    camera.onResize();
                }

                if (event.key.code == sf::Keyboard::I)
                {
                    camera.shift(camera.getCrds(), 1, false);
                }

                if (event.key.code == sf::Keyboard::O)
                {
                    camera.shift(camera.getCrds(), -1, false);
                }

                if ( event.key.code == sf::Keyboard::W ||
                     event.key.code == sf::Keyboard::A ||
                     event.key.code == sf::Keyboard::S ||
                     event.key.code == sf::Keyboard::D )
                {
                    float shift = 30.f * camera.getZoom();
                    sf::Vector2f shiftVec;

                    if (event.key.code == sf::Keyboard::W)
                    {
                        shiftVec.y = -shift;
                    }
                    else if (event.key.code == sf::Keyboard::A)
                    {
                        shiftVec.x = -shift;
                    }
                    else if (event.key.code == sf::Keyboard::S)
                    {
                        shiftVec.y = shift;
                    }
                    else if (event.key.code == sf::Keyboard::D)
                    {
                        shiftVec.x = shift;
                    }

                    camera.shift(camera.getCrds() + shiftVec);
                }
            }
        }

        draw();
    }

    //onClose();
}
