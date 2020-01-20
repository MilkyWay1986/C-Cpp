#ifndef _CLASS_LINE_H
#define _CLASS_LINE_H

#include<cmath>


namespace Line{

/***************************class Line*******************************************************************************/
class Line{

  private:
    double k, b ;

  public:
    Line();
    Line( double &, double & ) ;
   ~Line(){}

    double K() const ;
    double B() const ;
    void         _set( double & , double & ) ;

    double  Point_x() ;
    double  Point_y() ;
    int64_t Prov( const Line & ) ;
};
/****************************class Line******************************************************************************/

} //namespace Line

#endif // CLASS_LINE_H

