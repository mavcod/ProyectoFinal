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
Rpixel=img->data[i].r;
Bpixel=img->data[i].g;
Gpixel=img->data[i].b;
//enviando las variables a las funciones.
uint8_t avg = (Rpixel+ Bpixel + Gpixel)/3;
//prototipado funcion promedio
img->data[i].r = avg;
img->data[i].g = avg;
img->data[i].b = avg;
}
writeBMP("demo.bmp", img);
///
lecturaRGB();
maxim();
minim();


// libera memoria de la imagen.
freeBMP(img);
    return 0;
}

