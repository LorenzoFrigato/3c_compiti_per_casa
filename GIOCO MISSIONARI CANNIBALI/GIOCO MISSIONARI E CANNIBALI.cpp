#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


/* PROTOTIPI DELLE FUNZIONI */

void disegnaConfigurazione(void);
void interazioneUtente(void);
void eseguiAzione(void);
void controllaVittoria(void);
void inizializza(void);
void messaggioFinale(void);
void muoviMissionario (void);
void muoviCannibale(void);
void muoviBarca(void);

/****************************/


/* VARIABILI GLOBALI E TIPI DI DATO */
unsigned char a; // variabile che mi serve solo per visualizzare il messaggio d'errore logico

unsigned char missionari_sx, missionari_dx;
// numero di preti presenti su ciascuna sponda
// assumono valori tra 0 e 3

unsigned char cannibali_sx, cannibali_dx;
// numero di cannibali presenti su ciascuna sponda
// assumono valori tra 0 e 3

unsigned char lato_barca;
// assume solo due valori: 'd' e 's'

unsigned char missionariBarca, cannibaliBarca;
// assumono valori da 0 a 2

bool gioco_terminato;
// assume solo due valori: true e false

bool vittoria;
// assume solo due valori: true e false
// vale true se e solo se l'utente ha vinto il gioco

bool sconfitta;
// assume solo due valori: true e false
// vale true se e solo se l'utente ha perso il gioco

unsigned char personaggio;
// scelta personaggio da muovere

unsigned char azione;
// scelta azione da fare

unsigned char direzione;
// direzione azione

unsigned char postoSx;
// valore posto barca sx

unsigned char postoDx;
// valore posto barca dx


/************************************/


int main()
{
    inizializza();
    // questa funzione imposta i valori iniziali
    // per tutte le variabili del gioco
    while(!gioco_terminato){
      disegnaConfigurazione();
      interazioneUtente();
      eseguiAzione();
      // qui aggiorniamo il valore della variabile
      // che controlla la terminazione del gioco
	  controllaVittoria();
    }
    messaggioFinale();
    system("PAUSE");
    return 0;
}



void controllaVittoria(void){
if (lato_barca=='d'){
	if ((missionari_sx < cannibali_sx && missionari_sx > 0)||
          (missionari_dx + missionariBarca < cannibali_dx && missionari_dx > 0) )
         sconfitta = true;
         }
if (lato_barca== 's'){
    if ((missionari_sx + missionariBarca < cannibali_sx && missionari_sx > 0)||
          (missionari_dx < cannibali_dx && missionari_dx > 0) )
         sconfitta = true;
         }
	if (missionari_sx == 3 && cannibali_sx == 3)
         vittoria = true;
    if (vittoria || sconfitta)
         gioco_terminato = true;
}

void inizializza(void){
    //istruzioni che inizializzano le variabili del gioco
    system("CLS");
    sconfitta = false;
    vittoria = false;
    gioco_terminato = false;
    missionari_sx = 0;
    cannibali_sx = 0;
    missionari_dx = 3;
    cannibali_dx = 3;
    missionariBarca = 0;
    cannibaliBarca = 0;
    lato_barca = 'd';
    postoSx ='_';
    postoDx ='_';
    cout << "...................BENVENUTO AL GIOCO CANNIBALI E MISSIONARI..................."<<endl;
    cout << endl;
    cout << "SCOPO DEL GIOCO: " << endl;
    cout << "_______________________________________________________________________________" << endl;
    cout << endl;
    cout << "Porta i missionari e i cannibali sull'altra sponda del fiume" << endl;
    cout << "Usa la barca, ma attento a non lasciare i       " << endl;
    cout << "missionari in minoranza.... verranno mangiati!  " << endl;
    cout << "Usa i tasti per selezionare e muovere i personaggi, "<< endl;
    cout << "ma attento a fare scelte sensate!!"<< endl;
    cout << "_______________________________________________________________________________" << endl;
    system("PAUSE");
}

void messaggioFinale(void){
    system("CLS");
    if (gioco_terminato && sconfitta)
        cout << "Hai perso!" << endl;
    if (gioco_terminato && vittoria)
        cout << "Hai vinto!" << endl;
}


void disegnaConfigurazione(void){
 // DISEGNAZIONE INTERFACCIA INIZIALE

 system ("CLS");
cout << "............................CANNIBALI E MISSIONARI.............................";

cout << "     ";
int i;
i=1;
    for (int i=1; i <= missionari_sx; i++)
   {
       cout << "m";
       cout << " ";
   }
    for (int i=1; i <=cannibali_sx; i++)
   {
       cout << "c";
       cout << " ";
   }

cout << "                              ";

    for (int i=1; i <= missionari_dx; i++)
   {
       cout << "m";
       cout << " ";
   }
   for (int i=1; i <=cannibali_dx; i++)
   {
       cout << "c";
       cout << " ";
   }
   if (missionariBarca == 2)
        postoDx = 'm';
    else {
        if (cannibaliBarca == 2)   // due cannibali occupano entrambi i posti in barca
            postoSx = 'c';
        else {
            // i missionari cominciano ad occupare i posti in barca a partire da sinistra
            if (missionariBarca >= 1)
                postoSx = 'm';
            // i cannibali cominciano ad occupare i posti in barca a partire da destra
            if (cannibaliBarca >= 1)
                postoDx = 'c';
            }
        }
   cout << endl;
   if (lato_barca == 's')
        cout << "---------------_(" << postoSx << "|" << postoDx << ")__________ ---------------" << endl;
    if (lato_barca == 'd')
        cout << "---------------__________(" << postoSx << "|" << postoDx << ")_ ---------------" << endl;
    cout << "\n";
}


void interazioneUtente(void){
   /*
  Vengono  3 domande all'utente :
 - che tipo di elemento vuoi muovere?
   + l'utente ha tre opzioni: (b / c / m)
     b per barca
     c per cannibale
     m per missionario
 - che azione vuoi fargli compiere?
   + l'utente ha tre opzioni: (g / s / n)
     g per smonta giù dalla barca
     s per monta su in barca
     n per fai navigare la barca
 - da dove vuoi muovere tale elemento?
   + l'utente ha tre opzioni: (b / d / s)
     b per barca
     d per sponda destra
     s per sponda sinistra
*/
bool errore_inserimento = false;
    do{
    if (errore_inserimento){
    cout << "Inserisci valori corretti!!! (m;c;b)" << endl;
    }
    cout << "Che tipo di elemento vuoi muovere? " << endl;
    cout << "Premi il tasto corrispondenete se vuoi muovere: " << endl;
    cout << "m = missionario" << endl << "c = cannibale" << endl << "b = barca"<< endl;
    cin >> personaggio;
    errore_inserimento=(personaggio != 'b' && personaggio != 'c' && personaggio != 'm');
    }while (errore_inserimento);

    system ("CLS");
    switch (personaggio){

        case('m'):
        do{
        if (errore_inserimento){
        cout << "Inserisci valori corretti!!! (g;s)";
        }
        cout << "Che cosa deve fare il missionario?"<< endl;
        cout << "Premi il tasto corrispondenete per l'azione che deve fare: "<< endl;
        cout << "g = smontare dalla barca" << endl << "s = salire sulla barca" << endl;
        cin >> azione;
        errore_inserimento=(azione!= 'g' && azione != 's');
        }  while (errore_inserimento);
        system ("CLS");
        do {
        if (errore_inserimento){
        cout << "Inserisci valori corretti!!! (d;s;b)";
        }
        cout << "Da dove vuoi muovere il missionario?" << endl;
        cout << "d = dalla sponda destra" << endl << "s = dalla sponda sinistra" << endl << "b = dalla barca"<< endl;
        cin >> direzione;
        errore_inserimento=(direzione!='d'&& direzione!= 's' && direzione != 'b');
        } while (errore_inserimento);
        break;

        case ('c'):
        do {
        if (errore_inserimento){
        cout << "Inserisci valori corretti!!! (g;s)";
        }
        cout << "Che cosa deve fare il cannibale?"<< endl;
        cout << "Premi il tasto corrispondenete per l'azione che deve fare: "<< endl;
        cout << "g = smontare dalla barca" << endl << "s = salire sulla barca" << endl;
        cin >> azione;
        errore_inserimento=(azione!= 'g' && azione != 's');
        }while (errore_inserimento);
        system("CLS");
        do {
        if (errore_inserimento){
        cout << "Inserisci valori corretti!!! (d;s;b)";
        }
        cout << "Da dove vuoi muovere il cannibale?"<< endl;
        cout << "d = dalla sponda destra" << endl << "s = dalla sponda sinistra" << endl << "b = dalla barca"<< endl;
        cin >> direzione;
        errore_inserimento=(direzione!='d'&& direzione!= 's' && direzione != 'b');
        } while (errore_inserimento);
        break;

        case ('b'):
        do {
        if (errore_inserimento){
        cout << "Inserisci valori corretti!!! (n)";
        }
        cout << "Che cosa deve fare la barca?"<< endl;
        cout << "Premi il tasto corrispondenete per l'azione che deve fare: "<< endl;
        cout << "n = fai partire la barca verso la riva opposta"<< endl;
        cin >> azione;
        errore_inserimento=(azione != 'n');
        }while (errore_inserimento);
        break;
        }

    }







void eseguiAzione(void){

switch(personaggio){

    case ('m'):
     muoviMissionario();
    break;

    case ('c'):
     muoviCannibale();
    break;

    case ('b'):
        muoviBarca();
    break;



}
}
void muoviMissionario(void) {
bool errore_logico;
errore_logico= false;
switch(azione){
        case ('g'):

            switch(direzione){

            case('d'):
            errore_logico = (missionariBarca==0 || lato_barca=='s');
            if(errore_logico) {
            cout << "Errore logico! Controlla di aver dato una combinazione di scelte con un senso logico!!"<< endl;
            system("PAUSE");
            break;
            }
            missionariBarca--;
            missionari_dx++;
            break;

            case('s'):
            errore_logico = (missionariBarca==0 || lato_barca=='d');
            if(errore_logico) {
            cout << "Errore logico! Controlla di aver dato una combinazione di scelte con un senso logico!!"<< endl;
            system("PAUSE");
            break;
            }
            missionariBarca--;
            missionari_sx++;
            break;

            case('b'):
            cout << "Errore logico! Controlla di aver dato una combinazione di scelte con un senso logico!!"<< endl;
            system("PAUSE");
            break;

            }
        break;

        case ('s'):
            switch(direzione){

            case('d'):
            errore_logico=(missionari_dx==0 || missionariBarca==2 || cannibaliBarca==2 ||( missionariBarca==1 & cannibaliBarca==1));
            if (errore_logico){
            cout << "Errore logico! Controlla di aver dato una combinazione di scelte con un senso logico!!"<< endl;
           system("PAUSE");
            break;
            }
            missionariBarca++;
            missionari_dx--;
            break;

            case('s'):
            errore_logico=(missionari_sx==0 || missionariBarca==2 || cannibaliBarca==2 || (missionariBarca==1 &cannibaliBarca==1));
            if (errore_logico){
            cout << "Errore logico! Controlla di aver dato una combinazione di scelte con un senso logico!!"<< endl;
            system("PAUSE");
            break;
            }
            missionariBarca++;
            missionari_sx--;
            break;

            case('b'):
            cout << "Errore logico! Controlla di aver dato una combinazione di scelte con un senso logico!!"<< endl;
            system("PAUSE");
            break;

            }
        break;
}
}
void muoviCannibale (void){
bool errore_logico;
errore_logico= false;
switch(azione){
        case ('g'):

            switch(direzione){

            case('d'):
            errore_logico = (cannibaliBarca==0 || lato_barca=='s');
            if(errore_logico) {
            cout << "Errore logico! Controlla di aver dato una combinazione di scelte con un senso logico!!"<< endl;
            system("PAUSE");
            break;
            }
            cannibaliBarca--;
            cannibali_dx++;
            break;

            case('s'):
            errore_logico = (cannibaliBarca==0 || lato_barca=='d');
            if(errore_logico) {
            cout << "Errore logico! Controlla di aver dato una combinazione di scelte con un senso logico!!"<< endl;
            system("PAUSE");
            break;
            }
            cannibaliBarca--;
            cannibali_sx++;
            break;

            case('b'):
            cout << "Errore logico! Controlla di aver dato una combinazione di scelte con un senso logico!!"<< endl;
            system("PAUSE");
            break;

            }
        break;

        case ('s'):
            switch(direzione){

            case('d'):
            errore_logico=(cannibali_dx==0 || missionariBarca==2 || cannibaliBarca==2 || (missionariBarca==1 & cannibaliBarca==1));
            if (errore_logico){
            cout << "Errore logico! Controlla di aver dato una combinazione di scelte con un senso logico!!"<< endl;
            system("PAUSE");
            break;
            }
            cannibaliBarca++;
            cannibali_dx--;
            break;

            case('s'):
            errore_logico=(cannibali_sx==0 || missionariBarca==2 || cannibaliBarca==2 || (missionariBarca==1 &cannibaliBarca==1));
            if (errore_logico){
            cout << "Errore logico! Controlla di aver dato una combinazione di scelte con un senso logico!!"<< endl;
            system("PAUSE");
            break;
            }
            cannibaliBarca++;
            cannibali_sx--;
            break;

            case('b'):
            cout << "Errore logico! Controlla di aver dato una combinazione di scelte con un senso logico!!"<< endl;
            system("PAUSE");
            break;

            }
        break;


        }
}
void muoviBarca (void){
bool errore_logico;
errore_logico= false;
errore_logico=(cannibaliBarca==0 && missionariBarca==0);
    if (errore_logico){
    cout <<"Errore logico! Controlla di aver dato una combinazione di scelte con un senso logico!!"<< endl;
    system("PAUSE");
    }
    if(lato_barca=='d')
        lato_barca= 's';

    else
        lato_barca='d';


}
