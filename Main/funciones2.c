#include <stdio.h> 
#include <stdlib.h>
#include <math.h> 
#include <stdint.h>
#include "funcionesRgbHsv.h" //funciones

// rango un valor entre 0 y 255
double rango(double i)
{
  if (i < 0) i=0;
  if (i > 1) i=255;
  return i*255;
}


float * ConvHsvRgb(float H, float S, float V)
{


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
		float hf = H/60.0;
		int i = (int)hf;//(int)Math.Floor(hf);
	  	float f = hf - (float)i;
		float pv = 0.8*V * (1 - S);
		float qv = 0.8*V * (1 - S * f);
		float tv = 0.8*V * (1 - S * (1 - f));

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

//	float* x=0;
//	x = (float *) malloc(3);
float x[3]={0,0,0};
	 x[1] =(float)rango((R ));
	 x[2] =(float)rango((G ));
	 x[3] =(float)rango((B ));
	return x;
//	free(x);
}
