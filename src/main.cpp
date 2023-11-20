#include <iostream>
#include "segTree.hpp"
#include <string>
using namespace std;

void Last8Digits(string &str){
    str = str.substr(str.length() - 8);
}

int main(){
    int numInst, inst, numOps;
    int tB, tD;
    long unsigned int x, y;
    Matrix newMatrix(2, 2);
    Matrix queryMatrix(2, 2);
    Point initial_point;
    Point result;
    char op;

    cin >> numInst;
    cin >> numOps;

    Heap segHeap(numInst);
    segHeap.build(1, 0, numInst-1);

    int i = 0;
    string str_x;
    string str_y;
    while(i <= numOps){
        cin >> op;
        if(op == 'q'){
            cin >> tB;
            cin >> tD;
            cin >> x;
            cin >> y;
            initial_point.x = x;
            initial_point.y = y;
            queryMatrix = segHeap.query(tB, tD, 1, 0, numInst-1);
            result = queryMatrix.LinearTransformation(initial_point);

            str_x = to_string(result.x);
            str_y = to_string(result.y);

            if (str_x.length() > 8) Last8Digits(str_x);

            if (str_y.length() > 8) Last8Digits(str_y);

            cout << str_x << " " << str_y << endl;
        }
        if(op == 'u'){
            cin >> inst;
            cin >> newMatrix;
            segHeap.UpdateMatrix(inst, newMatrix);
        }
        i++;
    }
}