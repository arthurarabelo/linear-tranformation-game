#include <iostream>
#include "segTree.hpp"
#include <string>
using namespace std;

//modifica a string parâmetro substituindo-a pelos seus últimos 8 dígitos
void Last8Digits(string &str){
    str = str.substr(str.length() - 8);
}

int main(){
    int numInst, inst, numOps;
    int tB, tD;
    long unsigned int x, y;
    char op;

    //lê o número de instantes e de operações
    cin >> numInst;
    cin >> numOps;

    //avisa se o número de instantes ou operações são iguais a 0
    if(numOps == 0){
        cout << "WARNING: você não poderá realizar nenhuma operação." << endl;
    }
    if(numInst == 0){
        cout << "WARNING: o número de instantes é 0." << endl;
    }

    SegTree segHeap(numInst);
//    segHeap.build(1, 0, numInst);

    int i = 0;
    string str_x;
    string str_y;
    while(i < numOps){
        //lê operação a ser realizada
        cin >> op;
        if(op == 'q'){
            cin >> tB;
            cin >> tD;

            //testa se o intervalo a ser consultado está fora do intervalo dado pelos instantes
            if(tB < 0 || tD >= numInst){
                cerr << "Intervalo inválido" << endl;
                continue;
            }

            //lê as coordenadas do ponto
            cin >> x;
            cin >> y;

            //declara e atribui as coordenadas do ponto
            Point p;
            p.x = x;
            p.y = y;

            //chama a função query, que retorna uma matriz, e desta matriz chama a função de transformação linear
            segHeap.query(tB, tD, 1, 0, numInst-1).LinearTransformation(p);

            //passa os valores do ponto para strings e chama função Last8Digits
            str_x = to_string(p.x);
            str_y = to_string(p.y);
            if (str_x.length() > 8) Last8Digits(str_x);
            if (str_y.length() > 8) Last8Digits(str_y);

            cout << str_x << " " << str_y << endl;
            i++;
        }
        else if(op == 'u'){
            //declara a nova matriz que atualizará a árvore de segmentação
            Matrix newMatrix(2,2);

            //lê o instante a ser atualizado
            cin >> inst;

            //testa se o instante está dentro do intervalo permitido
            if(inst < 0 || inst >= numInst){
                cerr << "Intervalo inválido" << endl;
                continue;
            }

            //lê a nova matriz e chama função update
            cin >> newMatrix;
            segHeap.UpdateMatrix(inst, newMatrix, 1, 0, numInst-1);
            i++;
        }
        else{
            cerr << "Operação Inválida" << endl;
            continue;
        }
    }
}
