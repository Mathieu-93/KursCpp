#ifndef RATIONAL_H
#define RATIONAL_H
#include<iostream>

class Rational
{
public:
    Rational (int numerator, int denominator );
    ~Rational();
    Rational( const Rational&);
    Rational& operator= (Rational const& other);
    Rational& operator= (int i);
    int numerator () const;
    int denominator () const;
    static Rational normalize(Rational const& other);
    int gcd (int numerator, int denominator);
    static Rational normalized(int,int);
    Rational operator+(Rational const& other) const;
    Rational operator-(Rational const& other) const;
    Rational operator*(Rational const& other) const;
    Rational operator/(Rational const& other) const;

    Rational operator+() const;
    Rational operator-() const;

    bool operator==(Rational const& other) const;
    bool operator>=(Rational const& other) const;
    bool operator<=(Rational const& other) const;
    bool operator>(Rational const& other) const;
    bool operator<(Rational const& other) const;

private:
    int numer;
    int denom;
    //int gcdND;

    void initialize(int numerator, int denominator);

    friend std::ostream& operator<<(std::ostream &, const Rational &);
    friend std::istream& operator>>(std::istream &, Rational &);



};
Rational operator+(Rational const& r, int i);
Rational operator+(int i, Rational const& r);

Rational operator-(Rational const& r, int i);
Rational operator-(int i, Rational const& r);

Rational operator*(Rational const& r, int i);
Rational operator*(int i, Rational const& r);

Rational operator/(Rational const& r, int i);
Rational operator/(int i, Rational const& r);


#endif // RATIONAL_H
