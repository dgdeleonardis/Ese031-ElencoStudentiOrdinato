#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisci le costanti
#define MAX_STRLEN 30
#define N 3
// Definisci il tipo di dato struct s_studente
struct s_studente {
    char nome[MAX_STRLEN];
    char cognome[MAX_STRLEN];
    unsigned eta;
    char classe[MAX_STRLEN];
};
// Definisci studente come struct s_studente
struct s_studente v[N];
// Dichiara il prototipo della funzione di ordinamento
void funzioneOrdinamento (struct s_studente v[]); // Algoritmo di Ordinamento ingenuo : Selection Sort

int main(int argc, char** argv) {
    // Dichiara le variabili locali
    int i;
    // Codice per l'inserimento, da parte dell'utente, dei dati
    for(i = 0; i < N; i++) {
        printf("Inserisci il nome dello studente %d : ", i);
        scanf("%s", v[i].nome);
        printf("Inserisci il cognome dello studente %d : ", i);
        scanf("%s", v[i].cognome);
        printf("Inserisci l'eta' dello studente %d : ", i);
        scanf("%d", &(v[i].eta));
        printf("Inserisci la classe dello studente %d : ", i);
        scanf("%s", v[i].classe);
    }
    // Ordina l'elenco (con funzione)
    funzioneOrdinamento(v);
    // Codice per la stampa dei dati (uno studente per riga)
    for(i = 0; i < N; i++) {
        printf("%s; %s; %d; %s;\n", v[i].nome, v[i].cognome, v[i].eta, v[i].classe);

    }
    return (EXIT_SUCCESS);
}

// Definisci la funzione di ordinamento
void funzioneOrdinamento (struct s_studente v[]) {
    int i, j, iMin;
    struct s_studente temp;
 //Corpo della funzione   
    for(i = 0; i < N-1; i++) {
        iMin = i;
        for(j = i + 1; j < N; j++) {
            if(strcmp(v[j].cognome, v[iMin].cognome ) < 0) {
                iMin = j;
            }
        }
        if(i != iMin) {
            temp = v[i];
            v[i] = v[iMin];
            v[iMin] = temp;
        }
    }
}