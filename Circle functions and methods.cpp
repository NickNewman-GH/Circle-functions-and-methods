#include <iostream>
#include <vector>

struct Circle {
    float x, y, radius;
    char label;

    // constructor
    Circle(float x_, float y_, float radius_, char label_) {
        x = x_;
        y = y_;
        radius = radius_;
        label = label_;
    }
    // destructor
    ~Circle() {
    }

    float from_origin() {
        return sqrt(x * x + y * y);
    }

    float to_second_center(Circle c) {
        return sqrt(pow(abs(x - c.x), 2) + pow(abs(y - c.y), 2));
    }
    
    float to_X(){
        if (abs(y) > radius) {
            if (y > 0)
                return y - radius;
            else
                return y + radius;
        }
        else
            return 0;
    }

    float from_circle() {
        return sqrt(x * x + y * y) - radius;
    }

    bool can_be_unside(Circle c) {
        if (radius < c.radius)
            return true;
        else
            return false;
    }

    bool is_circles_cross(Circle c) {
        if (sqrt(pow(abs(x - c.x), 2) + pow(abs(y - c.y), 2)) >= radius + c.radius)
            return false;
        else
            return true;
    }
};

float from_origin(Circle c) {
    return sqrt(c.x * c.x + c.y * c.y);
}

float to_second_center(Circle c, Circle c1) {
    return sqrt(pow(abs(c.x - c1.x), 2) + pow(abs(c.y - c1.y), 2));
}

float to_X(Circle c) {
    if (abs(c.y) > c.radius) {
        if (c.y > 0)
            return c.y - c.radius;
        else
            return c.y + c.radius;
    }
    else
        return 0;
}

float from_circle(Circle c) {
    return sqrt(c.x * c.x + c.y * c.y) - c.radius;
}

bool can_be_unside(Circle c, Circle c1) {
    if (c.radius < c1.radius)
        return true;
    else
        return false;
}

bool is_circles_cross(Circle c, Circle c1) {
    if (sqrt(pow(abs(c.x - c1.x), 2) + pow(abs(c.y - c1.y), 2)) >= c.radius + c1.radius)
        return false;
    else
        return true;
}

//--TO-DO--- Функция отражения по Y, Отразить все окружности из нижней полуплоскости в верхнюю

void y_reflect(std::vector<Circle> &mass) {
    auto it = mass.begin();
    while (it != mass.end()) {
        it->y = -it->y;
        ++it;
    }
}

void circles_up(std::vector<Circle>& mass) {
    auto it = mass.begin();
    while (it != mass.end()) {
        it->y = abs(it->y);
        ++it;
    }
}

int main()
{
    Circle c(10, 20, 2, 'a');
    Circle c1(5, 40, 3, 'b');
    Circle c2(-20, 10, 4, 'c');
    
    std::cout << c.from_origin() << std::endl;
    std::cout << c.to_second_center(c1) << std::endl;
    std::cout << c.to_X() << std::endl;
    std::cout << c.from_circle() << std::endl;
    std::cout << c.can_be_unside(c1) << std::endl;
    std::cout << c.is_circles_cross(c1) << std::endl;

    std::cout << "-----------------------------" << std::endl;

    std::cout << from_origin(c) << std::endl;
    std::cout << to_second_center(c, c1) << std::endl;
    std::cout << to_X(c) << std::endl;
    std::cout << from_circle(c) << std::endl;
    std::cout << can_be_unside(c, c1) << std::endl;
    std::cout << is_circles_cross(c, c1) << std::endl;

    std::cout << "-----------------------------" << std::endl;

    std::vector<Circle> mass1 = { c, c1, c2 };
    std::cout << mass1[0].y << ", " << mass1[1].y << ", " << mass1[2].y << ", " << std::endl;
    y_reflect(mass1);
    std::cout << mass1[0].y << ", " << mass1[1].y << ", " << mass1[2].y << ", " << std::endl;

    std::cout << "-----------------------------" << std::endl;

    c1.y = -10;

    std::vector<Circle> mass2 = { c, c1, c2 };
    std::cout << mass2[0].y << ", " << mass2[1].y << ", " << mass2[2].y << ", " << std::endl;
    circles_up(mass2);
    std::cout << mass2[0].y << ", " << mass2[1].y << ", " << mass2[2].y << ", " << std::endl;
}