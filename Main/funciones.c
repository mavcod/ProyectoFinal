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

double maxim()//funcion maximo de pixel entre canales
{
printf( "falta maximo RGB \n" ); 
return 0;

}

double minim()//funcion minimo de pixel entre canales
{
printf( "falta minimo RGB \n" ); 
return 0;
}

double Color()//funcion minimo de pixel entre canales
{
printf( "falta minimo Hue \n" ); 
return 0;
}

double Saturacion()//funcion minimo de pixel entre canales
{
printf( "falta minimo Saturacion \n" ); 
return 0;
}

double Brillo()//funcion minimo de pixel entre canales
{
printf( "falta minimo Brillo \n" ); 
return 0;
}
