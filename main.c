#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define chiamate 10 //definiamo le 10 chiamate giornaliere
#define giorni 31   //definiamo i 31 giorni del mese

char *numeri[]= {"3128971586", "3391457864", "3388972014", "3332651311", "3869754357"};

typedef struct //Dichiarazione struct con i dati delle chiamate.
{
char *chiamante;
int ricevente;
int durata;
float costo;
float totale;
} Dati;

typedef struct //Dichiarazione struct contenente l'archivio mensile.
{
Dati elenco[chiamate][giorni];
} Archivio;

Archivio creaDati() //Funzione per creare l'archivio, essa restituisce una struct di tipo Archivio.
{
int i=0, j=0, k=0, costo;
Archivio archivio;

for (i=0; i<giorni; i++)//usiamo un ciclo per incrementare i giorni a seconda del numero di giorni, cioè 31
    {
    for (k=0; k<chiamate; k++)//usiamo un ciclo per incrementare le chiamate
        {
            archivio.elenco[k][i].chiamante=malloc(sizeof(Dati));
            j=rand()%5;
            strcpy(archivio.elenco[k][i].chiamante, numeri[j]);
            archivio.elenco[k][i].ricevente = 333400000+rand()%999999+1;//richiamiamo la variabile archivio, elenco e ricevente per poter generare un numero a caso del ricevente sommando 300000000+il valore casuale 999999+1*/
            archivio.elenco[k][i].durata = rand()%121;//richiamiamo la variabile archivio, elenco e durata per generare un numero casuale che indica la durata della chiamata*/
            archivio.elenco[k][i].costo=0.10*archivio.elenco[k][i].durata;//richiamiamo la variabile archivio, elenco e costo per generare un numero a caso del costo della chiamata moltiplicando il numero casuale per 10 centesimi, cioè 0.10*/
        }
    }
return archivio;
}


void stampaDati(Archivio archivio) //Procedura per stampare l'archivio, prende come input una struct di tipo Archivio.
{
int i=0, k=0;
for (i=0; i<=giorni-1;)//usiamo un ciclo per fare in modo di generare 10 registri per 31 giorni
{
printf("\n\n\t\t          Giorno %d          \n\n Chiamante\t\tRicevente    Durata\tCosto", i+1);
for (k=0; k<chiamate; k++)//usiamo un ciclo per poter generare le chiamate con il chiamante, il ricevente, la durata, e il costo della chiamata
{
printf("\n[C.%d] %s\t%d    %d min.\t%-.2f euro", k+1, archivio.elenco[k][i].chiamante, archivio.elenco[k][i].ricevente, archivio.elenco[k][i].durata, archivio.elenco[k][i].costo);
}
printf("\n\n\t\tInvio per scorrere l'elenco.");
getchar();
i++;//incrementiamo il ciclo utilizzando la variabile i
}
}

void stampaElenco() //Procedura per stampare l'elenco dei numeri.
{
int i=0;
printf("I numeri presenti nel registro sono :\n");
for (i=0; i<5; i++)
printf("N%d (+39)%s\n", i+1, numeri[i]);
getchar();
}

int main()
{
srand(time(NULL));//Con srand(), poniamo il seme uguale all'istante di tempo nel quale il programma viene eseguito, tramite la function time()
//In questo modo, per ogni eseguzione del programma, il seme sarà sempre diverso, generando con la function rand() (che vediamo in seguito) numeri diversi
Archivio simula;
stampaElenco();
simula = creaDati();
stampaDati(simula);
return 0;
}
