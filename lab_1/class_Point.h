#ifndef _CLASS_POINT_H
#define _CLASS_POINT_H

#include "class_Line.h"

#include<cmath>


namespace Point{

/***************************class Point******************************************************************************/
class Point{

  private:
    double x, y ;

  public:
    Point() ;
    Point( Point& p ) ;
    Point( double  , double  ) ;

   ~Point(){}

    double X() const ;
    double Y() const ;
    void   _set  ( double& , double& ) ;

    double  Rast() ;
    double  Rast_t( const Point& ) ;
    bool Prov ( Line::Line&  ) ;

    Point Wra_Point( double& ) ;

    std::ostream& operator<<( std::ostream &os, const Point::Point &point ) {
      os << point.X() << " " << point.Y() ;
      return os ;
    }

    std::istream& operator>>( std::istream &is, const Point::Point &point ) {
      point.Y()>> " " >>point.X() >> is;
      return is ;
    }

};
/****************************class Point*****************************************************************************/

} //namespace Point

#endif // CLASS_POINT_H
