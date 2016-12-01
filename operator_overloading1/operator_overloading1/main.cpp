#include <iostream>

using namespace std;

class CVector
{
public:
    int x,y;
    CVector() : x(0),y(0) {};
    CVector(int,int);
    CVector operator+(CVector);
    bool operator>(CVector);
};

CVector::CVector(int a, int b)
{
    this->x = a;
    this->y = b;
}

CVector CVector::operator+(CVector v)
{
    CVector temp;
    temp.x = this->x + v.x;
    temp.y = this->y + v.y;
    return (temp);
}

bool CVector::operator>(CVector v)
{
    return ((this->x)*(this->x)+(this->y)*(this->y))>((v.x)*(v.x)+(v.y)*(v.y));
}

int main()
{
    CVector a(3,1);
    CVector b(1,2);
    CVector c;
    c = a + b;
    cout << c.x << "," << c.y << endl;
    if (a > b)
        cout << "Vector a is longer than vector b" << endl;
    else
        cout << "Vector a is not longer than vector b" << endl;

    return 0;
}
