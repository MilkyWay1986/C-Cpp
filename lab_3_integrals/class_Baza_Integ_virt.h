#ifndef CLASS_BAZA_INTEG_VIRT_H_INCLUDED
#define CLASS_BAZA_INTEG_VIRT_H_INCLUDED


namespace Baza_Integ_virt{

/***************************class Baza_Integ_virt*************************************************************/
class Baza_Integ_virt{

  public:

    Baza_Integ_virt(){}
   ~Baza_Integ_virt(){}

    virtual double  Integral( double esp ) = 0 ;
    virtual double  A() const  = 0 ;
    virtual double  B() const  = 0 ;
    virtual int64_t N() const  = 0 ;
};
/***************************class Baza_Integ_virt*************************************************************/

} //namespace Baza_Integ_virt


#endif // CLASS_BAZA_INTEG_VIRT_H_INCLUDED
