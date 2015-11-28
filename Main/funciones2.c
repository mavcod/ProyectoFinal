#include <stdio.h> 
#include <stdlib.h>
#include <math.h> 
#include <stdint.h>
void HsvToRgb(double h, double S, double V)
{
 int r,g,b;

  double H = h;
  while (H < 0) { H += 360; };
  while (H >= 360) { H -= 360; };
  double R, G, B;
  if (V <= 0)
    { R = G = B = 0; }
  else if (S <= 0)
  {
    R = G = B = V;
  }
  else
  {
    double hf = H / 60.0;
    int i = hf;//(int)Math.Floor(hf);
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
  r = rango((int)(R * 255.0));
  g = rango((int)(G * 255.0));
  b = rango((int)(B * 255.0));

}


// rango un valor entre 0 y 255
int rango(int i)
{
  if (i < 0) return 0;
  if (i > 255) return 255;
  return i;
}


