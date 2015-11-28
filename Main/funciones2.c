#include <stdio.h> 
#include <stdlib.h>
#include <math.h> 
#include <stdint.h>
#include "funcionesRgbHsv.h" //funciones

float* ConvHsvRgb(float H, float S, float V)
{
float* x;
x = (float *) malloc(3);

  while (H < 0) { H += 360; };
  while (H >= 360) { H -= 360; };

// funcion para la conversion
  double R, G, B;

if (V <= 0)
    { R = G = B = 0; }
  else if (S <= 0)
  {
    R = G = B = V;
  }
  else
  {
	double hf = H/60.0;
	int i = H;//(int)Math.Floor(hf);
  
	double f = hf - i;
	double pv = V * (1 - S);
	double qv = V * (1 - S * f);
	double tv = V * (1 - S * (1 - f));
    
	if(i==0){
		R = V;
        	G = tv;
        	B = pv;
	}else if(i==1){
		R = qv;
        	G = V;
        	B = pv;

	}else if(i==2){
		R = pv;
        	G = V;
        	B = tv;
	}else if(i==3){
		R = pv;
        	G = qv;
        	B = V;

	}else if(i==4){
		R = tv;
        	G = pv;
        	B = V;

	}else if(i==5){
		R = V;
        	G = pv;
        	B = qv;
	}else if(i==6){
		R = V;
        	G = tv;
        	B = pv;
	}else if(i==-1){
		R = V;
        	G = pv;
        	B = qv;
	}

  }


//lineas para guardar en la matriz imagen la matriz Hsv
//x[1] = rango((int)(H * 255));
//x[2] = rango((int)(S * 255));
//x[3] = rango((int)(V * 1));

  x[1] = rango((int)(R * 255.0));
  x[2] = rango((int)(G * 255.0));
  x[3] = rango((int)(B * 255.0));
return x;
}

// rango un valor entre 0 y 255
int rango(int i)
{
  if (i < 0) return 0;
  if (i > 255) return 255;
  return i;
}


