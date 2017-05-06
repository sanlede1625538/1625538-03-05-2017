#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define MAXTHREAD 200

void *print (void *arg) 
{
     
     pthread_t id;
     id = pthread_self();
     printf("Hola %u \n",id );
}

int main (int argc , char ** argv) 
{
        //long array[MAXTHREAD];
        pthread_t threadarray[MAXTHREAD];
	int numhilos;
    if (argc !=2)
    {
	printf("por favor ingrese el numero de hilos a usar\n");
	printf("\t%s <numhilos>\n",argv[0]);
	exit(-1);
    }

    numhilos = atoi(argv[1]);
    
    if (numhilos > MAXTHREAD || numhilos == 0 )
    {
            printf("Máximo numero de hilos es %d, solicitó: %d \n" , MAXTHREAD, numhilos);
            exit(-1);
    }

for (int i=0 ; i < numhilos; i++) 
{
// array[i] ? (long) i;
   pthread_create(&threadarray [i] , NULL, &print,NULL);
}

for (int i = 0; i < numhilos; i++)
{
      pthread_join(threadarray [i],NULL);
}
 
return 0;

}
