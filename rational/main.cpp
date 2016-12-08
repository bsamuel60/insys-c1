#include <iostream>
#include <iomanip>
#include <exception>
#include <stdexcept>
#include <sstream>
//#include <cmath>
#include <cstdlib>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

class rational
{
    int numerator, denominator;
    void simplify();
public:
    rational(int,int);
    void print();
    void assign(int,int);
    rational operator=(const rational& r);
    rational operator+(const rational& r);
    rational operator-(const rational& r);
    rational operator*(const rational& r);
    rational operator/(const rational& r);
    rational operator+(const int&);
    rational operator-(const int&);
    rational operator*(const int&);
    rational operator/(const int&);
    rational operator+=(const rational& r);
    rational operator-=(const rational& r);
    rational operator*=(const rational& r);
    rational operator/=(const rational& r);
    rational operator++(int);
    rational operator--(int);
    bool operator==(const rational&);
    bool operator<(const rational&);
    bool operator==(const int&);
    bool operator<(const int&);
//    iostream operator<<(iostream);
    string tostring();
};

void rational::simplify()
{
    // Uses Euclidian algorithm to find greatest common divisor.
    // Described here: https://en.wikipedia.org/wiki/Euclidean_algorithm#Procedure
    int k,r,gcd,n,d;

    // denominator shall be positive
    if (denominator<0)
    {
        denominator=(-denominator);
        numerator=(-numerator);
    }

    //Special case: =0
    if (!numerator)
        denominator=1;
    else
    {
        //make both positive and n>=d
        n=abs(numerator);
        d=denominator;
        if (n<d)
        {
            int t;
            t=n;
            n=d;
            d=t;
        }
        for (k=0;; k++)
        {
            r=n%d;
            if (r)
            {
                n=d;
                d=r;
            }
            else
            {
                gcd=d;
                break;
            }
        }
        numerator/=gcd;
        denominator/=gcd;
    }
};

rational::rational(const int n = 0,const int d = 1)
{
    if(d==0) throw invalid_argument("rational::rational(): 0 in denominator");
    numerator=n;
    denominator=d;
    this->simplify();
};

void rational::print()
{
    cout << numerator << "/" << denominator << " = " << setprecision(5) << setiosflags(ios::fixed) << ((float)numerator/(float)denominator) << endl;
};

void rational::assign(int nom,int denom)
{
    if (denom==0) throw invalid_argument("rational::assign(int,int): 0 in denominator");
    numerator=nom;
    denominator=denom;
    this->simplify();
}

rational rational::operator=(const rational& r)
{
    this->assign(r.numerator,r.denominator);
    return *this;
}

rational rational::operator+(const rational& r)
{
    rational res;
    res.numerator=numerator*r.denominator+r.numerator*denominator;
    res.denominator=denominator*r.denominator;
    res.simplify();
    return res;
}

rational rational::operator-(const rational& r)
{
    rational res;
    res.numerator=numerator*r.denominator-r.numerator*denominator;
    res.denominator=denominator*r.denominator;
    res.simplify();
    return res;
}

rational rational::operator*(const rational& r)
{
    rational res;
    res.numerator=numerator*r.numerator;
    res.denominator=denominator*r.denominator;
    res.simplify();
    return res;
}

rational rational::operator/(const rational& r)
{
    rational res;
    if (r.numerator==0) throw invalid_argument("rational::operator/ division by 0");
    res.numerator=numerator*r.denominator;
    res.denominator=denominator*r.numerator;
    res.simplify();
    return res;
}

rational rational::operator+(const int &i)
{
    rational res;
    res.numerator=numerator+i*denominator;
    res.denominator=denominator;
    res.simplify();
    return res;
}

rational rational::operator-(const int &i)
{
//    rational res, r(i);
//    res.numerator=numerator*r.denominator-r.numerator*denominator;
//    res.denominator=denominator*r.denominator;
//    res.simplify();
//    return res;
    return *this+(-i);
}

rational rational::operator*(const int &i)
{
//    rational res;
//    res.numerator=numerator*i;
//    res.denominator=denominator;
//    res.simplify();
    return rational(numerator*i,denominator);
}

rational rational::operator/(const int &i)
{
//    rational res, r(i);
//    res.numerator=numerator*r.denominator-r.numerator*denominator;
//    res.denominator=denominator*r.denominator;
//    res.simplify();
//    return res;
    return rational(numerator,denominator*i);
}

rational rational::operator+=(const rational& r)
{
    numerator=numerator*r.denominator+r.numerator*denominator;
    denominator*=r.denominator;
    this->simplify();
    return *this;
}

rational rational::operator-=(const rational& r)
{
    numerator=numerator*r.denominator-r.numerator*denominator;
    denominator*=r.denominator;
    this->simplify();
    return *this;
}

rational rational::operator*=(const rational& r)
{
    numerator*=r.numerator;
    denominator*=r.denominator;
    this->simplify();
    return *this;
}

rational rational::operator/=(const rational& r)
{
    if (r.numerator==0) throw invalid_argument("rational::operator/ division by 0");
    numerator*=r.denominator;
    denominator*=r.numerator;
    this->simplify();
    return *this;
}

rational rational::operator++(const int i)
{
    rational temp(1);
    this->operator+=(temp);
    return *this;
}

rational rational::operator--(const int i)
{
    rational temp(1);
    this->operator-=(temp);
    return *this;
}

bool rational::operator==(const rational &r)
{
    return ((numerator==r.numerator)&&(denominator==r.denominator));
}

bool rational::operator<(const rational &r)
{
    return (numerator*r.denominator<r.numerator*denominator);
}

bool rational::operator==(const int &i)
{
    return ((numerator==i)&&(denominator==1));
}

bool rational::operator<(const int &i)
{
    return (numerator<i*denominator);
}


//iostream rational::operator<<(iostream t)
//{
//    //return this->numerator << "/" << this->denominator << t;
//    return t;
//};

string rational::tostring()
{
//    stringstream res;

    return SSTR(numerator) + '/' + SSTR(denominator);
}

rational operator+(int i, rational r)
{
    return r+i;
}

rational operator-(int i, rational r)
{
    return rational(i)-r;
}

rational operator*(int i, rational r)
{
    return r*i;
}

rational operator/(int i, rational r)
{
    return rational(i)/r;
}

int main()
{
    try
    {
        rational r(INT_MAX-3,INT_MAX-1);
        rational r1(-5);
        rational r2;
        rational r3(90,70);
        rational r4(0,-10);
        rational r5(3,-2);
        rational r6(-20,180);

        r.print();
        r1.print();
        r2.print();
        r3.print();
        r3=r2;
        r2.assign(-2,-3);
        r2.print();
        r3.print();
        r4.print();
        r5.print();
        r6.print();
        r6=r+r5;
        r6.print();
        cout <<endl;
        r5.assign(3,4);
        r6.assign(1,3);
        r5.print();
        r6.print();
        r2=r5+r6;
        r2.print();
        r2=r5-r6;
        r2.print();
        r2=r5*r6;
        r2.print();
        r2=r5/r6;
        r2.print();
        r2++;
        r2.print();
        r2--;
        r2.print();
        r2=r5+5;
        r2.print();
        r2=r5-10;
        r2.print();
        r2=5+r5;
        r2.print();
        r2=10-r5;
        r2.print();
        r4.assign(123,456);
        r2=(r5+r6/r4)*r1*3;
        r2.print();
        r2=5*r5;
        r2.print();
        r2=5/r5;
        r2.print();
        if (rational(5,5)==rational(1)) cout << "5/5 = 1" << endl;
        if (rational(5,11)<rational(5,12)) cout << "5/11 < 5/12" << endl;
        if (rational(5,6)==rational(1)) cout << "5/6 = 1" << endl;
        else cout << "5/6 != 1" << endl;
        if (rational(5,11)<rational(5,12)) cout << "5/11 < 5/12" << endl;

        if (rational(5,5)==1) cout << "5/5 = 1" << endl;
        if (rational(5,11)<1) cout << "5/11 < 1" << endl;

        cout << (rational(5,4)==rational(3,2)) << endl;
        cout << (rational(9,8)<rational(8,9)) << endl;
        cout << (rational(3,4)==2) << endl;

        // This is supposed to fail
        r2=r5/r3;
        r2.print(); // Will not reach this


//cout << r.tostring << endl;

//        cout << "Rational number: " << r.tostring() << endl;
    }
    catch (std::exception& e)
    {
        cout << "exception caught: " << e.what() << '\n';
    }
    return 0;
}
