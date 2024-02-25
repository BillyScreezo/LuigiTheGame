#include <iostream>
#include <memory>

#include "Map.h"
#include "Drawing.h"

int main()
{
    std::unique_ptr<Map> map(new Map);

    while (1) {
        map->fillSpace();
        map->printMap();
    }

    return 0;
}

