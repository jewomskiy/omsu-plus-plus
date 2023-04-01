#include <iostream>
#include <vector>
#include "boxClass.h"
#include "errorValues.h"
using namespace std;

class Container{
private:
    int lenght, height, width, maxWeight;
    vector<Box> ArrayOfBoxes;
public:
    Container(){
        lenght = 0;
        height = 0;
        width = 0;
        maxWeight = 0;
        ArrayOfBoxes = {};
    }

    friend ostream &operator<<(ostream &o, Container &a) {
        o << "Lenght: " << a.lenght << "\tHeight: " << a.height << "\tWidth: " << a.width << "\tMax Weight: " << a.maxWeight << "\tBoxes in: " << endl;
        for(int i; i < a.ArrayOfBoxes.size(); i++){
            cout << a.ArrayOfBoxes[i];
        };
        return o;
    }

    friend istream &operator>>(istream &i, Container &a){
        i >> a.lenght >> a.height >> a.width >> a.maxWeight;
        return i;
    }

    Box &operator[](int index){
        return this->ArrayOfBoxes[index];
    }

    int getSize(){
        return this->ArrayOfBoxes.size();
    }

    int summOfWeight(){
        int n = getSize();
        int weight = 0;
        for (int i = 0; i < n; i++){
            weight += this->ArrayOfBoxes[i].getWeight();
        }
        return weight;
    }

    int summOfValue(){
        int n = getSize();
        int value = 0;
        for (int i = 0; i < n; i++){
            value += this->ArrayOfBoxes[i].getValue();
        }
        return value;
    }

    Box getBox(int index){
        return this->ArrayOfBoxes[index];
    }

    int pushBox(Box box){
        int n = getSize();
        int weight = summOfWeight();
        if (((weight + box.getWeight()) < this->maxWeight) && (box.getLenght() <= this->lenght) && (box.getHeight() <= this->height) ){
            this->ArrayOfBoxes.push_back(box);
        } else {
            throw errorValues();
        }
        return n;
    }

//    После метода не выводятся коробки

    void deleteItem(int index){
        auto iter = this->ArrayOfBoxes.cbegin();
        cout << getSize();
        this->ArrayOfBoxes.erase(iter + index);
        cout << getSize();
    }
};