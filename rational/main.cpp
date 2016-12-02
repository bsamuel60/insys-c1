#include <iostream>
#include <iomanip>
#include <exception>
#include <stdexcept>
#include <sstream>

using namespace std;

class rational
{
    int numerator, denominator;
public:
    rational(int,int);
    void print();
    void assign(int,int);
//    iostream operator<<(iostream);
//    stringstream tostring();
};

rational::rational(int n = 0,int d = 1)
{
    if(d==0) throw invalid_argument("rational::rational(): 0 in denominator");
    numerator=n;
    denominator=d;
};

void rational::print()
{
    cout << numerator << "/" << denominator << " = " << setprecision(7) << ((float)numerator/(float)denominator) << endl;
};

void rational::assign(int nom,int denom)
{
    if (denom==0) throw invalid_argument("rational::assign(int,int): 0 in denominator");
    numerator=nom;
    denominator=denom;
}

//iostream rational::operator<<(iostream t)
//{
//    //return this->numerator << "/" << this->denominator << t;
//    return t;
//};

//stringstream rational::tostring()
//{
//    stringstream res;
//    res << numerator << '/' << denominator;
//    return res;
//}

int main()
{
    try
    {
        rational r(1,3);
        rational r1(5);
        rational r2;
        rational r3(9,7);

r.print();
r1.print();
r2.print();
r3.print();
r2.assign(2,3);
r2.print();

//        cout << "Rational number: " << r.tostring() << endl;
    }
    catch (std::exception& e)
    {
        cout << "exception caught: " << e.what() << '\n';
    }
    return 0;
}
