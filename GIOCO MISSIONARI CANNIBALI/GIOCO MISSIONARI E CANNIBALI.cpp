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

/****************************

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

unsigned char posizione;
//  posizione iniziale paersonaggio

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



void controllaVittoria(){
if (lato_barca=='d'){
	if ((missionari_sx < cannibali_sx && missionari_sx > 0)||
          (missionari_dx + missionariBarca < cannibali_dx+ cannibaliBarca && missionari_dx > 0) )
         sconfitta = true;
         }
if (lato_barca== 's'){
    if ((missionari_sx + missionariBarca < cannibali_sx + cannibaliBarca && missionari_sx > 0)||
          (missionari_dx < cannibali_dx && missionari_dx > 0) )
         sconfitta = true;
         }
	if (missionari_sx == 3 && cannibali_sx == 3)
         vittoria = true;
    if (vittoria || sconfitta)
         gioco_terminato = true;
}

void inizializza(){
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
    cout << endl;
    cout << "____________________BENVENUTO AL GIOCO CANNIBALI E MISSIONARI__________________  " << endl;
    cout << "\t \t \t       SCOPO DEL GIOCO: " << endl;
    cout << endl;
    cout << "\t      Aiuta i missionari ed i cannibali a guadare il fiume: " << endl;
    cout << "\t    Essi hanno solamente una barca da 2 posti ma sono in 6!!" << endl;
    cout << "\t      Usa i tasti per selezionare e muovere i personaggi, "<< endl;
    cout << " Attento, pero', a non lasciare i missionari in minoranza, verranno mangiati!!! " << endl;
    cout << "\t\t\t      Buona fortuna!!!!!"<< endl;
    cout << "________________________________________________________________________________" << endl;
    system("PAUSE");
}

void messaggioFinale(){
    system ("CLS");
    if (gioco_terminato && sconfitta)
        cout << "Hai perso!" << endl;
    if (gioco_terminato && vittoria)
        cout << "Hai vinto!" << endl;
}


void disegnaConfigurazione(){
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
   postoSx = '_';
   postoDx = '_';
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


void interazioneUtente(){
   /*
  Vengono  3 domande all'utente :
 - che tipo di elemento vuoi muovere?
   + l'utente ha tre opzioni: (b / c / m)
     b per barca
     c per cannibale
     m per missionario
 - che azione vuoi fargli compiere?
   + l'utente ha tre opzioni: (g / s / n)
     g per smonta gi� dalla barca
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
        cout << "Inserisci valori corretti!!! (d;s;b)";
        }
        cout << "Da dove vuoi muovere il missionario?"<< endl;
        cout << "Premi il tasto corrispondenete a seconda della sua posizione: "<< endl;
        cout << "d = sulla sponda destra" << endl << "s = sulla sponda sinistra" << endl<< "b = sulla barca"<< endl;
        cin >> posizione;
        errore_inserimento=(posizione!= 'd' && posizione != 's' && posizione!= 'b');
        }  while (errore_inserimento);
        system ("CLS");
        do {
        if (errore_inserimento){
        cout << "Inserisci valori corretti!!! (d;s;b)";
        }
        cout << "Dove vuoi far andare il missionario?" << endl;
        cout << "d = sulla sponda destra" << endl << "s = sulla sponda sinistra" << endl << "b = sulla barca"<< endl;
        cin >> direzione;
        errore_inserimento=(direzione!='d'&& direzione!= 's' && direzione != 'b');
        } while (errore_inserimento);
        break;

        case ('c'):
        do {
        if (errore_inserimento){
        cout << "Inserisci valori corretti!!! (d;s;b)";
        }
        cout << "Da dove vuoi muovere il cannibale?"<< endl;
        cout << "Premi il tasto corrispondenete a seconda della sua posizione: "<< endl;
        cout << "d = sulla sponda destra" << endl << "s = sulla sponda sinistra" << endl<< "b = sulla barca"<< endl;
        cin >> posizione;
        errore_inserimento=(posizione!= 'd' && posizione != 's' && posizione != 'b');
        }while (errore_inserimento);
        system("CLS");
        do {
        if (errore_inserimento){
        cout << "Inserisci valori corretti!!! (d;s;b)";
        }
        cout << "Dove vuoi far andare il cannibale?" << endl;
        cout << "d = sulla sponda destra" << endl << "s = sulla sponda sinistra" << endl << "b = sulla barca"<< endl;
        cin >> direzione;
        errore_inserimento=(direzione!='d'&& direzione!= 's' && direzione != 'b');
        } while (errore_inserimento);
        break;

        case ('b'):
         break;
        }

    }







void eseguiAzione(){

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
void muoviMissionario() {
           // MESSAGGI D'ERRORE
    if (posizione == 'd' && direzione == 's' && missionari_dx >0 || posizione== 's' && direzione=='d'
        && missionari_sx>0){
       cout << "NON puoi portare un missionario da una sponda all'altra senza usare la barca!!"<< endl;
        system ("pause");
    }
    if (posizione=='d' && direzione == 'b' && missionariBarca + cannibaliBarca==2 && lato_barca=='d' ||
        posizione=='s' && direzione == 'b' && missionariBarca + cannibaliBarca==2 && lato_barca=='s'){
        cout << "La barca e' piena!! Non ci sta piu' nessuno!!" << endl;
        system ("pause");
    }
    if (posizione=='b' && direzione == 'd' && missionariBarca+ cannibaliBarca==0 ||
        posizione=='b' && direzione == 's' && missionariBarca+ cannibaliBarca==0){
        cout << "Non c'e' nessuno da spostare nella barca!!"<< endl;
        system ("pause");
    }
    if (posizione=='b' && direzione == 'd' && lato_barca=='s' ||
        posizione=='b' && direzione == 's' && lato_barca=='d'){
        cout << "NON puoi spostare missionari sulla riva opposta!! Muovi la barca" << endl;
        system ("pause");
    }
    if (posizione=='d' && direzione == 'b' && lato_barca=='s' && missionari_dx !=0 ||
        posizione=='s' && direzione == 'b' && lato_barca=='d' && missionari_sx !=0){
        cout << "NON puoi spostare missionari sulla barca situata sulla riva opposta!!" << endl;
        cout << "Muovi la barca !!"<< endl;
        system ("pause");
    }
    if (posizione=='d' && direzione == 'b' && missionari_dx==0 ||
        posizione=='s' && direzione == 'b' && missionari_sx==0){
        cout << "NON c'e' nessun missionario da spostare!!" << endl;
        system ("pause");
    }
  if (posizione == 's' && direzione == 'b' && missionari_sx > 0
        && lato_barca == 's'
        && missionariBarca + cannibaliBarca < 2){
        missionariBarca++;
        missionari_sx--;
    }
    if (posizione == 'd' && direzione == 'b' && missionari_dx > 0
        && lato_barca == 'd'
        && missionariBarca + cannibaliBarca < 2){
        missionariBarca++;
        missionari_dx--;
    }
    if (posizione == 'b' && direzione == 's' && missionariBarca > 0
        && lato_barca == 's'){
        missionariBarca--;
        missionari_sx++;
    }
    if (posizione == 'b' && direzione == 'd' && missionariBarca > 0
        && lato_barca == 'd'){
        missionariBarca--;
        missionari_dx++;}

}
void muoviCannibale (){
 // MESSAGGI D'ERRORE
    if (posizione == 'd' && direzione == 's' && cannibali_dx >0 || posizione== 's' && direzione=='d'
        && cannibali_sx>0){
       cout << "NON puoi portare un missionario da una sponda all'altra senza usare la barca!!"<< endl;
        system ("PAUSE");
    }
    if (posizione=='d' && direzione == 'b' && missionariBarca+ cannibaliBarca==2 && lato_barca=='d'||
        posizione=='s' && direzione == 'b' && missionariBarca+ cannibaliBarca==2 && lato_barca=='s'){
        cout << "La barca e' piena!! Non ci sta piu' nessuno!!" << endl;
        system ("PAUSE");
    }
    if (posizione=='b' && direzione == 'd' && missionariBarca + cannibaliBarca==0 ||
        posizione=='b' && direzione == 's' && missionariBarca + cannibaliBarca==0){
        cout << "Non c'e' nessuno da spostare nella barca!!"<< endl;
        system ("PAUSE");
    }
    if (posizione=='b' && direzione == 'd' && lato_barca=='s' ||
        posizione=='b' && direzione == 's' && lato_barca=='d'){
        cout << "NON puoi spostare cannibali sulla riva opposta!! Muovi la barca" << endl;
        system ("PAUSE");
    }
    if (posizione=='d' && direzione == 'b' && lato_barca=='s' && cannibali_dx !=0||
        posizione=='s' && direzione == 'b' && lato_barca=='d' && cannibali_sx !=0){
        cout << "NON puoi spostare cannibali sulla barca situata sulla riva opposta!!" << endl;
        cout << "Muovi la barca !!"<< endl;
        system ("PAUSE");
    }
    if (posizione=='d' && direzione == 'b' && cannibali_dx==0 ||
        posizione=='s' && direzione == 'b' && cannibali_sx==0){
        cout << "NON c'e' nessun cannibale da spostare!!" << endl;
        system ("PAUSE");
    }
if (posizione == 's' && direzione == 'b' && cannibali_sx > 0
        && lato_barca == 's'
        && missionariBarca + cannibaliBarca < 2){
        cannibaliBarca++;
        cannibali_sx--;
    }
    if (posizione == 'd' && direzione == 'b' && cannibali_dx > 0
        && lato_barca == 'd'
        && missionariBarca + cannibaliBarca < 2){
        cannibaliBarca++;
        cannibali_dx--;
    }
    if (posizione == 'b' && direzione == 's' && cannibaliBarca > 0
        && lato_barca == 's'){
        cannibaliBarca--;
        cannibali_sx++;
    }
    if (posizione == 'b' && direzione == 'd' && cannibaliBarca > 0
        && lato_barca == 'd'){
        cannibaliBarca--;
        cannibali_dx++;
    }


}
void muoviBarca (){
 if ((missionariBarca+cannibaliBarca) == 0){
        cout << "La barca non si puo' muovere se non contiene nessun personaggio." << endl;
        system ("PAUSE");
    }else{
        if (lato_barca == 'd')
            lato_barca = 's';
        else // lato_barca == 's'
            lato_barca = 'd';
    }
}
