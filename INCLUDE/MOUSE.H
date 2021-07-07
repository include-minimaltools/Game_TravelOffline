#ifndef MOUSE_H
#define MOUSE_H 1
#include<dos.h>
union REGS reg;
/*************************************************/
/* LA FUNCION mtest                              */
/* Esta funci�n sirve para testear el rat�n.     */
/* No es necesario enviar ning�n par�metro.      */
/* Retorna: 0 => no hay rat�n instalado.         */
/*          n => el n�mero de botones del rat�n. */
/*************************************************/

int mtest(void)
{
	reg.x.ax = 0x0;
	int86(0x33, &reg, &reg);
	if (reg.x.ax > 0) return reg.x.bx; /* n�mero de botones */
	else return 0;
}


/*************************************************/
/* LA FUNCION mver                               */
/* Muestra el puntero del rat�n.                 */
/* No es necesario enviar ning�n par�metro.      */
/* No retorna ning�n valor.                      */
/*************************************************/

void mver(void)
{
	reg.x.ax = 0x1;
	int86(0x33, &reg, &reg);
}


/*************************************************/
/* LA FUNCION mocultar                           */
/* Oculta el puntero del rat�n.                  */
/* No es necesario enviar ning�n par�metro.      */
/* No retorna ning�n valor.                      */
/*************************************************/

void mocultar(void)
{
	reg.x.ax = 0x2;
	int86(0x33, &reg, &reg);
}


/*************************************************/
/* LA FUNCION mxpos                              */
/* Nos dice la coordenada X del rat�n.           */
/* Es necesario enviar un par�metro.             */
/*    1 => modo gr�fico.                         */
/*    8 => modo texto.                           */
/* Retorna la posici�n horizontal del rat�n.     */
/*************************************************/

int mxpos(int modo)
{
	reg.x.ax = 0x3;
	int86(0x33, &reg, &reg);
	return reg.x.cx/modo;
}


/*************************************************/
/* LA FUNCION mypos                              */
/* Nos dice la coordenada Y del rat�n.           */
/* Es necesario enviar un par�metro.             */
/*    1 => modo gr�fico.                         */
/*    8 => modo texto.                           */
/* Retorna la posici�n vertical del rat�n.       */
/*************************************************/

int mypos(int modo)
{
	reg.x.ax = 0x3;
	int86(0x33, &reg, &reg);
	return reg.x.dx/modo;
}


/*************************************************/
/* LA FUNCION msituar                            */
/* Situamos el rat�n en las coordenadas deseadas */
/* Es necesario enviar tres par�metros.          */
/*    modo => 1 => modo gr�fico.                 */
/*            8 => modo texto.                   */
/*    x => posici�n horizontal.                  */
/*    y => posici�n vertical.                    */
/* No retorna ning�n valor.                      */
/*************************************************/

void msituar(int modo, int x, int y)
{
	reg.x.ax = 0x4;
	reg.x.cx = x*modo;
	reg.x.dx = y*modo;
	int86(0x33, &reg, &reg);
}


/*************************************************/
/* LA FUNCION mclick                             */
/* Nos dice si hay alg�n bot�n presionado.       */
/* No es necesario enviar ning�n par�metro.      */
/* Retorna: 0 => ning�n bot�n presionado.        */
/*          1 => bot�n izquierdo presionado.     */
/*          2 => bot�n derecho presionado.       */
/*************************************************/

int mclick(void)
{
	int r = 0;
	reg.x.ax = 0x5;
	reg.x.bx = 0;
	int86(0x33, &reg, &reg);
	if ((reg.x.ax) & 1) r = 1;
	else if ((reg.x.ax>>1) & 1) r = 2;
	return r;
}


/*************************************************/
/* LA FUNCION mlimit                             */
/* Limitamos el espacio de movilidad del rat�n.  */
/* Es necesario enviar cinco par�metros.         */
/*    modo => 1 => modo gr�fico.                 */
/*            8 => modo texto.                   */
/*    x1 => l�mite arriba.                       */
/*    y1 => l�mite izquierda.                    */
/*    x2 => l�mite abajo.                        */
/*    y2 => l�mite derecha.                      */
/* No retorna ning�n valor.                      */
/*************************************************/

void mlimit(int modo, int x1, int y1, int x2, int y2)
{
	reg.x.ax = 0x7;
	reg.x.cx = x1*modo;
	reg.x.dx = x2*modo;
	int86(0x33, &reg, &reg);
	reg.x.ax = 0x8;
	reg.x.cx = y1*modo;
	reg.x.dx = y2*modo;
	int86(0x33, &reg, &reg);
}

/*************************************************/
/* LA FUNCION minlimit                           */
/* Verificamos si el rat�n se encuentra en un    */
/* �rea determinada.  Es necesario enviar cinco  */
/* par�metros:                                   */
/*    modo => 1 => modo gr�fico.                 */
/*            8 => modo texto.                   */
/*    x1 => l�mite arriba.                       */
/*    y1 => l�mite izquierda.                    */
/*    x2 => l�mite abajo.                        */
/*    y2 => l�mite derecha.                      */
/* Retorna 1 si est� en esa �rea y 0 en caso     */
/* contrario.                                    */
/*************************************************/

int minlimit(int modo,int x1,int y1,int x2,int y2)
{
 if((mxpos(modo)>=x1) &&
	(mxpos(modo)<=x2) &&
	(mypos(modo)>=y1) &&
	(mypos(modo)<=y2))
	   return 1;
 return 0;
}
#endif
