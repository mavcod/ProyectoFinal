#include <stdio.h>
#include "funcionesRgbHsv.h" 
#include "funcionesHsvRgb.h" 
#include "loadBMP.h"
#include <math.h> 
#include <stdlib.h>

int main()
{  
printf( "Principal Main \n" ); 
///lectura de imagen
IMAGE *img;
    loadBMP("lena.bmp", &img);

//variables de entrada a la funcion
uint8_t Rpixel;
uint8_t Bpixel;
uint8_t Gpixel;
uint8_t maxi;
uint8_t mini;
float filtro;
float H;
float sat;
int i;

//recorriendo la imagen
for (i = 0; i < img->width*img->height; i++) {
Rpixel=(uint8_t)img->data[i].r;
Bpixel=(uint8_t)img->data[i].g;
Gpixel=(uint8_t)img->data[i].b;



// se definen las funciones max y min para el calculo de los canales hsv
maxi = (uint8_t)maxim(Rpixel, Gpixel, Bpixel);
mini = (uint8_t)minim(Rpixel, Gpixel, Bpixel);
sat = Saturacion(maxi, mini);
H =Color(maxi,mini,Rpixel, Gpixel, Bpixel);
filtro=FiltroExperimental(H,sat,(float)(maxi)/255);
float* x;
x = (float *) malloc(3);
x=ConvHsvRgb(H*360,sat,(float)(maxi));
//prototipado funcion promedio
img->data[i].r = x[1];
img->data[i].g = x[2];
img->data[i].b = x[3];
free(x);
}


writeBMP("img.bmp", img);


// libera memoria de la imagen.
freeBMP(img);
    return 0;
}

