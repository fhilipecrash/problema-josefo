/*
  Practica01
    Sánchez Castro Alan Andrés
    208697345
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    struct nodo *siguiente;
    int coeficiente, variable, exponente;
}Nodo;

typedef Nodo Polinomio;

typedef struct ListaPolinomios{
    struct ListaPolinomios *siguiente;
    Polinomio *polinomio;
}ListaPolinomios;

int inicializarPolinomio(Polinomio **polinomio);
int insertarEnPolinomio(Polinomio *polinomio, int coeficiente, int exponente);

int inicializarListaPolinomios(ListaPolinomios **lista);
int insertarPolinomio(ListaPolinomios *lista, Polinomio *polinomio);

void imprimirPolinomio(Polinomio *polinomio);
void diferenciarPolinomio(Polinomio *polinomio);
void imprimirLista(ListaPolinomios **lista);
void sumarPolinomios(ListaPolinomios *lista, Polinomio *polinomio);

void menuDiferenciacion();
void menuSuma();

int main(){
    char opcion;
    int salir=0;
    do{
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("1) Diferenciaci\xA2n de un polinomio\n");
        printf("2) Sumar dos o m\xA0s polinomios\n");
        printf("3) Salir\n");
        opcion = getchar();
        while(getchar()!='\n');
        switch(opcion){
            case '1':
                menuDiferenciacion();
            break;
            case '2':
                menuSuma();
            break;
            case '3':
                printf("Hasta luego (:\nPresiona ENTER para salir...");
                getchar();
                salir=1;
            break;
            default:
                printf("Ingresa una opci\xA2n v\xA0lida\nPresiona ENTER para continuar...");
                while(getchar()!='\n');
            break;
        }
    }while(!salir);
    return 0;
}

int inicializarPolinomio(Polinomio **polinomio){
    *polinomio = (Polinomio*)malloc(sizeof(Polinomio));
    if(*polinomio!=NULL){
        (*polinomio)->siguiente=NULL;
        (*polinomio)->exponente=-1;
        return 1;
    }
    return 0;
}
int insertarEnPolinomio(Polinomio *polinomio, int coeficiente, int exponente){
    Nodo *aux;
    aux=polinomio;
    while(aux->siguiente!=NULL){
        if(aux->siguiente->exponente==exponente){
            aux->siguiente->coeficiente+=coeficiente;
            return 1;
        }else if(aux->siguiente->exponente<exponente){
            aux=aux->siguiente;
        }else{
            Polinomio *aux2;
            aux2 = (Polinomio*)malloc(sizeof(Polinomio));
            if(aux2==NULL) 
                return 0;
            aux2->coeficiente = coeficiente;
            aux2->exponente = exponente;
            aux2->siguiente = aux->siguiente;
            aux->siguiente = aux2;
            return 1;
        }
    }
    Nodo *aux2;
    aux2 = (Polinomio*)malloc(sizeof(Polinomio));
    if(aux2==NULL) 
        return 0;
    aux2->coeficiente = coeficiente;
    aux2->exponente = exponente;
    aux2->siguiente = NULL;
    aux->siguiente = aux2;
    return 1;
}

int inicializarListaPolinomios(ListaPolinomios **lista){
    *lista = (ListaPolinomios*)malloc(sizeof(ListaPolinomios));
    if(*lista!=NULL){
        (*lista)->siguiente=NULL;
        return 1;
    }
    return 0;
}
int insertarPolinomio(ListaPolinomios *lista, Polinomio *polinomio){
    ListaPolinomios *aux;
    aux=lista;
    while(aux->siguiente!=NULL){
        aux=aux->siguiente;
    }
    ListaPolinomios *aux2;
    if(inicializarListaPolinomios(&aux2)){
        aux2->polinomio=polinomio;
        imprimirPolinomio(aux2->polinomio);
        aux->siguiente=aux2;
        return 1;
    }
    else
        return 0;
}

void imprimirPolinomio(Polinomio *polinomio){
    int flag = 1;
    Nodo *aux = polinomio->siguiente;
    while(aux!=NULL){
        if(flag){
            if(aux->coeficiente!=0){
                flag=0;
                printf("%d",aux->coeficiente);
                if(aux->exponente>1)
                    printf("x^%d", aux->exponente);
                else if(aux->exponente==1)
                    printf("x");
            }
        }else{
            if(aux->coeficiente>0)
                printf("+");
            if(aux->coeficiente!=0){
                printf("%d",aux->coeficiente);
                if(aux->exponente>1)
                    printf("x^%d", aux->exponente);
                else if(aux->exponente==1)
                    printf("x");
            }
        }
        aux=aux->siguiente;
    }
    printf("\n");
}
void diferenciarPolinomio(Polinomio *polinomio){
    Nodo *aux = polinomio->siguiente;
    while(aux!=NULL){
        aux->coeficiente*=aux->exponente;
        aux->exponente--;
        aux=aux->siguiente;
    }
}
void imprimirLista(ListaPolinomios **lista){
    ListaPolinomios *aux = (*lista)->siguiente;
    while(aux!=NULL){
        imprimirPolinomio(aux->polinomio);
        aux=aux->siguiente;
    }
}
void sumarPolinomios(ListaPolinomios *lista,Polinomio *polinomio){
    ListaPolinomios *aux = lista->siguiente;
    Nodo *auxP;
    while(aux!=NULL){
        auxP = aux->polinomio->siguiente;
        while(auxP!=NULL){
            insertarEnPolinomio(polinomio,auxP->coeficiente, auxP->exponente);
            auxP=auxP->siguiente;
        }
        aux=aux->siguiente;
    }
}

void menuDiferenciacion(){
    Polinomio *polinomio;
    int coeficiente,exponente;
    inicializarPolinomio(&polinomio);
    printf("Ingresa el polinomio (ingresa -1 en el exponente para finalizar):\n");
    do{
        printf("Coeficiente: ");
        scanf("%d",&coeficiente);
        printf("Exponente: ");
        scanf("%d",&exponente);
        if(exponente>=0)
            insertarEnPolinomio(polinomio,coeficiente,exponente);
    }while(exponente!=-1);
    printf("Polinomio original: ");
    imprimirPolinomio(polinomio);
    diferenciarPolinomio(polinomio);
    printf("Polinomio diferenciado: ");
    imprimirPolinomio(polinomio);
    printf("Presiona ENTER para continuar...\n");
    while(getchar()!='\n');
    getchar();
}
void menuSuma(){
    ListaPolinomios *lista;
    inicializarListaPolinomios(&lista);
    int cantidadPolinomios=0,salir=0;
    char opcion;
    Polinomio *polinomio;
    int coeficiente,exponente;
    printf("Ingresa por lo menos dos polinomios:\n");
    do{
        inicializarPolinomio(&polinomio);
        printf("Ingresa el polinomio (ingresa -1 en el exponente para finalizar):\n");
        do{
            printf("Coeficiente: ");
            scanf("%d",&coeficiente);
            printf("Exponente: ");
            scanf("%d",&exponente);
            if(exponente>=0)
                insertarEnPolinomio(polinomio,coeficiente,exponente);
        }while(exponente!=-1);
        insertarPolinomio(lista, polinomio);
        cantidadPolinomios++;
        printf("Llevas %d polinomio(s) ingresados\n", cantidadPolinomios);
        printf("Presiona ENTER para continuar...\n");
        while(getchar()!='\n');
        getchar();
        if(cantidadPolinomios>=2){
            printf("¿Deseas ingresar otro polinomio?\n1)S\xA1\n2)No\n");
            opcion=getchar();
            if(opcion=='2')
                salir=1;
        }
    }while(cantidadPolinomios<2||!salir);
    printf("Lista de polinomios:\n");
    imprimirLista(&lista);
    printf("Suma:\n");
    inicializarPolinomio(&polinomio);
    sumarPolinomios(lista,polinomio);
    imprimirPolinomio(polinomio);
    printf("Presiona ENTER para continuar...\n");
    while(getchar()!='\n');
    getchar();
}