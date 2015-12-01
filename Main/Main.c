#include <stdio.h>
#include "funcionesRgbHsv.h" 
#include "funcionesHsvRgb.h" 
#include "loadBMP.h"
#include <math.h> 
#include <stdlib.h>

int main()
{  
//printf( "Principal Main \n" ); 
///lectura de imagen
char carName[50];
printf("\n Introduzca el nombre de la imagen extension *BMP (ej:lena.bmp) : \n");
     scanf("%s", &carName);

IMAGE *img;
    //loadBMP("lena.bmp", &img);//el formato de entrada de la imagen es nombre.extención, para este caso solo lee imagenes BMP.
	loadBMP(carName, &img);//el formato de entrada de la imagen es nombre.extención, para este caso solo lee imagenes BMP.
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
float *x;
//float* x=malloc(3);
//x = (float)malloc(3);

//recorriendo la imagen
for (i = 0; i < img->width*img->height; i++) {
Rpixel=(uint8_t)img->data[i].r;
Bpixel=(uint8_t)img->data[i].b;
Gpixel=(uint8_t)img->data[i].g;

// se definen las funciones max y min para el calculo de los canales hsv
maxi = (uint8_t)maxim(Rpixel, Gpixel, Bpixel);
mini = (uint8_t)minim(Rpixel, Gpixel, Bpixel);
sat = Saturacion(maxi, mini);//calculo de la saturacion del pixel
H =Color(maxi,mini,Rpixel, Gpixel, Bpixel);//calculando canal de color H
filtro=FiltroExperimental(H,sat,(float)(maxi)/255);//definiendo filtro multiplicador de color

//retornando de hsv a rgb
x=ConvHsvRgb(filtro*H,sat,(float)(maxi)/(255));

//salida a imagen 
img->data[i].r = filtro*255;//x[1];
img->data[i].g = filtro*255;//x[2];
img->data[i].b = filtro*255;//x[3];
}
//free(x);//libera memoria de variable X

writeBMP("img.bmp", img); //guardado de imagen
freeBMP(img);// libera memoria de la imagen.
free(img);
    return 0;
}

