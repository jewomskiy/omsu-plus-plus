#include <iostream>

using namespace std;
#define N 3


class Box {
private:
    int lenght, width, height, value;
    double weight;
public:
    bool operator==(const Box &boxB) const {
        return this->lenght == boxB.lenght && this->height == boxB.height && this->width == boxB.width;
    }

    friend ostream &operator<<(ostream &o, Box &a) {
        o << "Lenght: " << a.lenght << "\tHeight: " << a.height << "\tWidth: " << a.width << endl;
        return o;
    }


    int getLenght() {
        return this->lenght;
    }

    int getWidth() {
        return this->width;
    }

    int getHeight() {
        return this->height;
    }

    int getValue() {
        return this->value;
    }

    double getWeight() {
        return this->weight;
    }

    void setLenght(int lenght) {
        this->lenght = lenght;
    }

    void setWidth(int width) {
        this->width = width;
    }

    void setHeight(int height) {
        this->height = height;
    }

    void setValue(int value) {
        this->value = value;
    }

    void setWeight(double weight) {
        this->weight = weight;
    }

};

int valueOfAllBoxes(Box arr[]) {
    int result = 0;
    for (int i = 0; i < N; i++) {
        result += arr[i].getValue();
    }
    return result;
}

bool maxValue(Box arr[], int value) {
    int summ = 0;
    for (int i = 0; i < N; i++) {
        summ += arr[i].getLenght() + arr[i].getWidth() + arr[i].getHeight();
    }
    if (summ <= value) return true;
    else return false;
}

void bubbleSort(Box arr[]) {
    int len = N;
    while (len--) {
        bool swapped = false;

        for (int i = 0; i < N; i++) {
            if (((arr[i].getWidth()) < (arr[i + 1].getWidth())) && ((arr[i].getLenght()) < (arr[i + 1].getLenght())) &&
                ((arr[i].getHeight()) < (arr[i + 1].getHeight()))) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

int maxWeight(Box arr[], int maxV) {
    int maxW = 0;
    int volume = 0;
    for (int i = 0; i < N; i++) {
        volume = arr[i].getLenght() * arr[i].getHeight() * arr[i].getWidth();
        if (volume <= maxV && arr[i].getWidth() > maxW) maxW = arr[i].getWidth();
    }
    return maxW;
}

bool packingBoxes(Box arr[]) {
    bool res = true;
    bubbleSort(arr);
    for (int i = 0; i < N; i++) {
        if (((arr[i].getWidth()) <= (arr[i + 1].getWidth())) && ((arr[i].getLenght()) <= (arr[i + 1].getLenght())) &&
            ((arr[i].getHeight()) <= (arr[i + 1].getHeight()))) {
            res = false;
        }
    }
    return res;
}
