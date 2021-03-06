#include "class_Circle.h"
#include "../lab_1/class_Point.cpp"
#include "../lab_1/class_Line.cpp"

namespace Circle{

/***************************class Circle*****************************************************************************/
/*------------------------------------------------------------------------------------------------------------------*/
Circle::Circle(){}
/*------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------*/
Circle::Circle( Point::Point &pt, double &rv )
  : center(&pt), r(rv){}
/*------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------*/
double Circle::R() const {
  return Circle::r ;
}
/*------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------*/
void Circle::Set( Point::Point &pt, double &rv ){
  Circle::center = &pt ;
  Circle::r = rv ;
}
/*------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------*/
int64_t Circle::Prov ( Circle &pt ) const {
  Point::Point* t = pt.center ;
  double r1 = Circle::center->Rast_t( *t ) ;

  if( r1 < pt.r + Circle::r ) return 1;
  else if ( ( r1 < pt.Circle::r ) || ( r1 < Circle::r ) ) return 0;
  return -1 ;
}
/*------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------*/
int64_t Circle::Prov_W( Point::Point& pt ) const {
  return ( ( pow( Circle::r, 2 ) < pt.X() + pt.Y() ) ? 1 : 0 );
}
/*------------------------------------------------------------------------------------------------------------------*/
/***************************class Circle*****************************************************************************/

}//namespace Circle
