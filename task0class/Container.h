#pragma once
#include <vector>
#include "Box.h"


namespace resNS {
    class Container
    {
    private:
        std::vector<Box> container;
        int length;
        int width;
        int height;
        int maxWeight;

        double weight = 0;
        int lastindex = -1;
    public:
        Container(int length, int width, int height, int maxWeight) : length(length), width(width), height(height), maxWeight(maxWeight) {
            container = {};
        }

        Container() : length(0), width(0), height(0), maxWeight(0) {
            container = {};
        }

        ~Container() = default;

        int getLength();

        int getWidth();

        int getHeight();

        int getMaxWeight();

        int push(Box box);

        void erase(int index);

        int size();

        double fullWeight();

        int fullValue();

        Box getByIndex(int index);

        friend std::ostream& operator<<(std::ostream& out, const Container& cont);

        friend std::istream& operator>>(std::istream& in, Container& cont);

        Box operator[](int index);
    };
}