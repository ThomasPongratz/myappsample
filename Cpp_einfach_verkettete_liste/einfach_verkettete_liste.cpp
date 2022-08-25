#include <iostream>

using namespace std;

struct Vektor {
    double x, y;
    Vektor *next;
};

int main()
{
    Vektor *first = nullptr;
    double in_x, in_y;
    cout << "Vektor Eingabe:" << endl;
    while (cin >> in_x >> in_y) {
        if (first == nullptr) {
            first = new Vektor{in_x, in_y, nullptr};
        } else {
            Vektor *ptr = first;
            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->next = new Vektor{in_x, in_y, nullptr};
        }
    }

    Vektor *ptr = first;
    unsigned i = 0;
    while (ptr != nullptr) {
        cout << i + 1 << ". Vektor ("
             << ptr->x << ", "
             << ptr->y << ")" << endl;
        ptr = ptr->next;
        ++i;
    }

    ptr = first;
    while (ptr) {
        Vektor *hilf = ptr->next;
        delete ptr;
        ptr = hilf;
    }
    first = nullptr;

    return 0;
}
