#include <cstdio>

namespace {
    class Rectangle {
    public:
        Rectangle(int width, int height) {
            this->width = width;
            this->height = height;
        }
        int getArea() {
            return width * height;
        }
        int getPerimeter() {
            return 2 * (width + height);
        }
    private:
        int height;
        int width;
    };
}

int main(int argc, char** argv) {
    int width;
    int height;
    std::scanf("%d %d", &width, &height);
    Rectangle rectangle(width, height);
    std::printf("%d %d\n",
                rectangle.getArea(),
                rectangle.getPerimeter());
    return 0;
}
