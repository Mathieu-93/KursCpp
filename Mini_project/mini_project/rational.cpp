#include <iostream>
#include "rational.h"

using namespace std;

Rational::Rational (int numerator, int denominator =1): numer{numerator}, denom{denominator}{
    // this ->normalized(numer,denom);
}
Rational::~Rational(){}
Rational::Rational( const Rational& copy){
    this->denom = copy.denom;
    this->numer = copy.numer;
}

Rational& Rational::operator= (Rational const& other){
    if(&other != this){
        this->denom = other.denom;
        this->numer = other.numer;
    }
    return *this;
}
Rational& Rational::operator= (int i){
    this->numer = i;
    return *this;
}

int Rational::numerator () const{return numer; }
int Rational::denominator () const { return denom; }

 Rational Rational::normalize(Rational const& other){
    int denoma = other.denom;
    int numera = other.numer;
    //int gcd_ = gcd(numera,denoma);

    if(other.numerator()<0&&other.denominator()<0){
        numera = -other.numerator();
        denoma = -other.denominator();
    }
    else if((other.numerator()<0) != (other.denominator()<0)) {
        if (other.denominator()<0){numera = -other.numerator(), denoma =-other.denominator();}
        else{numera = other.numerator(), denoma = other.denominator();}

    }
    else{
        numera = other.numerator();
        denoma = other.denominator();
    }
    return Rational{numera, denoma};

}
int Rational::gcd (int numerator, int denominator){
    //gcd of two non-negative numbers:  Euclid's algorithm.

    do {
        if(numerator<denominator){
            int temp = numerator;
            numerator = denominator;
            denominator = temp;
        }
        numerator-=denominator;
    }while(numerator);
    return denominator;
}


 Rational Rational::normalized(int numerator, int denominator){
    //gcd of two non-negative numbers:  Euclid's algorithm.
    int numera=numerator;
    int denomi= denominator;
    do {
        if(numera<denomi){
            int temp = numera;
            numera = denomi;
            denomi = temp;
        }
        numera-=denomi;
    }while(numera);
    int gcdND= denomi;
    return Rational {numerator/gcdND, denominator/gcdND} ;

}


Rational Rational::operator+(Rational const& other) const{
    //return negation of a rational number
    return Rational{(this->numer*other.denom)+(other.numer*this->denom),this->denom * other.denom};
}
Rational Rational::operator-(Rational const& other) const{
    return Rational{(this->numer*other.denom)-(other.numer*this->denom),this->denom * other.denom};
}
Rational Rational::operator*(Rational const& other) const{
    return Rational{this->numer*other.numer,this->denom*other.denom};
}
Rational Rational::operator/(Rational const& other) const{
    return Rational{this->numer*other.denom,this->denom*other.numer};
}

Rational Rational::operator-() const{
    return Rational {-(this->numerator()),this->denominator()};
}
Rational Rational::operator+()const{
    return Rational {this->numerator(),this->denominator()};
}


bool Rational:: operator ==(Rational const& other)const{
    return{ (this->numer*other.denom - other.numer*this->denom) ==0};
}
bool Rational::operator >=(Rational const& other)const{
    return{ (this->numer*other.denom - other.numer*this->denom) >=0};
}
bool Rational::operator <=(Rational const& other)const{
    return{ (this->numer*other.denom - other.numer*this->denom) <=0};
}
bool Rational::operator >(Rational const& other)const{
    return{ (this->numer*other.denom - other.numer*this->denom) > 0};
}
bool Rational::operator <(Rational const& other)const{
    return{ (this->numer*other.denom - other.numer*this->denom) <0};
}



void initialize(int numerator, int denominator);

//    friend std::ostream& operator<<(std::ostream &, const Rational &);
//    friend std::istream& operator>>(std::istream &,  Rational &);

ostream &operator<<(ostream &os, const Rational &value)
{
    // stream output of rational number
    os << value.numerator() << " / " << value.denominator();
    return os;
}

Rational operator+(Rational const& r,int i){
    return Rational{ r.numerator() + (i *r.denominator()), r.denominator()};
}
Rational operator+(int i, Rational const& r){
    return Rational{  r.numerator() + (i *r.denominator()), r.denominator()};
}

Rational operator*(Rational const& r,int i){
    return Rational{ r.numerator()*i, r.denominator()};
}
Rational operator*(int i, Rational const& r){
    return Rational{ r.numerator()*i, r.denominator()};
}

Rational operator/(Rational const& r,int i){
    return Rational{ r.numerator(), r.denominator()*i};
}
Rational operator/(int i, Rational const& r){
    return Rational{i*r.denominator(),r.numerator()};
}


