#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Tarea {
int TareaID; //Numerado en ciclo iterativo
char *Descripcion;
int Duracion; // entre 10 – 100
} typedef Tarea;



int main()
{
    int n;
    char buff[100], r;
    Tarea **tareasPendientes, **tareasRealizadas;

    printf("ingrese la cantidad de tareas a realizar \n");
    scanf("%d", &n);
    fflush(stdin);
    srand(time(NULL));

    tareasPendientes=(Tarea **)malloc(n*sizeof(Tarea *));
    tareasRealizadas=(Tarea **)malloc(n*sizeof(Tarea *));
    for (int i = 0; i < n; i++)
    {
        tareasPendientes[i]=NULL;
        tareasRealizadas[i]=NULL;
    }
    printf("========================================\n");
    printf("vamos a cargar las tareas ahora \n");
    for (int i = 0; i < n; i++)
    {
        printf("Tarea %d \n", (i+1));
        tareasPendientes[i]=(Tarea *)malloc(sizeof(Tarea));
        tareasPendientes[i]->TareaID=i+1;
        printf("describa brevemente la tarea (maximo 99 digitos) \n");
        gets(buff);
        tareasPendientes[i]->Descripcion=(char *)malloc((strlen(buff)+1)*sizeof(char));
        strcpy(tareasPendientes[i]->Descripcion, buff);
        tareasPendientes[i]->Duracion=10+rand()%90;
        printf("\n");
    }
    printf("finalizo la carga de tareas \n");
    printf("========================================\n");
    for (int i = 0; i < n; i++)
    {
        printf("la tarea %d fue realizada? (S/N) \n", (i+1));
        scanf("%c", &r);
        fflush(stdin);
        if (r=='s' || r=='S')
        {
            tareasRealizadas[i]=tareasPendientes[i];
            tareasPendientes[i]=NULL;
            printf("\n");
        }
    }
    printf("=====listado de tareas pendientes===== \n");
    for (int i = 0; i < n; i++)
    {
        if (tareasPendientes[i]!=NULL)
        {
            printf("Tarea %d \n", tareasPendientes[i]->TareaID);
            printf("Descripcion: ");
            puts(tareasPendientes[i]->Descripcion);
            printf("Duracion: %d \n", tareasPendientes[i]->Duracion);
            printf("\n");
        }
        
    }
    
    printf("=====listado de tareas realizadas===== \n");
    for (int i = 0; i < n; i++)
    {
        if (tareasRealizadas[i]!=NULL)
        {
            printf("Tarea %d \n", tareasRealizadas[i]->TareaID);
            printf("Descripcion: ");
            puts(tareasRealizadas[i]->Descripcion);
            printf("Duracion: %d \n", tareasRealizadas[i]->Duracion);
            printf("\n");
        }
        
    }
    

    for (int i = 0; i < n; i++)
    {
        if (tareasPendientes[i]!=NULL)
        {
            free(tareasPendientes[i]->Descripcion);
            free(tareasPendientes[i]);
        }
        if (tareasRealizadas[i]!=NULL)
        {
            free(tareasRealizadas[i]->Descripcion);
            free(tareasRealizadas[i]);
        }
    }
    free(tareasPendientes);
    free(tareasRealizadas);
    getchar();
    return 0;
}
