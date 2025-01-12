#include <iostream>

using namespace std;

class Points {

private:
    float x;
    float y;
    static int count; 

public:

    Points() {
        x = 0;
        y = 0;
        count++;
    }
    Points(float x, float y) {
        this->x = x;
        this->y = y;
        count++;
    }


    float getX() { 
        return x;
    }
    float getY() { 
        return y;
    }
    void print() {
        cout << "x: " << x << endl; 
        cout << "y: " << y << endl; 
    }
    ~Points() {
        cout << "Destructor\n";
    }
    static int getCount() {
        return count;
    }
};


int Points::count = 0;

int main() {

    int t;
    cout << "Enter quantity of points: ";
    cin >> t;
    for (int i = 0; i < t; i++) {
        int enterx, entery;
        cout << "\nEnter x:";
        cin >> enterx;
        cout << "\nEnter y:";
        cin >> entery;
        Points a(enterx, entery);
        a.print();
    }
    
    cout << "\nTotal points count: " << Points::getCount() << endl;

    return 0;
}
