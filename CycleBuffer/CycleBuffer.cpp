
#include<iostream>
using namespace std;
#define BS  4
//Он работает, я не уверен, что все исключительные ситуации учтены. но чекался код в 3 ночи по остаточному
//принципу. потому надеюсь, что с первого раза написал нормально. если что - перепишу. но местами код выглядит странно
class CB {
    int buf[BS];
    int p = 0;
    int g = 0;
    int field = 0;

public:
    void put(int);
    int get();
   
    void show();
};

void CB::show() {
    cout << "Buffer looks like : ";
    for (int i = 0; i < BS; i++) {
        cout << buf[i] << " ";
    }
    cout << "\n";
}

void CB::put(int num) {
    if (field != BS) {
        buf[p++] = num;
        field++;
    }
    else {
        g++;
        g = (g == BS) ? (0) : (g);
        p = (p == BS) ? (0) : (p);
        buf[p++] = num;

    }
    /*buf[p++] = num;
    p = (p == BS) ? (0) : (p);
    if (field == BS) {
        g++;
        g = (g == BS) ? (0) : (g);
    }*/
}
int CB::get() {
    if (field == 0) {
        cout << "Buffer is empty \n";
        return 0;
    }
    else {
        int num = buf[g++];
        buf[g - 1] = 0;
        if (g == BS)  g = 0; 
        field--;
        return num;
    }
}

void test1() {
    int i = 4;
    CB obj;
    while (i--) {
        obj.put(i);
    }
    obj.show();
    obj.put(5);
    obj.show();
    obj.put(3);
    cout << "The list is ";
    cout << obj.get() << " ";
    while (i < 4) {
        i++;
        cout << obj.get() << " ";
    }
    obj.show();
}

int main() {
    test1();

    return 0;
}