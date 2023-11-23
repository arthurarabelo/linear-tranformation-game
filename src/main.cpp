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
    Point p;
    char op;

    cin >> numInst;
    cin >> numOps;

    SegTree segHeap(numInst);

    int i = 0;
    string str_x;
    string str_y;
    while(i < numOps){
        cin >> op;
        if(op == 'q'){
            i++;
            cin >> tB;
            cin >> tD;
            cin >> x;
            cin >> y;
            p.x = x;
            p.y = y;
            segHeap.query(tB, tD, 1, 0, numInst-1)->LinearTransformation(p);

            str_x = to_string(p.x);
            str_y = to_string(p.y);

            if (str_x.length() > 8) Last8Digits(str_x);

            if (str_y.length() > 8) Last8Digits(str_y);

            cout << str_x << " " << str_y << endl;
        }
        if(op == 'u'){
            i++;
            auto* newMatrix = new Matrix(2,2);
            cin >> inst;
            cin >> *newMatrix;
            segHeap.UpdateMatrix(inst, newMatrix, 1, 0, numInst-1);
        }
    }
}
