#include "class_Interval_nul.h"


namespace Interval_null{

/***************************class Interval_null********************************************************************/
/*----------------------------------------------------------------------------------------------------------------*/
void Interval_null::P() const {
  for ( size_t i = 0 ; i < Interval_null::Baza_tab::kol_in ; i++ )
    std::cout << p_in[i].X() << "  " << p_in[i].Y() << std::endl ;
}
/*----------------------------------------------------------------------------------------------------------------*/

Point::Point* Interval_null::Interwal_nul() {
  size_t i, j ;
  Point::Point *dt = new Point::Point[n];
  for ( i = 0, j = 0 ; i < n - 2 ; i++ )
    if ( p[i].Y() * p[i + 1].Y() < 0)
      dt[j++] = Point::Point ( p[i].X(), p[i + 1].X() ) ;
    p_in = new Point::Point[j];
    for ( i = 0; i < j; i++)
      p_in[i] = dt[i];kol_in = j;
  delete []dt;
  return p_in;
}
/***************************class Interval_null********************************************************************/


} //namespace Interval_null
