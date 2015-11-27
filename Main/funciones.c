#include <stdio.h> 
#include <stdlib.h>
#include <math.h> 
#include <stdint.h>
#include "funcionesRgbHsv.h" //funciones

uint8_t lecturaRGB (uint8_t R, uint8_t G, uint8_t B)//Funcion lectura RGB
{
uint8_t avg = (R+B+G)/3;
//printf( "falta lectura RGB \n" ); 
return avg;

}

uint8_t maxim(uint8_t A,uint8_t B,uint8_t C)//funcion maximo de pixel entre canales
{
uint8_t MAXI;
if(A > B) {
	if(A > C) {
		MAXI=A;
		}
	else {
		MAXI=C;
		}
}
else {
	if(B > C) {
		MAXI=B;
		}
	else {
		MAXI=C;
		}
}
return MAXI;
printf( "falta maximo RGB \n" ); 
//return 0;

}

uint8_t minim(uint8_t A,uint8_t B,uint8_t C)//funcion minimo de pixel entre canales
{
    uint8_t mini = A;
    if (mini > B) {
		mini = B;
		}
	else if (mini > C){
		 mini = C;
		}
	else {
		mini=mini;
		}
    return mini;

//printf( "falta minimo RGB \n" ); 
}

double Color(uint8_t Max,uint8_t min,uint8_t A,uint8_t B,uint8_t C)//H function
{	
	uint8_t r=Max-min;
	double  h=0.00;

	
	if(A==Max && C!=0){
	
	   h=((B-C)/r)%6;
			
	}
	else{
	
		if(B==Max && C!=0){
	
	   		h=((C-A)/r)+2;
			
		}else{
	
			if(B==min && C!=0){
		
		   		h=((A-B)/r)+4;
			}else{h=0;}
		     }

	
	     }

	h=h*60/360;//se divide en 360 para normalizar y dejar solo valores entre 0 y  1
 
return h;
}

double Saturacion(uint8_t A, uint8_t B)//funcion minimo de pixel entre canales
{
double sat;
sat=(double)(A-B)/A;
return sat;
}

double Brillo()//funcion minimo de pixel entre canales
{
printf( "falta minimo Brillo \n" ); 
return 0;
}
