#pragma once
#include <iostream>

namespace resNS {
    class Box {
    private:
        int length, width, height;
        double weight;
        int value;
    public:
        Box(int length, int width, int height, double weight, int value) :
            length(length), width(width), height(height), weight(weight), value(value) {}

        Box() : length(0), width(0), height(0), weight(0), value(0) {}

        ~Box() = default;

        int getLength();

        int getWidth();

        int getHeight();

        double getWeight();

        int getValue();

        void setLength(int length);

        void setWidth(int width);

        void setHeight(int height);

        void setWeight(double weight);

        void setValue(int value);

        bool operator==(const Box& other);

        bool operator!=(const Box& other);

        bool operator<(const Box& other);

        bool operator>(const Box& other);

        friend std::ostream& operator<<(std::ostream& out, const Box& box);

        friend std::istream& operator>>(std::istream& in, Box& box);

        static int boxValueSum(Box* box, int size);

        static bool smallerThan(Box* box, int size, int value);

        static double maxBoxOutOfV(Box* box, int size, int maxV);

        static bool canPack(Box* boxArr, int size);
    };
}