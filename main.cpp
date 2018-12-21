#include <iostream>
#include <memory>
#include <cstdlib>

#include "Figure.h"
#include "Vector.h"
#include "TAllocationBlock.h"

using std::cin;
using std::cout;
using std::endl;

void menu();

int main() {
    int key;
    int index;
    int a = 0;
    int b = 0;
    int c = 0;

    std::shared_ptr<Figure> tri;
    // TMyVector <Figure> vector(5);
    TMyVector<Figure> *vector = new TMyVector <Figure> (10);
    Trapeze *t = nullptr;
    Pentagon *r = nullptr;
    Rhombus *f = nullptr;
    do {
        menu();
        cin >> key;
        switch(key) {
            case 1:
                cout << "Enter sides of trapeze" << endl;
                cin >> a >> b >> c;
                t = new Trapeze(a, b, c);
                tri = std::shared_ptr<Figure>(t);
                vector->Push(tri);
                break;
            case 2:
                cout << "Enter sides of pentagon" << endl;
                cin >> a >> b;
                r = new Pentagon(a, b);
                tri = std::shared_ptr<Figure>(r);
                vector->Push(tri);
                break;
            case 3:
                cout << "Enter sides of rhombus" << endl;
                cin >> a;
                f = new Rhombus(a);
                tri = std::shared_ptr<Figure>(f);
                vector->Push(tri);
                break;
            case 4:
                cout << "Enter index of figure" << endl;
                cin >> index;
                if(index >= vector->GetSize()) {
                    cout << "Figure not found" << endl;
                } else {
                        vector->Get(index);
                }
                break;
            case 5:
                if(vector->GetSize() > 0) {
                    vector->Delete();
                } else {
                    cout << "Figure not found" << endl;
                }
                break;
            case 6:
                vector->~TMyVector();
                key = 0;
                break;
            case 7:
                cout << *vector;
                break;
            case 8:
                vector->MySort(0, vector->GetSize() - 1);
                for(auto i : *vector) {
                    (*i).Print();
                }
                break;
            case 9:
                vector->Quicksort_parallel(0, vector->GetSize() - 1);
                for(auto i : *vector) {
                    (*i).Print();
                }
                break;
            case 0:
                break;
            default:
                cout << "Unknown command" << endl;
                break;
        }
    } while(key);
    delete vector;
    return 0;
}

void menu() {
    cout << "Enter:" << endl;
    cout << "1)For add Trapeze" << endl;
    cout << "2)For add Pentagon" << endl;
    cout << "3)For add Rhombus" << endl;
    cout << "4)For get figure." << endl;
    cout << "5)For delete figure." << endl;
    cout << "6)For delete all figures." << endl;
    cout << "7)Print vector." << endl;
    cout << "8)Print with iterator and qsort." << endl;
    cout << "9)Print with iterator and parallel_qsort." << endl;
    cout << "0)Exit" << endl;
}