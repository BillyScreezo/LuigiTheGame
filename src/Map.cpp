#include "Map.h"

#include <cstring>
#include <algorithm>

using namespace std;

Map::Map()
{
	this->width = 100;
	this->height = 25;

	field = new char* [height];

	for (uint32_t i = 0; i < height; i++)
		field[i] = new char[width];
}

Map::Map(uint32_t width, uint32_t height) : width(width), height(height)
{
	field = new char*[height];

	for (uint32_t i = 0; i < height; i++)
		field[i] = new char[width];
}

void Map::fillSpace()
{
	for (uint32_t i = 0; i < width - 1; i++)
		field[0][i] = ' ';
	field[0][width - 1] = '\0';

	for (uint32_t i = 1; i < height; i++)
        memcpy(field[i], field[0], width);
}

void Map::makePicture()
{
    std::vector<Object> tmp;
    auto map_width = this->width;
    std::for_each(obj_list.begin(), obj_list.end(), [&tmp, &map_width](const Object& a)
        {
            auto _x = a.getX();
            if (_x > 0 && _x < (int32_t) map_width)
                tmp.push_back(a);
        }
    );

    for (const auto& obj: tmp) {
        auto _x = obj.getX();
        auto _y = obj.getY();
        auto _width = obj.getWidth();
        auto _height = obj.getHeight();

        auto model = obj.getModel();

        auto last_x = (_x + _width < this->width) ? _x + _width : this->width;
        auto last_y = (_x + _height < this->height) ? _y + _height : this->height;

        for (uint32_t i = (uint32_t) _y, k = 0; i < last_y; i++, k++) {
            for (uint32_t j = (uint32_t) _y, m = 0; j < last_x; j++, m++) {
                this->field[i][j] = model[k][m];
            }
        }
    }
}

void Map::printMap()
{
	for (uint32_t i = 0; i < height; i++)
		std::cout << field[i] << std::endl;
}

int Map::getWidth()
{
	return width;
}

int Map::getHeight()
{
	return height;
}

void Map::putObjectOnMap(Object &obj)
{
    this->obj_list.push_back(obj);
}

Map::~Map()
{
	for (uint32_t i = 0; i < height; i++)
		delete[] field[i];
	delete[] field;
}
