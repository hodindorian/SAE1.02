#include <stdio.h>
#include "exo.h"
#include <stdlib.h>
#include <string.h>

int global(void){
	int choix=1;
	char term;
	while (choix!=0){  
		printf("\n");
		printf("\033[1;35m    ██████  ██ ███████ ███    ██ ██    ██ ███████ ███    ██ ██    ██ ███████         ███████ ██    ██ ██████          ██   ██ ██      ███    ███  ██████  ██████  \033[0m\n");
		printf("\033[1;35m    ██   ██ ██ ██      ████   ██ ██    ██ ██      ████   ██ ██    ██ ██              ██      ██    ██ ██   ██         ██   ██ ██      ████  ████ ██            ██ \033[0m\n");
		printf("\033[1;35m    ██████  ██ █████   ██ ██  ██ ██    ██ █████   ██ ██  ██ ██    ██ █████           ███████ ██    ██ ██████          ███████ ██      ██ ████ ██ ███████   █████  \033[0m\n");
		printf("\033[1;35m    ██   ██ ██ ██      ██  ██ ██  ██  ██  ██      ██  ██ ██ ██    ██ ██                   ██ ██    ██ ██   ██         ██   ██ ██      ██  ██  ██ ██    ██      ██ \033[0m\n");
		printf("\033[1;35m    ██████  ██ ███████ ██   ████   ████   ███████ ██   ████  ██████  ███████         ███████  ██████  ██   ██         ██   ██ ███████ ██      ██  ██████  ██████  \033[0m\n");
		printf("\n\n\033[1;32mQue souhaitez-vous faire?\033[0m");                                                                                                                                                    
       	printf("\n\n\033[1;36m1- Ajout d'un logement\n\n2- Supprime d'un logement\n\n3- Affiche les logements\n\n4- Affiche/Recherche les locataires\n\n5- Enregistrer une demande\n\n6- Afficher toute les demandes\n\n7- Traiter les demandes en attente\n\n0- Sortir\033[0m\n\n");
		if (scanf("%d%c",&choix,&term)!=2 || term!= '\n'){
			printf("\033[1;31mVeuillez bien tapez l'une des possibilités proposées ci-dessus.\033[0m\n");
			exit(1);
		}
		if (choix>7){
			printf("\033[1;31mVeuillez bien tapez l'une des possibilités proposées ci-dessus.\033[0m\n");
			exit(1);
		}else if (choix==1){
			AjLogement();
		}else if (choix==2){
			SupLogement();
		}else if (choix==3){
			Choix();
		}else if (choix==4){
			Locat();
		}else if (choix==5){
			DemandeLog();
		}else if (choix==6){
			AffDemande();
		}else if (choix==7){
			GesDemande();
		}
		system("clear");
	}
	return 0;
}



void Choix(void){
	int choix;
	char term;
	printf("\n\033[1;32mSouhaitez vous voir tous les logements ou seulement ceux d'un nombre de personnes en particulier?\033[0m\n\n");
	while (choix!=0){
		printf("\n\033[1;33m|----------------------------------------------------------------|\033[0m\n");
		printf("\033[1;33m|Tapez 1 pour voir tous les logements.                           |\033[0m\n");
		printf("\033[1;33m|Tapez 2 pour voir ceux d'un nombre de personnes en particulier. |\033[0m\n");
		printf("\033[1;33m|Tapez 0 pour quitter.                                           |\033[0m\n");
		printf("\033[1;33m|----------------------------------------------------------------|\033[0m\n");
		if (scanf("%d%c",&choix,&term)!=2 || term!= '\n'){
			printf("\033[1;31mVeuillez bien tapez l'une des possibilités proposées ci-dessus.\033[0m\n");
			break;
		}
		if (choix==1){
			OuvLogement();
		}
		if (choix==2){
			printf("\033[1;32mDe combien de personnes le logement recherché doit être composé ? \033[0m\n");
	 		if (scanf("%d%c",&choix,&term)!=2 || term!= '\n'){
				printf("\033[1;31mVeuillez bien tapez l'une des possibilités proposées ci-dessus.\033[0m\n");
				break;
			}
	 		TypeLogement(choix);
		}
	}
}
void OuvLogement(void){
	FILE *f;
	int numero,nbrper;
	f=fopen("Logement.don","r");
	if (f==NULL) exit(1);
	while (feof(f)==0){
		fscanf(f,"%d %d\n",&numero,&nbrper);
		printf("Logement numero %d de %d personnes.\n",numero,nbrper);
	}
	fclose(f);
}
void TypeLogement(int type){
	FILE *f;
	int numero,nbrper,resultat=0;
	f=fopen("Logement.don","r");
	if (f==NULL) exit(1);
	while (feof(f)==0){
		fscanf(f,"%d %d\n",&numero,&nbrper);
		if (nbrper==type){
			printf("Logement numero %d de %d personnes.\n",numero,nbrper);
			resultat=1;
		}
	}
	if(resultat==0){
		printf("\033[1;31mAucun logement disponible!\033[0m\n\n");
	}
	fclose(f);
}
void AjLogement(void){
	FILE *f;
	int type,k=0,non=0;
	char trash[100][30],choix[1][30],term;
	printf("\n\033[1;33mRenseignez le numero du logement : \033[0m");
	scanf("%s",choix[1]);
	f=fopen("Logement.don","r");
	if (f==NULL) exit(1);
	while (feof(f)==0){
		fscanf(f,"%s %s",trash[k],trash[k+1]);
		if (strcmp(trash[k],choix[1])==0){
			printf("\033[1;31mCe numéro de logement existe déjà!\033[0m\n\n");
			non=1;
			fclose(f);
			break;
		}
	}
	if (non==0){
		printf("\n\033[1;33mRenseignez le nombre de personnes pouvant vivre dans ce logement : \033[0m");
		if (scanf("%d%c",&type,&term)!=2 || term!= '\n'){
			printf("\033[1;31mVeuillez bien tapez l'une des possibilités proposées ci-dessus.\033[0m\n");
			exit(1);
		}
		f=fopen("Logement.don","a");
		fprintf(f,"\n%s %d",choix[1],type);
		fclose(f);
	}
}
void SupLogement(void){
	int oui,i=0,j,k=0,non=0;
	char sup[100][40],choix[1][30],numero[100][30],term;
	printf("\033[1;33mRenseignez le numero du logement à supprimer : \033[0m");
	scanf("%s",choix[1]);
	FILE *f;
	f=fopen("Logement.don","r+");
	if (f==NULL) exit(1);
	while (feof(f)==0){
		fscanf(f,"%s %s",numero[k],numero[k+1]);
		if (strcmp(numero[k],choix[1])==0){
			printf("\nVous allez supprimer le logement numero %s de %s personnes, est-ce bien ça? [0 pour OUI/1 pour NON] \n",numero[k],numero[k+1]);
			if (scanf("%d%c",&oui,&term)!=2 || term!= '\n'){
				printf("\033[1;31mVeuillez bien tapez l'une des possibilités proposées ci-dessus.\033[0m\n");
				break;
				}
			if (oui!=0 || oui!=1){
				printf("\033[1;31mVeuillez bien tapez l'une des possibilités proposées ci-dessus.\033[0m\n");
				break;
			}	
			if (oui==0){
				fclose(f);
				f=fopen("Logement.don","r");
				while (feof(f)==0){
					fscanf(f,"%s %s",sup[i],sup[i+1]);
					i=i+2;
				}
				for (j=1;j<i;j=j+2){
					if (strcmp(choix[1],sup[j-1])==0){
						strcpy(sup[j-1],"\0");
						strcpy(sup[j],"\0");
					}
				}
				fclose(f);
				f=fopen("Logement.don","w");
				for (j=0;j<i;j=j+2){
					fprintf(f,"\n%s %s",sup[j],sup[j+1]);
				}
				fclose(f);
				printf("\033[1;32mSuppression confirmée !\033[0m\n");
				non=1;
        		break;
   			}else if (oui==1){
				printf("\033[1;31mAnnulation de la suppression\033[0m\n");
				non=1;
				break;
			}else if (oui!=1 && oui!=0){
				printf("\033[1;31mVeuillez tapez soit O(Oui) soit N(Non) pour confirmer votre choix.\033[0m");
				non=1;
				break;
			}
		}
		k=k+2;	
	}
	if (non==0){
		printf("\n\033[1;31mLe numéro de logement entré n'est pas présent dans la base de données de HLM63, veuillez réessayez.\033[0m\n");
	}
}


void Locat(void){
	int choix=1,i=0,taille=100,non=0;
	char nom[100][30],num[1][30],name[1][30],term;
	Loge * tab[taille];
	while (choix!=0){
		printf("\n\033[1;32mQuel affichage souhaitez-vous?\033[0m\n\n");
		printf("\033[1;33m|----------------------------------------------------------------------------------|\033[0m\n");
		printf("\033[1;33m|Tapez 1 pour voir tous les locataires triés par ordre alphabétique de leurs noms. |\033[0m\n");
		printf("\033[1;33m|Tapez 2 pour voir tous les locataires triés en fonction de leur logements.        |\033[0m\n");
		printf("\033[1;33m|Tapez 3 pour voir les locataires d'un certain numéro de logement.                 |\033[0m\n");
		printf("\033[1;33m|Tapez 4 pour voir un locataire en focntion de son nom.                            |\033[0m\n");
		printf("\033[1;33m|Tapez 0 pour sortir de ce menu                                                    |\033[0m\n");
		printf("\033[1;33m|----------------------------------------------------------------------------------|\033[0m\n");
		if (scanf("%d%c",&oui,&term)!=2 || term!= '\n'){
				printf("\033[1;31mVeuillez bien tapez l'une des possibilités proposées ci-dessus.\033[0m\n");
				break;
		}
		FILE *f;
		f=fopen("Locataire.don","r");
		if (f==NULL) exit(1);
		if (choix==1){
			i=chargeFLogement("Locataire.don",tab,taille);
			triAlphabet(tab,i);
			affichLogement(tab,i);
		}
		if (choix==2){
			i=chargeFLogement("Locataire.don",tab,taille);
			triLogement(tab,i);
			affichLogement(tab,i);
		}
		if (choix==3){
			non=0;
			printf("\033[1;32mQuel est le numéro de logement où vous souhaitez rechercher les locataires ? \033[0m");
			scanf("%s",num[1]);
			while (feof(f)==0){
				fscanf(f,"%s %s %s",nom[i],nom[i+1],nom[i+2]);
				if (strcmp(num[1],nom[i+2])==0){
					printf("\n%s %s habite dans le logement numéro %s\n",nom[i+1],nom[i],nom[i+2]);
					non=1;
				}
				i=i+3;
			}
			if (non==0){
				printf("\n\033[1;31mIl n'y a pas ce numéro de logement chez HLM63.\033[0m\n");
			}
		}
		if (choix==4){
			non=0;
			printf("\n\033[1;32mQuel est le nom du locataire recherché ? \033[0m");
			scanf("%s",name[1]);
			while (feof(f)==0){
				fscanf(f,"%s %s %s",nom[i],nom[i+1],nom[i+2]);
				if (strcmp(name[1],nom[i])==0){
					printf("\n%s %s habite dans le logement numéro %s\n",nom[i+1],nom[i],nom[i+2]);
					non=1;
				}
				i=i+3;	
			}
			if (non==0){
				printf("\n\033[1;31mIl n'y a pas de locataires à ce nom chez HLM63.\033[0m\n");
			}
		}
		if (choix>4){
			printf("\n\033[1;31mVeuillez bien tapez l'une des possibilités proposées ci-dessus.\033[0m\n");
			exit(1);
		}
		if (choix==0){
			break;
		}
	}
}

Loge * lireLogement(FILE *f){
	Loge *l=(Loge*)malloc(sizeof(Loge));
	fscanf(f,"%s %s %s\n",l->Prenom,l->Nom,l->Logement);
	return l;
}

int chargeFLogement(char * nomFich,Loge * tLoge[],int taillemax){
	FILE *f;
	int i=0;
	f=fopen(nomFich,"r");
	if (f==NULL) return -1;
	while (feof(f)==0){
		tLoge[i]=lireLogement(f);
		i++;
	}
	fclose(f);
	return i;
}

int triAlphabet(Loge **tLoge,int taille){
	char min[25];
	int pos;
	Loge *l;
	for(int i=0;i<taille;i++){
		strcpy(min,"ZZZZZZZ");
		for(int l=i;l<taille;l++){
			if(strcmp(tLoge[l]->Prenom,min)<0){
				strcpy(min,tLoge[l]->Prenom);
				pos=l;
			}
		}
		l=tLoge[pos];
		tLoge[pos]=tLoge[i];
		tLoge[i]=l;
	}
	return 0;
}
int triLogement(Loge **tLoge,int taille){
	char min[25];
	int pos;
	Loge *l;
	for(int i=0;i<taille;i++){
		strcpy(min,"ZZZZZZZ");
		for(int l=i;l<taille;l++){
			if(strcmp(tLoge[l]->Logement,min)<0){
				strcpy(min,tLoge[l]->Logement);
				pos=l;
			}
		}
		l=tLoge[pos];
		tLoge[pos]=tLoge[i];
		tLoge[i]=l;
	}
	return 0;
}

void affichLogement(Loge **tLoge,int nbLoge){
	for (int i=0;i<nbLoge;i++){
		printf("\n%s %s habite dans le logement %s.\n",tLoge[i]->Prenom,tLoge[i]->Nom,tLoge[i]->Logement);
	}
}
Demande * lireDemande(FILE *f){
	Demande *d=(Demande*)malloc(sizeof(Demande));
	fscanf(f,"%s %s \n",d->nbPers,d->point);
	return d;
}

int chargeFDemande(char * nomFich,Demande * tDem[],int taillemax){
	FILE *f;
	int i=0;
	f=fopen(nomFich,"r");
	if (f==NULL) return -1;
	while (feof(f)==0){
		tDem[i]=lireDemande(f);
		i++;
	}
	fclose(f);
	return i;
}
int triDemande(Demande **tDem,int taille){
	char min[25];
	int pos;
	Demande *d;
	for(int i=0;i<taille;i++){
		strcpy(min,"ZZZZZZZ");
		for(int d=i;d<taille;d++){
			if(strcmp(tDem[d]->point,min)<0){
				strcpy(min,tDem[d]->point);
				pos=d;
			}
		}
		d=tDem[pos];
		tDem[pos]=tDem[i];
		tDem[i]=d;
	}
	return 0;
}
void affichDemande(Demande **tDem,int nbDem){
	for (int i=nbDem-1;i>=0;i--){
		printf("\nDemande d'un logement pour %s personnes avec %s points.\n",tDem[i]->nbPers,tDem[i]->point);
	}
}
void DemandeLog(void){
	int point=0,capture,logement;
	char term;
	FILE *f;
	printf("\n\033[1;32mPour combien de personnes souhaitez-vous faire une demande de logement ?\033[0m\n");
	scanf("%d",&logement);
	if (logement<1){
		printf("\033[1;31mVeuillez tapez un nombre entier superieur à 0!\033[0m");
		exit(1);
	}
	printf("\n\033[1;33mPour répondre au question, mettez 0 pour oui et 1 pour non.\033[0m\n");
	if (logement==1){
		printf("\n\033[1;32mEtes-vous en situation de handicap ?\033[0m\n");
		scanf("%d",&capture);
		if(capture==0){
			point=point+30;
		}
		printf("\n\033[1;32mAvez vous etez victime de violence au sein de votre couple ?\033[0m\n");
		scanf("%d",&capture);
		if(capture==0){
			point=point+15;
		}
		printf("\n\033[1;32mEtes-vous hébergé ou logé temporairement ?\033[0m\n");
		scanf("%d",&capture);
		if(capture==0){
			point=point+15;
		}
		printf("\033[1;32mEtes-vous menacé d'explusion ?\033[0m\n");
		scanf("%d",&capture);
		if(capture==0){
			point=point+10;
		}
		printf("\033[1;32mEtes-vous actuellement logé dans un logement insalubre ?\033[0m\n");
		scanf("%d",&capture);
		if(capture==0){
			point=point+8;
		}
	}else if (logement>1){
		printf("\n\033[1;32mEst-ce que l'une des personnes pour qui vous faites la demande ou vous même est en situation de handicap ?\033[0m\n");
		scanf("%d",&capture);
		if(capture==0){
			point=point+30;
		}
		printf("\n\033[1;32mEst-ce que l'une des personnes pour qui vous faites la demande ou vous même est victime de violence au sein de votre couple ?\033[0m\n");
		scanf("%d",&capture);
		if(capture==0){
			point=point+15;
		}
		printf("\n\033[1;32mEst-ce que l'une des personnes pour qui vous faites la demande ou vous même êtes hébergées ou logées temporairement ?\033[0m\n");
		scanf("%d",&capture);
		if(capture==0){
			point=point+15;
		}
		printf("\033[1;32mEst-ce que l'une des personnes pour qui vous faites la demande ou vous même êtes menacées d'explusion ?\033[0m\n");
		scanf("%d",&capture);
		if(capture==0){
			point=point+10;
		}
		printf("\033[1;32mEst-ce que l'une des personnes pour qui vous faites la demande ou vous même êtes logées dans un logement insalubre ?\033[0m\n");
		scanf("%d",&capture);
		if(capture==0){
			point=point+8;
		}
	}
	f=fopen("Demande.don","a");
	fprintf(f,"%d %d\n",logement,point);
	fclose(f);	
}

void affichDemandeRec(Demande **tDem,int nbDem){
	if (nbDem==0){
		printf("\nDemande d'un logement pour %s personnes avec %s points\n",tDem[nbDem]->nbPers,tDem[nbDem]->point);
		return;
	}else{
		printf("\nDemande d'un logement pour %s personnes avec %s points\n",tDem[nbDem]->nbPers,tDem[nbDem]->point);
		affichDemandeRec(tDem,nbDem-1);
	}
}

void AffDemande(void){
	int taille=100,i,choix=1;
	Demande * tDem[taille];
	printf("\n\033[1;32mQuel affichage souhaitez-vous?\033[0m\n");
	while (choix!=0){	
		printf("\n\033[1;33m|---------------------------------------------------------------------|\033[0m\n");
		printf("\033[1;33m|Tapez 1 pour voir toutes les demandes triés par les plus récentes.   |\033[0m\n");
		printf("\033[1;33m|Tapez 2 pour voir toutes les demandes triés par le nombre de point.  |\033[0m\n");
		printf("\033[1;33m|Tapez 0 pour sortir de ce menu                                       |\033[0m\n");
		printf("\033[1;33m|---------------------------------------------------------------------|\033[0m\n");
		scanf("%d",&choix);
		if (choix==1){
			i=chargeFDemande("Demande.don",tDem,taille);
			affichDemandeRec(tDem,i-1);
		}
		if (choix==2){
			i=chargeFDemande("Demande.don",tDem,taille);
			triDemande(tDem,i);
			affichDemande(tDem,i);
		}
		
	}
}
void affichageLoge(int *fin[100][30]){
	FILE *f;
	char tab[100][30];
	int i=0,cont=0,k,j,fi=0,numero,placeFinal[100][30],placeLog[100][30],fini[100][30],m=0,lon,dernier[100][30];
	f=fopen("Logement.don","r");
	if (f==NULL) exit(1);
	while (feof(f)==0){
		fscanf(f,"%d %s\n",&numero,tab[cont]);
		cont++;
	}
	fclose(f);
	f=fopen("Locataire.don","r");
	if (f==NULL) exit(1);
	while (feof(f)==0){
		fscanf(f,"%s %s %d",tab[i],tab[i],placeLog[i]);
		i++;	
	}

	fclose(f);
	for (k=0;k<=cont;k++){
		for (j=0;j<=i;j++){
			if (k==*placeLog[j]){
				*placeFinal[k]=*placeFinal[k]+1;
			}
		}
	}

	f=fopen("Logement.don","r");
	if (f==NULL) exit(1);
	while (feof(f)==0){
		fscanf(f,"%d %d\n",dernier[m],fini[m]);
		m++;
	}
	fclose(f);
	for (k=0;k<m;k++){
		lon=*fini[k]-(*placeFinal[k+1]);
		if (lon==0){
			printf("\nIl n'y a plus de places dans le logement numéro %d.\n",*dernier[k]);
		}else if (lon>0){
			printf("\nIl reste %d place(s) dans le logement numéro %d.\n",lon,*dernier[k]);
		}
		*fin[fi]=dernier[k];
		*fin[fi+1]=&lon;
		fi=fi+2;
	}
}

	
void traitDem(Demande **tDem,int nbDem,int *fin[100][30]){
	int choix,value,i,j,k=0;
	FILE *f;
	char nom[1][30],prenom[1][30],numero[100][30];
	f=fopen("Locataire.don","a");
	if (f==NULL) exit(1);
	printf("\n\033[1;32mDemande pour %s personnes avec un total de %s point(s). Voici les places disponibles : \033[0m\n\n",tDem[nbDem]->nbPers,tDem[nbDem]->point);
	affichageLoge(fin);
	printf("\n\033[1;32mAcceptez-vous la demande de logement (0 pour Oui 1 pour Non) ? \033[0m");
	scanf("%d",&choix);
	if (choix==0){
		printf("\n\033[1;33mDans quel logement souhaitez-vous loger cette demande ? \033[0m");
		scanf("%d",&choix);
		value=atoi(tDem[nbDem]->nbPers);
		if ((fin[choix]-value)<0){
			printf("\n\033[1;31mIl n'y a pas assez de place dans ce logement.\n\033[0m");
		}else{
			for (i=1;i<=value;i++){
				printf("\033[1;33mDonnez le nom de la personne numéro %d : \033[0m",i);
				scanf("%s",nom[1]);
				printf("\033[1;33mDonnez le prénom de la personne numéro %d : \033[0m",i);
				scanf("%s",prenom[1]);
				printf("%s %s %d\n",nom[1],prenom[1],choix);
				fprintf(f,"%s %s %d\n",nom[1],prenom[1],choix);
				fclose(f);

				f=fopen("Demande.don","r+");
				if (f==NULL) exit(1);
				while (feof(f)==0){
					fscanf(f,"%s %s",numero[k],numero[k+1]);
					k=k+2;
				}
				strcpy(numero[0],"\0");
				strcpy(numero[1],"\0");
				fclose(f);
				f=fopen("Demande.don","w");
				for (j=0;j<k;j=j+2){
					fprintf(f,"\n%s %s",numero[j],numero[j+1]);
				}
				fclose(f);
			}
		}
	}
}



void GesDemande(void){
	int choix=1;
	int *tab[100][30],taille=100,i;
	Demande * tDem[taille];
	printf("\n\033[1;32mQuel affichage souhaitez-vous?\033[0m\n");
	while (choix!=0){
		printf("\n\033[1;33m|----------------------------------------------------------------------------------|\033[0m\n");
		printf("\033[1;33m|Tapez 1 pour afficher les places disponibles.                                     |\033[0m\n");
		printf("\033[1;33m|Tapez 2 pour traiter les demandes.                                                |\033[0m\n");
		printf("\033[1;33m|Tapez 0 pour sortir de ce menu.                                                   |\033[0m\n");
		printf("\033[1;33m|----------------------------------------------------------------------------------|\033[0m\n");
		scanf("%d",&choix);
		if (choix==1){
			affichageLoge(tab);
			printf("\n");
		}
		if (choix==2){
			i=chargeFDemande("Demande.don",tDem,taille);
			triDemande(tDem,i);
			traitDem(tDem,i-1,tab);
		}
		if (choix==0){
			break;
		}
	}
}

File creerVide(void){
 	File fi;
 	fi.tete=NULL;
 	fi.queue=NULL;
 	fi.taille=0;
 	return fi;
}
void affich(File fi){
 	if (fi.tete==NULL && fi.queue==NULL && fi.taille==0){
 		perror("File Vide");
 		exit(1);
 	}else{
 		printf("%d %d %d\n", fi.tete->contenu,fi.queue->contenu,fi.taille);
 	}
}

int enfiler(File *f,int v,int point,int tailleMax){
 	Maillon new;
 	if (f->taille==tailleMax)return -1;
 	new.suivant=NULL;
 	new.contenu=v;
 	new.point=point;
 	f->queue=&new;
 	if (f->tete==NULL){
 		f->tete=&new;
 	}else{
 	 	f->queue->suivant=&new;
 	}
 	f->taille++;
 	return f->taille;
}


int defiler(File *f){
 	int val=f->tete->point;
 	f->tete=f->tete->suivant;
 	f->taille--;
 	return val;
}
