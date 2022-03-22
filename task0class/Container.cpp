#include "Container.h"

using namespace resNS;

int Container::getLength() {
    return length;
}

int Container::getWidth() {
    return width;
}

int Container::getHeight() {
    return height;
}

int Container::getMaxWeight() {
    return maxWeight;
}

int Container::push(Box box) {
    this->weight += box.getWeight();
    if (this->weight > maxWeight) {
        throw std::exception("max weight exceeded");
    }
    else {
        container.push_back(box);
        lastindex++;
    }
    return lastindex;
}

void Container::erase(int index) {
    container.erase(container.begin() + index);
    lastindex--;
}

int Container::size() {
    return container.size();
}

double Container::fullWeight() {
    double weightSum = 0;
    for (int i = 0; i < size(); i++) {
        weightSum += container[i].getWeight();
    }
    return weightSum;
}

int Container::fullValue() {
    int valueSum = 0;
    for (int i = 0; i < size(); i++) {
        valueSum += container[i].getValue();
    }
    return valueSum;
}

Box Container::getByIndex(int index) {
    if (index < 0 || index > size() - 1) {
        throw std::exception("Container index out of range");
    }
    else {
        return container[index];
    }
}

Box Container::operator[] (int index) {
    if (index < 0 || index > this->lastindex) {
        throw std::exception("Container index out of range");
    }
    else {
        return container[index];
    }
}

namespace resNS {
    std::ostream& operator<<(std::ostream& out, const Container& cont) {
        out << "Container: " << cont.length << ", " << cont.width << ", " << cont.height << ", "
            << cont.maxWeight << ";" << std::endl << "Boxes: " << std::endl;
        for (int i = 0; i < cont.container.size(); i++) {
            out << cont.container[i];
        }
        return out;
    }

    std::istream& operator>>(std::istream& in, Container& cont) {
        in >> cont.length;
        in >> cont.width;
        in >> cont.height;
        in >> cont.maxWeight;
        return in;
    }
}