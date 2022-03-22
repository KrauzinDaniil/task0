#include <iostream>
#include "Box.h"
#include "Container.h"

using namespace resNS;

int main()
{
    Box box1(4, 4, 4, 10, 100);
    Box box2(1, 1, 1, 11, 200);
    Box box3(2, 2, 2, 1, 300);
    Box box4(3, 3, 3, 1, 300);
    Box* boxArr;
    boxArr = new Box[4];
    boxArr[0] = box1;
    boxArr[1] = box2;
    boxArr[2] = box3;
    boxArr[3] = box4;
    std::cout << "box1 and box2 equal? " << (box1 == box2) << std::endl;
    std::cout << "BoxArr sum value: " << Box::boxValueSum(boxArr, 4) << std::endl;
    std::cout << "All boxess len,wid,hei sum in array smaller: " << Box::smallerThan(boxArr, 4, 100) << std::endl;
    std::cout << "Maximum Boxes weight, which volume smaller than inserted value: " << Box::maxBoxOutOfV(boxArr, 4, 1)
        << std::endl << std::endl;
    std::cout << "Current array can be packed: " << Box::canPack(boxArr, 4) << std::endl;
    Box test;
    std::cout << "Insert box  length, width, height, weight, value:" << std::endl;
    std::cin >> test;
    std::cout << "Inserted box:" << std::endl << test << std::endl;

    Container container(100, 100, 100, 100);
    container.push(box1);
    container.push(box2);
    container.push(box3);
    container.push(box4);
    std::cout << container << std::endl;
    std::cout << "Container box i = 1: " << container[1];
    std::cout << "Number of boxes in container: " << container.size() << std::endl;
    std::cout << "Sum weight of container: " << container.fullWeight() << std::endl;
    std::cout << "Sum value of container: " << container.fullValue() << std::endl;
    return 0;
}