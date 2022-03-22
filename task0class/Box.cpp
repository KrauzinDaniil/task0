#include "Box.h"

using namespace resNS;

bool Box::operator==(const Box& other)
{
    return this->length == other.length && this->width == other.width && this->height == other.height &&
        this->weight == other.weight && this->value == other.value;
}

bool Box::operator!=(const Box& other)
{
    return !(this->length == other.length && this->width == other.width && this->height == other.height &&
        this->weight == other.weight && this->value == other.value);
}

bool Box::operator<(const Box& other)
{
    return this->length < other.length&& this->width < other.width&& this->height < other.height;
}

bool Box::operator>(const Box& other)
{
    return this->length > other.length && this->width > other.width && this->height > other.height;
}

int Box::boxValueSum(Box* box, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += box[i].getValue();
    }
    return sum;
}

bool Box::smallerThan(Box* box, int size, int value) {
    int tempSum = 0;
    for (int i = 0; i < size; i++) {
        tempSum += box[i].getLength() + box[i].getWidth() + box[i].getHeight();
    }
    return tempSum <= value;
}

double Box::maxBoxOutOfV(Box* box, int size, int maxV) {
    int tempV;
    double maxWeight = 0;
    for (int i = 0; i < size; i++) {
        tempV = box[i].getLength() * box[i].getWidth() * box[i].getHeight();
        if (tempV <= maxV) {
            maxWeight += box[i].getWeight();
        }
    }
    return maxWeight;
}

bool Box::canPack(Box* boxArr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (!(boxArr[i] > boxArr[j] || boxArr[i] < boxArr[j])) {
                return false;
            }
        }
    }
    return true;
}

int Box::getLength() {
    return length;
}

int Box::getWidth() {
    return width;
}

int Box::getHeight() {
    return height;
}

double Box::getWeight() {
    return weight;
}

int Box::getValue() {
    return value;
}

void Box::setLength(int length) {
    this->length = length;
}

void Box::setWidth(int width) {
    this->width = width;
}

void Box::setHeight(int height) {
    this->height = height;
}

void Box::setWeight(double weight) {
    this->weight = weight;
}

void Box::setValue(int value) {
    this->value = value;
}

namespace resNS {
    std::ostream& operator<<(std::ostream& out, const Box& box) {
        out << "Box(" << box.length << ", " << box.width << ", " << box.height << ", "
            << box.weight << ", " << box.value << ")" << std::endl;
        return out;
    }

    std::istream& operator>>(std::istream& in, Box& box) {
        in >> box.length;
        in >> box.width;
        in >> box.height;
        in >> box.weight;
        in >> box.value;
        return in;
    }
}