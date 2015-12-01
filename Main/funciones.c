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
}

float Color(uint8_t Max,uint8_t min,uint8_t A,uint8_t B,uint8_t C)//H function
{	
	float r=(double)(Max-min);
	float  h=0.00;

	
	if(A==Max && r!=0){
		h=((B - C) / r) ;
	  		
	}
	else{
	
		if(B==Max && r!=0){
	
	   		h=((C-A)/r)+2;
			
		}else{
	
			if(B==min && r!=0){
		
		   		h=((A-B)/r)+4;
			}else{h=0;}
		     }

	
	     }

	h=h*60;
	return h;
}

float Saturacion(uint8_t A, uint8_t B)//Saturacion 
{
float sat;
	if (A == B) {
			sat=1;
			}
		else {
			sat=(((double)A-(double)B)/(double)A);
			}

	return sat;
}


float FiltroExperimental(float h, float s, float v)//funcion para aplicar filtro a los datos
{
	float filtro;
	while (h < 0) { h += 360; };
	while (h >= 360) { h -= 360; };
	h=h/360;
	//printf("h value %f\t producto cuadrado value %f\t s-v value %f\n",h,s,v);
	filtro=(1-(h-(s-v)*(s-v)));
	return filtro;
}
