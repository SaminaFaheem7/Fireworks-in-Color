#include <cassert>
#include <array>
#include <vector>
#include "Renderer.h"
#include "Pixel.h"

using namespace std;

Renderer::~Renderer() {

}
void Renderer::render_art(array<size_t, 2> pos, const vector<std::vector<char>> &art, PixelBuffer &buffer) const {

    if (pos[0] + art[0].size() > buffer.width()) {
        pos[0] -= (pos[0] + art[0].size() - buffer.width() + 1);
    }

    if (pos[1] + art.size() > buffer.height()) {
        pos[1] -= (pos[1] + art.size() - buffer.height() + 1);
    }

    for (auto i = 0; i < art.size(); i++) {
        for (auto j = 0; j < art[i].size(); j++) {
            array<size_t, 2> posi_j{pos[0] + j, pos[1] + i};
            buffer.set(posi_j, Pixel(art[i][j], render_color()));
        }
    }
}

void Renderer::render_trace(array<size_t, 2> pos, const vector<vector<char>> &art, PixelBuffer &buffer) const {

    if (pos[0] + art[0].size() > buffer.width()) {
        pos[0] -= (pos[0] + art[0].size() - buffer.width() + 1);
    }

    if (pos[1] + art.size() > buffer.height()) {
        pos[1] -= (pos[1] + art.size() - buffer.height() + 1);
    }

    auto x = pos[0] + (int) (art[0].size() / 2.0);
    auto y = pos[1] + art.size();

    if (x == 30)       // If the firework is in between then "|"
    {
        for (size_t i = y; i < buffer.height(); i++) {
            array<size_t, 2> pos2{x, y};
            buffer.set(pos2, Pixel('|', render_color()));
            y++;
        }
    } else if (x > 30) {    // If the firework lies on the left side then the string is " / "
        for (int i = y; i < buffer.height(); i++) {
            array<size_t, 2> pos2{x, y};
            buffer.set(pos2, Pixel('/', render_color()));
            x--;
            y++;
        }
    } else if (x < 30) {// If the firework lies on the right side then the string is "\"
        for (int i = y; i < buffer.height(); i++) {
            array<size_t, 2> pos2{x, y};
            buffer.set(pos2, Pixel('\\', render_color()));
            x++;
            y++;
        }
    }
}

SolidColor::SolidColor(Pixel::Color color) {
    _color = color;
}

SolidColor::~SolidColor()
{

}

Pixel::Color SolidColor::render_color() const {
    return _color;
}

RandomColor::RandomColor() {

}

RandomColor::~RandomColor(){

}


Pixel::Color RandomColor::render_color() const {
    return Pixel::random_color();
}