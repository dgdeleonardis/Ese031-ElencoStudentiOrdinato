#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisci le costanti
#define N 3
#define MAX_STRLEN 30

// Definisci il tipo di dato struct s_studente
struct s_studente {
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    int eta;
    char classe[MAX_STRLEN+1];
};

// Definisci studente come struct s_studente
typedef struct s_studente studente;

// Dichiara il prototipo della funzione di ordinamento
int ordinaElenco(studente elenco[], int n);

int main(int argc, char** argv) {
    // Dichiara le variabili locali
    studente elenco[N];
    char stringaInput[MAX_STRLEN+1];
    int i;
    
    // Codice per l'inserimento, da parte dell'utente, dei dati
    printf("Inserisci i dati per %d studenti\n", N);
    for(i=0; i<N; i++) {
        printf("\nInserisci il nome (%d max): ", MAX_STRLEN);
        scanf("%s", stringaInput);
        strcpy(elenco[i].nome, stringaInput);
        printf("Inserisci il cognome (%d max): ", MAX_STRLEN);
        scanf("%s", stringaInput);
        strcpy(elenco[i].cognome, stringaInput);
        printf("Inserisci l'eta': ");
        scanf("%d", &(elenco[i].eta));
        printf("Inserisci la classe (%d max): ", MAX_STRLEN);
        scanf("%s", stringaInput);
        strcpy(elenco[i].classe, stringaInput);
    }
    
    // Ordina l'elenco (con funzione)
    ordinaElenco(elenco, N);
    
    // Codice per la stampa dei dati (uno studente per riga)
    printf("\n\nElenco ordinato\n");
    for(i=0; i<N; i++) {
        printf("%s; %s; %d; %s\n", 
                elenco[i].nome,
                elenco[i].cognome,
                elenco[i].eta,
                elenco[i].classe);
    }
    
    return (EXIT_SUCCESS);
}

// Definisci la funzione di ordinamento
int ordinaElenco(studente elenco[], int n) {
    int r = 0;
    if(n > 0) {
        // Selection sort
        int i, j, minimo;
        studente temp;
        for(i=0; i<n-1; i++) {
            minimo = i;
            for(j=i+1; j<n; j++) {
                if(strcmp(elenco[j].cognome, elenco[minimo].cognome) < 0)
                        minimo = j;
            }
            if(minimo != i) {
                strcpy(temp.nome, elenco[i].nome);
                strcpy(temp.cognome, elenco[i].cognome);
                temp.eta = elenco[i].eta;
                strcpy(temp.classe, elenco[i].classe);
                
                strcpy(elenco[i].nome, elenco[minimo].nome);
                strcpy(elenco[i].cognome, elenco[minimo].cognome);
                elenco[i].eta = elenco[minimo].eta;
                strcpy(elenco[i].classe, elenco[minimo].classe);
                
                strcpy(elenco[minimo].nome, temp.nome);
                strcpy(elenco[minimo].cognome, temp.cognome);
                elenco[minimo].eta = temp.eta;
                strcpy(elenco[minimo].classe, temp.classe);
                
                //temp = elenco[i];
                //elenco[i] = elenco[minimo];
                //elenco[minimo] = temp;
            }
        }
    }
    else
        r = -1;
    return r;
}