#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE *fichero;
   int i,j, matriz[1200][1200],rows,columns;

   /* inicializa matriz a 0 */
   for (i = 0; i < 4; i++){
      for (j = 0; j < 4; j++){
         matriz[i][j] = 0;}
    }


   fichero = fopen("img.txt","r");
   if (fichero==NULL)
   {
      printf( "No se puede abrir el fichero.\n" );
      system("pause");
      exit (EXIT_FAILURE);
   }
   i = 0;
   int val;
   while (1)
   {
      if (feof(fichero))
      break;
      for(val=0;val<4;val++){
	fscanf (fichero, "%d", &matriz[i][val]);
	}
      
     
      //fscanf (fichero, "%d %d %d %d \n", &matriz[i][0], &matriz[i][1], &matriz[i][2], &matriz[i][3]);
      i++;
   }


  fscanf( fichero, "%d", &columns );

   fclose(fichero);

   printf( "Contenido del fichero:\n" );
   for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++){
    printf ("%d ", matriz[i][j]);}
     printf ("\n");
   }

   return EXIT_SUCCESS;
}