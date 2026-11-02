#include <iostream>
#include <memory>
#include <vector>

class Shape {
public:
    virtual ~Shape() = default;
    virtual std::unique_ptr<Shape> clone() const = 0;
    virtual void draw() const = 0;

    void moveTo(int x, int y) {
        x_ = x;
        y_ = y;
    }

protected:
    Shape(int x, int y) : x_(x), y_(y) {}

    int x_;
    int y_;
};

class Circle final : public Shape {
public:
    Circle(int x, int y, int radius) : Shape(x, y), radius_(radius) {}

    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Circle>(*this);
    }

    void draw() const override {
        std::cout << "Circle at (" << x_ << ", " << y_
                  << "), radius " << radius_ << '\n';
    }

private:
    int radius_;
};

class Rectangle final : public Shape {
public:
    Rectangle(int x, int y, int width, int height)
        : Shape(x, y), width_(width), height_(height) {}

    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Rectangle>(*this);
    }

    void draw() const override {
        std::cout << "Rectangle at (" << x_ << ", " << y_
                  << "), size " << width_ << 'x' << height_ << '\n';
    }

private:
    int width_;
    int height_;
};

int main() {
    std::vector<std::unique_ptr<Shape>> originals;
    originals.push_back(std::make_unique<Circle>(1, 2, 3));
    originals.push_back(std::make_unique<Rectangle>(4, 5, 6, 7));

    for (const auto& original : originals) {
        auto copy = original->clone();
        copy->moveTo(10, 20);

        std::cout << "Original: ";
        original->draw();
        std::cout << "Clone: ";
        copy->draw();
    }
}
