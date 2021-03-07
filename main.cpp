//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// csci272*sp21 - lab3
#include <cmath> 

class Quaternion
{
    double a;
    double b;
    double c;
    double d;

public:
    Quaternion()
    {
        a = 0;
        b = 0;
        c = 0;
        d = 0;
    }
    Quaternion(double _a, double _b, double _c, double _d)
    {
        a = _a;
        b = _b;
        c = _c;
        d = _d;
    }
    bool operator==(const Quaternion &obj) const
    {
        if (a == obj.a)
            if (b == obj.b)
                if (c == obj.c)
                    if (d == obj.d)
                        return true;
        return false;
    }
    Quaternion operator+(const Quaternion &obj) const
    {
        Quaternion temp;
        temp.a = a + obj.a;
        temp.b = b + obj.b;
        temp.c = c + obj.c;
        temp.d = d + obj.d;
        return temp;
    }
    Quaternion operator-(const Quaternion &obj) const
    {
        Quaternion temp;
        temp.a = a - obj.a;
        temp.b = b - obj.b;
        temp.c = c - obj.c;
        temp.d = d - obj.d;
        return temp;
    }
    friend Quaternion operator*(const Quaternion &obj, int n);
};

Quaternion operator*(const Quaternion &obj, int n)
{
    Quaternion temp;
    temp.a = n * obj.a;
    temp.b = n * obj.b;
    temp.c = n * obj.c;
    temp.d = n * obj.d;
    return temp;
}

// driver function
int main()
{
    // test q1
    Quaternion q(1.0, 2.0, 3.0, 4.0), p(1.0, 2.0, 3.0, 4.0);
    if (q == p)
        cout << "Quaternions q and p are same\n";
    else
        cout << "Quaternions q and p are different\n";

    // test q2
    Quaternion r(2.0, 4.0, 6.0, 8.0);
    if (q + p == r)
        cout << "Quaternions q + p is equal to r\n";
    else
        cout << "Quaternions q + p is not equal to r\n";

    // test q3
    // since r was already declared, I have used s here
    Quaternion s(0.0, 0.0, 0.0, 0.0);
    if (q - p == s)
        cout << "Quaternions q - p is equal to s\n";
    else
        cout << "Quaternions q - p is not equal to s\n";

    // test q4
    if (q * 2.0 == r)
        cout << "Quaternions q * 2.0 is equal to r\n";
    else
        cout << "Quaternions q * 2.0 is not equal to r\n";
        
    return 0;
}


};

//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "q1" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion p{1.0, 2.0, 3.0, 4.0};
        REQUIRE( q == p );
    }
    SECTION( "q2" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion p{1.0, 2.0, 3.0, 4.0};
        Quaternion r{2.0, 4.0, 6.0, 8.0};
        REQUIRE( (q + p) == r );
    }
    SECTION( "q3" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion p{1.0, 2.0, 3.0, 4.0};
        Quaternion r{0.0, 0.0, 0.0, 0.0};
        REQUIRE( (q - p) == r );
    }
    SECTION( "q3" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion r{2.0, 4.0, 6.0, 8.0};
        REQUIRE( (q * 2.0) == r );
    }
}
//------------------------------
