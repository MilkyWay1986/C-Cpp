#ifndef _CLASS_CIRCLE_H
#define _CLASS_CIRCLE_H

#include<cmath>

#include "../lab_1/class_Point.h"
#include "../lab_1/class_Line.h"



namespace Circle{

/***************************class Circle*****************************************************************************/
class Circle{

  private:
    double r ;
    Point::Point* center ;

  public:
    Circle() ;
    Circle( Point::Point &, double & ) ;
   ~Circle(){}

    double R() const ;
    void Set( Point::Point &, double & ) ;

    int64_t Prov  ( Circle & ) const ;
    int64_t Prov_W( Point::Point & ) const  ;

} ;
/****************************class Circle****************************************************************************/

} //namespace Circle

#endif // _CLASS_CIRCLE_H

