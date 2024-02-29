#include "SimBase.hpp"

void SimBase::draw()
{
    window.clear(prms.clearColor);

    camera.update();

    if (gfx)
    {
        tank.draw();

        for (auto &i : zappers)
        {
            i.draw();
        }

        for (auto &i : pellets)
        {
            i.draw();
        }

        for (auto &i : guppies)
        {
            i.draw();
        }

        for (auto &i : corpses)
        {
            i.draw();
        }
    }

    if (displayText)
    {
        text.print();
    }

    window.display();
}
