#include <iostream>
#include "cmake-build-debug/containerClass.h"
using namespace std;
#define N 3



int main() {
    Box arrayOfBox[N];
    Box first;
    first.setHeight(10);
    first.setLenght(10);
    first.setWidth(10);
    first.setWeight(3);
    first.setValue(300);
    Box second;
    second.setHeight(5);
    second.setLenght(5);
    second.setWidth(5);
    second.setWeight(2);
    second.setValue(4000);
    Box third;
    third.setHeight(4);
    third.setLenght(4);
    third.setWidth(4);
    third.setWeight(1);
    third.setValue(4000);
    arrayOfBox[0] = first;
    arrayOfBox[1] = second;
    arrayOfBox[2] = third;
    int res = valueOfAllBoxes(arrayOfBox);
    cout << res << endl;
    cout << maxValue(arrayOfBox, 1000) << endl;
    cout << maxWeight(arrayOfBox, 1001) << endl;
    cout << packingBoxes(arrayOfBox) << endl;
    cout << (first == second) << endl;
    cout << first << endl;
    Container contForBox;
    cin >> contForBox;
    contForBox.pushBox(first);
    contForBox.pushBox(second);
    contForBox.pushBox(third);
    cout << contForBox;
    contForBox.deleteItem(1);
    cout << "-----------" << endl;
    cout << contForBox;
    return 0;
}
