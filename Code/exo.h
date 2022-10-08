typedef struct {
	char Nom[20];
	char Prenom[20];
	char Logement[5];
}Loge ;
typedef struct {
	char nbPers[10];
	char point[10];
}Demande ;

typedef struct Maillon Maillon;

struct Maillon{
	int contenu;
	int point;
	Maillon *suivant;
};

typedef struct File{
	Maillon *tete;
	Maillon *queue;
	int taille;
}File;

int global(void);
void OuvLogement(void);
void Choix(void);
void TypeLogement(int type);
void SupLogement(void);
void AjLogement(void);
void Locat(void);
Loge * lireLogement(FILE *f);
int chargeFLogement(char * nomFich,Loge * tLoge[],int taillemax);
int triAlphabet(Loge **tLoge,int taille);
int triLogement(Loge **tLoge,int taille);
void affichLogement(Loge **tLoge,int nbLoge);
void DemandeLog(void);
void AffDemande(void);
void GesDemande(void);
void affichDemandeRec(Demande **tDem,int nbDem);
File creerVide();
int enfiler(File *f,int v,int point,int tailleMax);
void affichageLoge(int *fin[100][30]);
int defiler(File *f);
void affich(File fi);
void traitDem(Demande **tDem,int nbDem,int *fin[100][30]);