#include <stdio.h>
#include "funcionesRgbHsv.h" 
#include "loadBMP.h"
int main()
{  
printf( "Principal Main \n" ); 
///lectura de imagen
 IMAGE *img;
    loadBMP("lena.bmp", &img);
int i;
//variables de entrada a la funcion
uint8_t Rpixel;
uint8_t Bpixel;
uint8_t Gpixel;
//recorriendo la imagen
for (i = 0; i < img->width*img->height; i++) {
Rpixel=(uint8_t)img->data[i].r;
Bpixel=(uint8_t)img->data[i].g;
Gpixel=(uint8_t)img->data[i].b;
//enviando las variables a las funciones.
//uint8_t avg = (Rpixel+ Bpixel + Gpixel)/3;
uint8_t H;
H = (uint8_t)lecturaRGB(Rpixel, Gpixel, Bpixel);
//prototipado funcion promedio
img->data[i].r = H;
img->data[i].g = H;
img->data[i].b = H;
}
writeBMP("img.bmp", img);
///
//lecturaRGB();
maxim();
minim();


// libera memoria de la imagen.
freeBMP(img);
    return 0;
}

