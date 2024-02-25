#include "Prototype.h"
#include <cmath>
#include <ctime>

void Prototype::putOnMap()
{
    roundCoords();

    auto start_x{ ix };
    auto end_x{ ix + width };
    auto start_y {iy};
    auto end_y{ iy + height };

    if (iy < 0) {
        start_y = 0;
    }
    else {
        start_y = iy;
    }

    if (iy + height > map->getHeight() - 1) {
        end_y = map->getHeight() - 1;
    }
    else {
        end_y = iy + height;
    }

    if (ix + width > map->getWidth() - 1) {
        end_x = map->getWidth() - 1;
    }
    else {
        end_x = ix + width;
    }

    if (ix < 0) {
        start_x = 0;
    }

    if (ix < map->getWidth()) {
        for (int i = start_y; i < end_y; i++)
            for (int j = start_x; j < end_x; j++)
                map->field[i][j] = sym;
    }
}

void Prototype::roundCoords()
{
    ix = static_cast<int>(round(x));
    iy = static_cast<int>(round(y));
}

void Prototype::setTime() { m_time = clock(); }