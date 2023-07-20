#include <iostream>
using namespace std;

class math{
    public:
        int length;
        int breadth;
    int area(){
        return length*breadth;
    }
};

int main(){
    math obj;
    cin >> obj.length;
    cin >> obj.breadth;

    cout << obj.area() << endl;
    return 0;
}