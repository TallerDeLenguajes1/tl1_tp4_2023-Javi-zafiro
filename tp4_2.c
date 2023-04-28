#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Tarea {
int TareaID; //Numerado en ciclo iterativo
char *Descripcion;
int Duracion; // entre 10 – 100
} typedef Tarea;

struct Nodo{
    Tarea T;
    struct Nodo *Siguiente;
} typedef Nodo;

Nodo * BuscarTareaPorId(Nodo *lista, int y);
//Tarea * BuscarTareaPorPalabra(Tarea **x, char *y, int n);

int main()
{
    int y, i=0;
    char buff[100], r;
    Nodo *listaPendientes, *listaRealizadas, *nuevo, *aux, *aux2, *encontrado;
    listaPendientes=NULL;
    listaRealizadas=NULL;

    srand(time(NULL));


    printf("========================================\n");
    printf("vamos a cargar las tareas ahora \n");
    do
    {
        i++;
        printf("Tarea %d \n", i);
        nuevo=(Nodo *)malloc(sizeof(Nodo));
        nuevo->T.TareaID=i;
        printf("describa brevemente la tarea (maximo 99 digitos) \n");
        gets(buff);
        nuevo->T.Descripcion=(char *)malloc((strlen(buff)+1)*sizeof(char));
        strcpy(nuevo->T.Descripcion, buff);
        nuevo->T.Duracion=10+rand()%90;
        if (listaPendientes==NULL)
        {
            listaPendientes=nuevo;
            nuevo->Siguiente=NULL;
        }else
        {
            nuevo->Siguiente=listaPendientes;
            listaPendientes=nuevo;
        }
        printf("\n");
        printf("desea ingresar una nueva tarea? (S/N) \n");
        scanf("%c", &r);
        fflush(stdin);
        
    } while (r=='s' || r=='S');
    
    /*for (int i = 0; i < n; i++)
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
    }*/
    printf("finalizo la carga de tareas \n");
    printf("========================================\n");
    getchar();
    system("cls");
    aux=listaPendientes;
    aux2=listaRealizadas;
    while (aux!=NULL)
    {
        i=i+1;
        printf("tarea %d \n", aux->T.TareaID);
        printf("descripcion: \n");
        puts(aux->T.Descripcion);
        printf("\n");
        printf("la tarea %d fue realizada? (S/N)\n", aux->T.TareaID);
        scanf("%c", &r);
        fflush(stdin);
        if (r=='s' || r=='S')
        {
            if (listaRealizadas==NULL)
            {
                aux2=aux;
                aux=aux->Siguiente;
                aux2->Siguiente=NULL;
                listaRealizadas=aux2;
                if (listaPendientes==aux2)
                {
                    listaPendientes=aux;
                }
                
                
            }else
            {
                aux2->Siguiente=aux;
                aux=aux->Siguiente;
                aux2=aux2->Siguiente;
                aux2->Siguiente=NULL;
                if (listaPendientes==aux2)
                {
                    listaPendientes=aux;
                }
            }
            
            
        }else
        {
            aux=aux->Siguiente;
        }
        
        
    }
    
    getchar();
    system("cls");

    printf("=====listado de tareas pendientes===== \n");
    printf("\n");
    aux=listaPendientes;
    while (aux!=NULL)
    {
        printf("Tarea %d \n", aux->T.TareaID);
        printf("Descripcion: ");
        puts(aux->T.Descripcion);
        printf("Duracion: %d \n", aux->T.Duracion);
        printf("\n");
        aux=aux->Siguiente;
    }
    

    /*for (int i = 0; i < n; i++)
    {
        if (tareasPendientes[i]!=NULL)
        {
            printf("Tarea %d \n", tareasPendientes[i]->TareaID);
            printf("Descripcion: ");
            puts(tareasPendientes[i]->Descripcion);
            printf("Duracion: %d \n", tareasPendientes[i]->Duracion);
            printf("\n");
        }
        
    }*/
    
    printf("=====listado de tareas realizadas===== \n");
    printf("\n");
    aux2=listaRealizadas;
    while (aux2!=NULL)
    {
        printf("Tarea %d \n", aux2->T.TareaID);
        printf("Descripcion: ");
        puts(aux2->T.Descripcion);
        printf("Duracion: %d \n", aux2->T.Duracion);
        printf("\n");
        aux2=aux2->Siguiente;
    }
    /*for (int i = 0; i < n; i++)
    {
        if (tareasRealizadas[i]!=NULL)
        {
            printf("Tarea %d \n", tareasRealizadas[i]->TareaID);
            printf("Descripcion: ");
            puts(tareasRealizadas[i]->Descripcion);
            printf("Duracion: %d \n", tareasRealizadas[i]->Duracion);
            printf("\n");
        }
        
    }*/
    getchar();
    system("cls");
    /*
    printf("desea realizar alguna busqueda? (S/N) \n");
    scanf("%c", &r);
    fflush(stdin);
    if (r=='s'||r=='S')
    {
        printf("desea realizar una busqueda por id(I) o palabras(P)? \n");
        scanf("%c", &r);
        fflush(stdin);
        switch (r)
        {
        case 'i':
        */
            printf("ingrese el id de la tarea que esta buscando \n");
            scanf("%d", &y);
            fflush(stdin);
            encontrado=BuscarTareaPorId(listaPendientes, y);
            if (encontrado!=NULL)
            {
                printf("la tarea fue encontrada \n");
                printf("Tarea %d: \n", encontrado->T.TareaID);
                printf("descripcion: ");
                puts(encontrado->T.Descripcion);
                printf("duracion: %d \n",encontrado->T.Duracion);
            }else
            {
                encontrado=BuscarTareaPorId(listaRealizadas, y);
                if (encontrado!=NULL)
                {
                    printf("la tarea fue encontrada \n");
                    printf("Tarea %d: \n", encontrado->T.TareaID);
                    printf("descripcion: ");
                    puts(encontrado->T.Descripcion);
                    printf("duracion: %d \n",encontrado->T.Duracion);
                }else
                {
                    printf("la tarea no fue encontrada");
                }
            }
            /*
            break;
        case 'p':
            printf("ingrese una palabra para buscar cocincidencias en las tareas \n");
            gets(buff);
            fflush(stdin);
            tareaid=BuscarTareaPorPalabra(tareasPendientes, buff, n);
            if (tareaid!=NULL)
            {
                printf("la tarea fue encontrada \n");
                printf("Tarea %d: \n", tareaid->TareaID);
                printf("descripcion: ");
                puts(tareaid->Descripcion);
                printf("duracion: %d \n",tareaid->Duracion);
            }else
            {
                tareaid=BuscarTareaPorPalabra(tareasRealizadas, buff, n);
                if (tareaid!=NULL)
                {
                    printf("la tarea fue encontrada \n");
                    printf("Tarea %d: \n", tareaid->TareaID);
                    printf("descripcion: ");
                    puts(tareaid->Descripcion);
                    printf("duracion: %d \n",tareaid->Duracion);
                }else
                {
                    printf("la tarea no fue encontrada");
                }
            }
            break;
        default:
            printf("respuesta incorrecta, aprenda a leer \n");
            break;
            
        }
        
        
    }
    */
    aux=listaPendientes;
    while (aux!=NULL)
    {
        aux2=aux->Siguiente;
        free(aux);
        aux=aux2;
    }
    aux=listaRealizadas;
    while (aux!=NULL)
    {
        aux2=aux->Siguiente;
        free(aux);
        aux=aux2;
    }
    getchar();
    return 0;
}


Nodo * BuscarTareaPorId(Nodo *lista, int y){
    Nodo *aux;
    aux=lista;
    while (aux!=NULL)
    {
        if (aux->T.TareaID==y)
        {
            return aux;
        }
        aux=aux->Siguiente;
    }
    
    
    return NULL;
}
/*
Tarea * BuscarTareaPorPalabra(Tarea **x, char *y, int n){
    char *aux;
    for (int i = 0; i < n; i++)
    {
        if (x[i]!=NULL)
        {
            aux=x[i]->Descripcion;
            if (strstr(aux, y) != NULL)
            {
                return x[i];
            }
            
        }
    }
    return NULL;
}
*/