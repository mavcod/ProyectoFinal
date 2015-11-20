#include <stdio.h>
#include "funcionesRgbHsv.h" 
#include "loadBMP.h"

int main()
{  
printf( "Principal Main \n" ); 
///lectura de imagen
 IMAGE *img;
    loadBMP("lena.bmp", &img);
///
lecturaRGB();
maxim();
minim();


// libera memoria de la imagen.
freeBMP(img);
    return 0;
}

