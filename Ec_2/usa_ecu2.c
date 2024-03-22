#include <stdio.h>
#include "ecu2.h"

int main(){
  double r;
  char salida[100];
  ecu2 a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
  ecu2 b1, b2, b3, b4, b5, b6, b7, b8, b9, b10;
  ecu2 c1, c2, c3, c4, c5, c6, c7, c8, c9, c10;
  
  crea_ecu2(&a1,-4,-2,2);      /* sol -1    y 0.5  */
  crea_ecu2(&a2,3,15,12);      /* sol -1    y -4   */
  crea_ecu2(&a3,10,-10,0);     /* sol 1     y 0    */
  crea_ecu2(&a4,-5,28,-15);    /* sol 0.6   y 5    */
  crea_ecu2(&a5,5,18,-8);      /* sol 0.4   y -4   */
  crea_ecu2(&a6,-16,0,0);      /* sol 0     y 0    */
  crea_ecu2(&a7,-25,10,0);     /* sol 0     y 0.4  */
  crea_ecu2(&a8,6,11,-10);     /* sol 0.667 y -2.5 */
  crea_ecu2(&a9,6,19,10);      /* sol-0.667 y -2.5 */
  crea_ecu2(&a10,10,31,15);    /* sol -0.6  y -2.5 */

  crea_ecu2(&b1,1,-6,9);       /* sol 3    */
  crea_ecu2(&b2,4,-16,16);     /* sol 2    */
  crea_ecu2(&b3,16,-40,25);    /* sol 1.25 */
  crea_ecu2(&b4,4,0,0);        /* sol 0    */
  crea_ecu2(&b5,1,0,0);        /* sol 0    */
  crea_ecu2(&b6,1,8,16);       /* sol -4   */
  crea_ecu2(&b7,25,-20,4);     /* sol 0.4  */
  crea_ecu2(&b8,1,4,4);        /* sol -2   */
  crea_ecu2(&b9,25,-40,16);    /* sol 0.8  */
  crea_ecu2(&b10,1,2,1);       /* sol -1   */
  
  crea_ecu2(&c1,36,-216,648);  /* sol 3+i*3   y  3-i*3  */
  crea_ecu2(&c2,4,8,8);        /* sol -1+i*1  y -1-i*1  */
  crea_ecu2(&c3,16,96,160);    /* sol -3+i*-1 y -3-i*-1 */
  crea_ecu2(&c4,36,-216,648);  /* sol 3+i*3   y  3-i*3  */
  crea_ecu2(&c5,4,-16,32);     /* sol 2+i*2   y  2-i*2  */
  crea_ecu2(&c6,4,-24,52);     /* sol 3+i*-2  y  3-i*-2 */
  crea_ecu2(&c7,1,-6,18);      /* sol 3+i*-3  y  3-i*-3 */
  crea_ecu2(&c8,1,4,8);        /* sol -2+i*-2 y -2-i*-2 */
  crea_ecu2(&c9,4,-8,8);       /* sol 1+i*1   y  1-i*1  */
  crea_ecu2(&c10,1,2,10);      /* sol -1+i*-3 y -1-i*-3 */

  return 0;
}