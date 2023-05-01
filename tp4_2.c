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
Nodo * BuscarTareaPorPalabra(Nodo *lista, char *y);
void Eliminar(Nodo *x);
void MostrarDatos(Nodo *lista);

int main()
{
    int y, i=0, l=0;
    char buff[100], r;
    Nodo *listaPendientes, *listaRealizadas, *listaEnProgreso, *nuevo, *aux, *aux2, *encontrado;
    listaPendientes=NULL;
    listaRealizadas=NULL;
    listaEnProgreso=NULL;

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
    
    printf("finalizo la carga de tareas \n");
    printf("========================================\n");
    getchar();
    system("cls");
    
    do
    {
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
        printf("=====listado de tareas en progreso===== \n");
        printf("\n");
        aux2=listaEnProgreso;
        while (aux2!=NULL)
        {
            printf("Tarea %d \n", aux2->T.TareaID);
            printf("Descripcion: ");
            puts(aux2->T.Descripcion);
            printf("Duracion: %d \n", aux2->T.Duracion);
            printf("\n");
            aux2=aux2->Siguiente;
        }
        printf("seleccione una de las tareas ingresando su id \n");
        scanf("%d",&y);
        fflush(stdin);
        encontrado=BuscarTareaPorId(listaPendientes, y);
        getchar();
        system("cls");
        if (encontrado!=NULL)
        {
            printf("---------LA TAREA FUE ENCONTRADA--------- \n");
            printf("Pertenece a la lista de tareas Pendientes \n");
            l=1;
            printf("Tarea %d: \n", encontrado->T.TareaID);
            printf("descripcion: ");
            puts(encontrado->T.Descripcion);
            printf("duracion: %d \n",encontrado->T.Duracion);
        }else
        {
            encontrado=BuscarTareaPorId(listaRealizadas, y);
            if (encontrado!=NULL)
            {
                printf("---------LA TAREA FUE ENCONTRADA--------- \n");
                printf("Pertenece a la lista de tareas Realizadas \n");
                l=2;
                printf("Tarea %d: \n", encontrado->T.TareaID);
                printf("descripcion: ");
                puts(encontrado->T.Descripcion);
                printf("duracion: %d \n",encontrado->T.Duracion);
            }else
            {
                encontrado=BuscarTareaPorId(listaEnProgreso, y);
                if (encontrado!=NULL)
                {
                    printf("---------LA TAREA FUE ENCONTRADA--------- \n");
                    printf("Pertenece a la lista de tareas en Progreso \n");
                    l=3;
                    printf("Tarea %d: \n", encontrado->T.TareaID);
                    printf("descripcion: ");
                    puts(encontrado->T.Descripcion);
                    printf("duracion: %d \n",encontrado->T.Duracion);
                }else{
                    printf("**********LA NO TAREA FUE ENCONTRADA********** \n");
                }
            }
        }
        if (encontrado!=NULL)
        {
            switch (l)
            {
            case 1:
                aux=listaPendientes;
                break;
            case 2:
                aux=listaRealizadas;
                break;
            case 3:
                aux=listaEnProgreso;
                break;
            default:
                break;
            }
            printf("que desea realizar con esta tarea? \n");
            printf("1. Mover \n");
            printf("2. Eliminar \n");
            printf("3. No Hacer Nada \n");
            printf("ingrese el numero de la tarea que desea realizar (1, 2, 3) \n");
            scanf("%d",&y);
            fflush(stdin);
            getchar();
            system("cls");
            switch (y)
            {
            case 1:
                printf("a que lista desea mover la tarea? \n");
                printf("1. Lista de Tareas Pendientes \n");
                printf("2. Lista de Tareas Realizadas \n");
                printf("3. Lista de Tareas En Progreso \n");
                printf("ingrese el numero de la lista destino \n");
                scanf("%d", &l);
                fflush(stdin);
                switch (l)
                {
                case 1:
                    if (aux!=listaPendientes)
                    {
                        i=0;
                        do
                        {
                            if (aux==encontrado)
                            {
                                aux=encontrado->Siguiente;
                                if (aux==listaRealizadas->Siguiente)
                                {
                                    listaRealizadas=aux;
                                }else
                                {
                                    listaEnProgreso=aux;
                                }
                                i=1;
                            }else
                            {
                                if (aux->Siguiente==encontrado)
                                {
                                    aux->Siguiente=encontrado->Siguiente;
                                    i=1;
                                }
                                else
                                {
                                    aux=aux->Siguiente;
                                }
                            }
                        } while (i!=1);
                        nuevo=listaPendientes;
                        listaPendientes=encontrado;
                        listaPendientes->Siguiente=nuevo;
                        printf("SE MOVIO CORRECTAMENTE LA TAREA \n");
                    }
                    
                    break;
                case 2:
                    if (aux!=listaRealizadas)
                    {
                        i=0;
                        do
                        {
                            if (aux==encontrado)
                            {
                                aux=encontrado->Siguiente;
                                if (aux==listaPendientes->Siguiente)
                                {
                                    listaPendientes=aux;
                                }else
                                {
                                    listaEnProgreso=aux;
                                }
                                i=1;
                            }else
                            {
                                if (aux->Siguiente==encontrado)
                                {
                                    aux->Siguiente=encontrado->Siguiente;
                                    i=1;
                                }
                                else
                                {
                                    aux=aux->Siguiente;
                                }
                            }
                        } while (i!=1);
                        nuevo=listaRealizadas;
                        listaRealizadas=encontrado;
                        listaRealizadas->Siguiente=nuevo;
                        printf("SE MOVIO CORRECTAMENTE LA TAREA \n");
                    }
                    
                    break;
                case 3:
                    if (aux!=listaEnProgreso)
                    {
                        i=0;
                        do
                        {
                            if (aux==encontrado)
                            {
                                aux=encontrado->Siguiente;
                                if (aux==listaRealizadas->Siguiente)
                                {
                                    listaRealizadas=aux;
                                }else
                                {
                                    listaPendientes=aux;
                                }
                                i=1;
                            }else
                            {
                                if (aux->Siguiente==encontrado)
                                {
                                    aux->Siguiente=encontrado->Siguiente;
                                    i=1;
                                }
                                else
                                {
                                    aux=aux->Siguiente;
                                }
                            }
                        } while (i!=1);
                        nuevo=listaEnProgreso;
                        listaEnProgreso=encontrado;
                        listaEnProgreso->Siguiente=nuevo;
                        printf("SE MOVIO CORRECTAMENTE LA TAREA \n");
                    }
                    
                    break;
                
                default:
                printf("el numero ingresado no es valido, el movimiento fue cancelado \n");
                    break;
                }
                break;
            case 2:
                i=0;
                do
                {
                    if (aux==encontrado)
                    {
                        aux=encontrado->Siguiente;
                        if (aux==listaRealizadas->Siguiente)
                        {
                            listaRealizadas=aux;
                        }else
                        {
                            if (aux==listaRealizadas->Siguiente)
                            {
                                listaRealizadas=aux;
                            }else
                            {
                                listaEnProgreso=aux;
                            }
                        }
                        i=1;
                    }else
                    {
                        if (aux->Siguiente==encontrado)
                        {
                            aux->Siguiente=encontrado->Siguiente;
                            i=1;
                        }
                        else
                        {
                            aux=aux->Siguiente;
                        }
                    }
                } while (i!=1);
                Eliminar(encontrado);
                printf("SE ELIMINO CORRECTAMENTE LA TAREA \n");
                break;
            default:
                if (y==3)
                {
                    printf("usted decidio no hacer nada, la tarea no sera modificada \n");
                }else
                {
                    printf("el numero ingresado no es valido, se cancela esta operacion \n");
                }
                break;
            }
        }
        printf("desea modificar otra tarea?(S/N) \n");
        scanf("%c",&r);
        fflush(stdin);
    } while (r=='s'||r=='S');
    getchar();
    system("cls");
    printf("##### LISTADO FINAL DE TAREAS #####\n");
    printf("=====listado de tareas pendientes===== \n");
    printf("\n");
    aux=listaPendientes;
    if (aux==NULL)
    {
        printf("+Lista vacia+\n");
    }else{
        while (aux!=NULL)
        {
            printf("Tarea %d \n", aux->T.TareaID);
            printf("Descripcion: ");
            puts(aux->T.Descripcion);
            printf("Duracion: %d \n", aux->T.Duracion);
            printf("\n");
            aux=aux->Siguiente;
        }
        MostrarDatos(listaPendientes);
    }
    
    printf("=====listado de tareas realizadas===== \n");
    printf("\n");
    aux2=listaRealizadas;
    if (aux2==NULL)
    {
        printf("+Lista vacia+\n");
    }else{
        while (aux2!=NULL)
        {
            printf("Tarea %d \n", aux2->T.TareaID);
            printf("Descripcion: ");
            puts(aux2->T.Descripcion);
            printf("Duracion: %d \n", aux2->T.Duracion);
            printf("\n");
            aux2=aux2->Siguiente;
        }
        MostrarDatos(listaRealizadas);
    }

    printf("=====listado de tareas en progreso===== \n");
    printf("\n");
    aux2=listaEnProgreso;
    if (aux2==NULL)
    {
        printf("+Lista vacia+\n");
    }else{
    while (aux2!=NULL)
    {
        printf("Tarea %d \n", aux2->T.TareaID);
        printf("Descripcion: ");
        puts(aux2->T.Descripcion);
        printf("Duracion: %d \n", aux2->T.Duracion);
        printf("\n");
        aux2=aux2->Siguiente;
    }
    MostrarDatos(listaEnProgreso);
    }
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
    aux=listaEnProgreso;
    while (aux!=NULL)
    {
        aux2=aux->Siguiente;
        free(aux);
        aux=aux2;
    }
    getchar();
    return 0;
}

void Eliminar(Nodo *x){
    free(x);
}

void MostrarDatos(Nodo *lista){
    int suma=0, cantidad=0;
    Nodo *aux;
    aux=lista;
    while (aux!=NULL)
    {
        suma=suma+aux->T.Duracion;
        cantidad++;
        aux=aux->Siguiente;
    }
    if (cantidad!=0 || suma!=0)
    {
        printf("la cantidad de tareas es: %d \n", cantidad);
        printf("el tiempo asociado a esta lista es: %d \n", suma);
    }else
    {
        printf("la lista no tiene tareas \n");
    }
    
    
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

Nodo * BuscarTareaPorPalabra(Nodo *lista, char *y){
    Nodo *auxl;
    char *aux;
    auxl=lista;
    while(auxl!=NULL)
    {
        aux=auxl->T.Descripcion;
        if (strstr(aux, y) != NULL)
        {
            return auxl;
        }
        auxl=auxl->Siguiente;  
    }
    return NULL;
}
