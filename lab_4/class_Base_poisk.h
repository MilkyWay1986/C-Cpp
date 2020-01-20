#ifndef CLASS_BASE_POISK_H_INCLUDED
#define CLASS_BASE_POISK_H_INCLUDED




namespace Baza_poisk{

/***************************class Baza_poisk*************************************************************/
class Baza_poisk{

  protected:
    double a, b;

  public:
    Baza_poisk() { }
    Baza_poisk( double _a , double _b ) { a =_a; b =_b ;}
   ~Baza_poisk(){}

    double A() const { return a ; }
    double B() const { return b ; }

    virtual double poisk( double ( *f ) (double x), double esp ) = 0;

};
/***************************class Baza_poisk*************************************************************/

} //namespace Baza_poisk





#endif // CLASS_BASE_POISK_H_INCLUDED
