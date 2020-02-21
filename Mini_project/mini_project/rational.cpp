#include <iostream>

using namespace std;
class Rational
{
public:
    Rational (int numerator, int denominator =1): numer{numerator}, denom{denominator}{
       // this ->normalized(numer,denom);
    }
    ~Rational(){}
    Rational( const Rational& copy){
        this->denom = copy.denom;
        this->numer = copy.numer;
    }

    Rational& operator= (Rational const& other){
        if(&other != this){
            this->denom = other.denom;
            this->numer = other.numer;
        }
        return *this;
    }
    Rational& operator= (int i){
        this->numer = i;
        return *this;
    }

    int numerator () const{return numer; }
    int denominator () const { return denom; }

    static Rational normalize(Rational const& other){
        int denoma = other.denominator();
        int numera = other.numerator();
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
    int gcd (int numerator, int denominator){
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


    static Rational normalized(int numerator, int denominator){
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


     Rational operator+(Rational const& other) const{
         //return negation of a rational number
         return Rational{(this->numer*other.denom)+(other.numer*this->denom),this->denom * other.denom};
     }
     Rational operator-(Rational const& other) const{
         return Rational{(this->numer*other.denom)-(other.numer*this->denom),this->denom * other.denom};
     }
     Rational operator*(Rational const& other) const{
         return Rational{this->numer*other.numer,this->denom*other.denom};
     }
     Rational operator/(Rational const& other) const{
         return Rational{this->numer*other.denom,this->denom*other.numer};
     }

     Rational operator-(){
         return Rational {-(this->numerator()),this->denominator()};
     }
     Rational operator+(){
         return Rational {this->numerator(),this->denominator()};
     }


    bool operator ==(Rational const& other)const{
        return{ (this->numer*other.denom - other.numer*this->denom) ==0};
    }
    bool operator >=(Rational const& other)const{
         return{ (this->numer*other.denom - other.numer*this->denom) >=0};
    }
    bool operator <=(Rational const& other)const{
         return{ (this->numer*other.denom - other.numer*this->denom) <=0};
    }
    bool operator >(Rational const& other)const{
         return{ (this->numer*other.denom - other.numer*this->denom) > 0};
    }
    bool operator <(Rational const& other)const{
         return{ (this->numer*other.denom - other.numer*this->denom) <0};
    }


private:
    int numer;
    int denom;
    //int gcdND;

    void initialize(int numerator, int denominator);

    friend std::ostream& operator<<(std::ostream &, const Rational &);
    friend std::istream& operator>>(std::istream &,  Rational &);
};

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

int main(){
    Rational rr{15,-25};
    Rational irr=Rational::normalized(15,25);

    cout<<"irr ="<<irr<<endl;
    Rational r2(2, 11), r3(1, -3), r5(18, 6);
    Rational res1 = 3 + r2 * r3;
    //Rational ires1 =Rational::normalize(res1);
    Rational res2 = (3 + r2) * r3;
    Rational res3 = 3 + r3 * (r2 + 2) / (r5 - r3);
   // Rational ires3 = Rational::normalized(res3.numerator(),res3.denominator());

    cout << 3 << " + " << r2 << " * " <<  r3 << " = " << Rational::normalize(res1) << endl;
    cout << "(" << 3 << " + " << r2 << ")" << " * " <<  r3 << " = " << Rational::normalize(res2) << endl;
    cout << 3 << " + " << r3 << " * " << "(" << r2 << " + " << 2 << ")" << "/"
         << "(" << r5 << " - " << r3 << ")" << " = " << Rational ::normalized(res3.numerator(),res3.denominator()) << endl;

    return 0;
}
