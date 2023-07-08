// Struttura ambulatorio con una lista di prenotazione
// prenotazione; id paziende, id dottore, tuno di preferenza, lista di medici (id, reparto, lista di turni=(id e giorni settimana))

// lista esuberi serbatioiperche turni gia tutti occupati


// Creare una lista vuoita di appuntamenti e poi riemirla
// data poi una lista di appuntamenti bisogna restituire la lista dei medici (da popolare in base agli apputnaemnti)

// appuntamenti oridnati per qualcosa e se un appuntametno non entrava in un turno di un medico
// doveva finire nella lista di esubero


// eliminazio ... e altre cose


typedef struct Prenotazioni
{
    int idPaziente;
    int idDottore;
    int orario;
    Medico medici[];
    struct listaProntazione * next;
} listaPrenotazione;

typedef struct Medico {
    int idMedico;
    char reparto;
    int orario
} Medico;


// Serve per creare la nuova lista 
listaPrenotazione *creaLista(int idPaziente, int idDottore, int orario ,Medico medici){
    // Alloca dinamicamente la variabile puntatore listaPokemon *nuovaListaPokemon
    listaPrenotazione *nuovaListaPrenotazione = (listaPrenotazione*)malloc(sizeof(listaPrenotazione));
    // Assegnazione parametri
    strcpy(nuovaListaPrenotazione->idPaziente, idPaziente);
    strcpy(nuovaListaPrenotazione->idDottore, idDottore);
    memcpy(nuovaListaPrenotazione->medici, medici, sizeof(Medico));
    nuovaListaPrenotazione->next = NULL;

    return nuovaListaPrenotazione;
}


void popolaLista(listaPrenotazione **head, char nomeCognome[maxNomeCognome], char idCliente[maxIdCliente], char dataOrdine, Piatto piatti[15]) {
    // Si crea la lista da aggiungere in head
    listaPrenotazione *nuovaListaPrenotazioni = creaLista(nomeCognome,idCliente,dataOrdine,piatti);
    nuovaListaPrenotazioni->next = *head;
    *head = nuovaListaPrenotazioni;
}