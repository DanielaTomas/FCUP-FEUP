
#ifndef __funcs_h__ // {
#define __funcs_h__

//! \file funcs.h
#ifdef __cplusplus
extern "C" {
#endif

//! Convert hexadecimal string to integer.
//!
//! \param String formed by characters '0'-'9', 'A-F', 'a-f'
//! \return Corresponding integer
int hexstr_convert(const char str[]);

//! Enumeration for month values.
enum { 
  JANUARY = 1, 
  FEBRUARY,
  MARCH, 
  APRIL, 
  MAY, 
  JUNE, 
  JULY, 
  AUGUST, 
  SEPTEMBER, 
  OCTOBER, 
  NOVEMBER, 
  DECEMBER
};

//! Return the number of days in month.
//!
//! \param m Month
//! \param y Year
//! \return Corresponding integer
int days_in_month(int m, int y);

double exp_taylor(double x, int n);

#ifdef __cplusplus
}
#endif

#endif // }
