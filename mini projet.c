#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicament
{
	int refm;
	char nom[30];
	float prix_achat;
	float prix_vent;
	int contite_at_stock;
	char categorie[30];	
};

struct commande
{
	int refm;
	int numC;
	int date;
	char gtcmd[20];
};



void remplissage(struct medicament t[])
	{
		int i ;
		printf("entrer le reference \n");
		scanf("%d",&t[0].refm);
		printf("entrer le nom \n");
		scanf("%s",&t[0].nom);
		printf("entrer prix d'achat \n");
		scanf("%f",&t[0].prix_achat);
		printf("entrer prix de vente \n");
		scanf("%f",&t[0].prix_vent);
		printf("entrer la contite en stock \n");
		scanf("%d",&t[0].contite_at_stock);
		printf("entrer la categorie \n");
		scanf("%s",&t[0].categorie);
		
		printf("entrer le 2eme reference \n");
		scanf("%d",&t[1].refm);
		while(t[1].refm==t[0].refm)
		{
			printf("le reference deja exist \n");
			
			printf("entrer le 2eme reference \n");
			scanf("%d",&t[1].refm);
		}
		if(t[1].refm!=t[0].refm)
		{
		printf("entrer le nom \n");
		scanf("%s",&t[1].nom);
		printf("entrer prix d'achat \n");
		scanf("%f",&t[1].prix_achat);
		printf("entrer prix de vente \n");
		scanf("%f",&t[1].prix_vent);
		printf("entrer la contite en stock \n");
		scanf("%d",&t[1].contite_at_stock);
		printf("entrer la categorie \n");
		scanf("%s",&t[1].categorie);
		}
	}


void ajouter(struct medicament t[],int n,struct medicament m) 
	{
		int i ;
		
			printf("entrer le reference \n");
			scanf("%d",&m.refm);
			for(i=0;i<n;i++)
			{
				while(t[i].refm==m.refm)
				{
					printf("le reference deja exist \n");
					
					printf("entrer le reference \n");
					scanf("%d",&m.refm);
				}
			}	
		
			printf("entrer le nom \n");
			scanf("%s",&m.nom);
			printf("entrer prix d'achat \n");
			scanf("%f",&m.prix_achat);
			printf("entrer prix de vente \n");
			scanf("%f",&m.prix_vent);
			printf("entrer la contite en stock \n");
			scanf("%d",&m.contite_at_stock);
			printf("entrer la categorie \n");
			scanf("%s",&m.categorie);	
				
			t[n]=m;
	}
	

void affichage(struct medicament t[],int n)
	{
		int i ;
		for(i=0;i<n;i++)
		{
			printf("pour le %d medicament \n",i+1);
			printf("%d \t\t",t[i].refm);
			printf("%s \t\t",t[i].nom);
			printf("%.2f \t\t",t[i].prix_achat);
			printf("%.2f \t\t",t[i].prix_vent);
			printf("%d \t\t",t[i].contite_at_stock);
			printf("%s \t\t",t[i].categorie);
			printf("\n");
		}
		printf("\n");
	}
	
int recherche(struct medicament t[],int n,int x)
	{
		int po=-1;
		int i;
		for(i=0;i<n;i++)
		{
			if(t[i].refm==x)
			{
				po=i;
				printf("la position de medicament est %d \n",po);
				printf("les information \n");
				printf("%d \t\t",t[i].refm);
				printf("%s \t\t",t[i].nom);
				printf("%.2f \t\t",t[i].prix_achat);
				printf("%.2f \t\t",t[i].prix_vent);
				printf("%d \t\t",t[i].contite_at_stock);
				printf("%s \t\t",t[i].categorie);
				printf("\n");
			}
		}
		return po;
	}

void supprimer(struct medicament t[],int n ,int x)
	{
		int i;
		int pos=recherche(t,n,x);
		if(pos==-1)
		{
			printf("%d n'existe pas \n",x);
		}
		else
		{
			printf("le nouveau tableau \n");
			for(i=pos;i<n-1;i++)
			{
				t[i]=t[i+1];
			}
		}
	}
	
void modifier(struct medicament t[],int n,int x,struct medicament y)
	{
		int pos=recherche(t,n,x);
		if(pos==-1)
		{
			printf("l'element deja exist \n");
		}
		else
		{
			printf("entrer le reference \n");
			scanf("%d",&y.refm);
			printf("entrer le nom \n");
			scanf("%s",&y.nom);
			printf("entrer prix d'achat \n");
			scanf("%f",&y.prix_achat);
			printf("entrer prix de vente \n");
			scanf("%f",&y.prix_vent);
			printf("entrer la contite en stock \n");
			scanf("%d",&y.contite_at_stock);
			printf("entrer la categorie \n");
			scanf("%s",&y.categorie);
			t[pos]=y;
		}
	}

int affichage_repture(struct medicament t[],int n)
	{
		int i ;
		int res=0;
		int cnt=0;
		for(i=0;i<n;i++)
		{
			if(t[i].contite_at_stock==0)
			{
				printf("%d \t\t",t[i].refm);
				printf("%s \t\t",t[i].nom);
				printf("%.2f \t\t",t[i].prix_achat);
				printf("%.2f \t\t",t[i].prix_vent);
				printf("%d \t\t",t[i].contite_at_stock);
				printf("%s \t\t",t[i].categorie);
				printf("\n");
				res++;
			}
		}
		printf("\n");
		return res;
	}
	
void affichage_catg(struct medicament t[],int n,char c[])
	{
		int i ,j;
		int r=0;
		for(i=0;i<n;i++)
		{
			if(strcmp(t[i].categorie,c)==0)
			{
				printf("%d \t\t",t[i].refm);
				printf("%s \t\t",t[i].nom);
				printf("%.2f \t\t",t[i].prix_achat);
				printf("%.2f \t\t",t[i].prix_vent);
				printf("%d \t\t",t[i].contite_at_stock);
				printf("%s \t\t",t[i].categorie);
				printf("\n");
				r++;
			}
		}
		if(r==0)
		{
			printf("cette categorie n'existe pas \n");
		}
		printf("\n");
	}
	
void affichage_plus_cher(struct medicament t[],int n)
	{
		int i ,p;
		int max=0;
		for(i=0;i<n;i++)
		{
			if(t[i].prix_vent>max)
			{
				max=t[i].prix_vent;
				p=i;			
			}
		}
			printf("%d \t\t",t[p].refm);
			printf("%s \t\t",t[p].nom);
			printf("%.2f \t\t",t[p].prix_achat);
			printf("%.2f \t\t",t[p].prix_vent);
			printf("%d \t\t",t[p].contite_at_stock);
			printf("%s \t\t",t[p].categorie);
		
		printf("\n");
	}


void affichage_moins_cher(struct medicament t[],int n)
	{
		int i ;
		int min=t[0].prix_vent;
		int p=0;
		for(i=1;i<n;i++)
		{
			if(t[i].prix_vent<min)
			{
				min=t[i].prix_vent;
				p=i;			
			}
		}
			printf("%d \t\t",t[p].refm);
			printf("%s \t\t",t[p].nom);
			printf("%.2f \t\t",t[p].prix_achat);
			printf("%.2f \t\t",t[p].prix_vent);
			printf("%d \t\t",t[p].contite_at_stock);
			printf("%s \t\t",t[p].categorie);
		
		printf("\n");
	}
	
void moyenne(struct medicament t[],int n)
	{
		int i;
		float moy_achat=0;
		float moy_vent=0;
		for(i=0;i<n;i++)
		{
			moy_achat=moy_achat+t[i].prix_achat;
			moy_vent=moy_vent+t[i].prix_vent;
		}
		moy_achat=moy_achat/n;
		moy_vent=moy_vent/n;
		
		printf("la moyenne des achat est %.2f \n",moy_achat);
		printf("la moyenne des vent est %.2f \n",moy_vent);
	}
	
void plus_rontable(struct medicament t[],int n)
{
	int i ,pos;
	float b,max=0;
	
	for(i=0;i<n;i++)
	{
		b=t[i].prix_vent-t[i].prix_achat;
		if(b>=max)
		{
			max=b;
			pos=i;
		}
	}
	printf("le medicament le plus rentable est %.2f \n",max);
	printf("%d \t\t",t[pos].refm);
	printf("%s \t\t",t[pos].nom);
	printf("%.2f \t\t",t[pos].prix_achat);
	printf("%.2f \t\t",t[pos].prix_vent);
	printf("%d \t\t",t[pos].contite_at_stock);
	printf("%s \t\t",t[pos].categorie);
	printf("\n");
}

void sauvegarder(struct medicament t[],int n)
{
	int i;
	FILE *fichier;
	char nomf[20];
	printf("donner le nom de fichier ");
	scanf("%s",&nomf);
	fichier=fopen(nomf,"w");
	if(fichier==NULL)
	{
	printf("imposible d'ouvrir fichier");
	}
	else
	{
		for(i=0;i<n;i++)
		{
			fprintf(fichier,"refm:%d \tnom:%s \tprix_achat:%.2f \tprix_vent:%.2f \tcontite_at_stock:%d \tcategorie:%s\n",t[i].refm,t[i].nom,t[i].prix_achat,t[i].prix_vent,t[i].contite_at_stock,t[i].categorie);
		}
	}
	fclose(fichier);
}

void cherche_par_char(struct medicament t[],int n)
{
	int i,count=0;
	char ch[1];
	printf("entrer le charactere \n");
	scanf("%s",&ch);
	for(i=0;i<n;i++)
		{
			if(t[i].nom[0]==ch[0])
			{
				printf("%d \t\t",t[i].refm);
				printf("%s \t\t",t[i].nom);
				printf("%.2f \t\t",t[i].prix_achat);
				printf("%.2f \t\t",t[i].prix_vent);
				printf("%d \t\t",t[i].contite_at_stock);
				printf("%s \t\t",t[i].categorie);
				printf("\n");
				count++;
			}
		}
		if(count==0)
		{
			printf("ce ledicament n'exist pas \n");
		}
		
	printf("\n");
}

void commande(struct commande tab[],int nbe)
{
	int i;
	printf("le nombre de medicament en repture de stock est %d \n",nbe);
	for(i=0;i<nbe;i++)
	{
		printf("entrer le %d reference \n",i+1);
		scanf("%d",&tab[i].refm);
		printf("entrer le nombre de commande \n");
		scanf("%d",&tab[i].numC);
		printf("entrer la date \n");
		scanf("%d",&tab[i].date);
		printf("entrer la categorie \n");
		scanf("%s",&tab[i].gtcmd);	
	}
}

void sauvegarder_commande(struct commande tab[],int nbe)
{
	int i;
	FILE *fichier;
	char nomC[20];
	printf("donner le nom de fichier ");
	scanf("%s",&nomC);
	fichier=fopen(nomC,"w");
	if(fichier==NULL)
	{
	printf("imposible d'ouvrir fichier");
	}
	else
	{
		for(i=0;i<nbe;i++)
		{
			fprintf(fichier,"refm:%d \tnum_de_commande:%d \tdate:%d \tcategorie:%s \n",tab[i].refm,tab[i].numC,tab[i].date,tab[i].gtcmd);
		}
	}
	fclose(fichier);
}
	
	

int main() 
{
	int n=2 , nbe=2;
	int opperation;
	struct medicament t[100];
	struct medicament m;
	struct commande tab[100];
	do
	{
		printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
		printf("tapez 1 pour remplir le tableau par deux medical different \n");
		printf("tapez 2 pour ajouter un medical neauveu \n");
		printf("tapez 3 pour chercher un medical par refm \n");
		printf("tapez 4 pour afficher tout les medicament \n");
		printf("tapez 5 pour suprimer un medicament \n");
		printf("tapez 6 pour modifier un medicament \n");
		printf("tapez 7 pour afficher le medicament en repture en stock \n");
		printf("tapez 8 pour afficher un medicament d'un categore donnees \n");
		printf("tapez 9 pour afficher le medicament le plus cher \n");
		printf("tapez 10 pour afficher le medicament le moins cher \n");
		printf("tapez 11 pour afficher la moyenne des prix \n");
		printf("tapez 12 pour afficher les medicament le plus rontable \n");
		printf("tapez 13 pour sauvgarder tous les medicament dans fichier \n");
		printf("tapez 14 pour chercher les medicament dont le nom commence par un caractere donnees \n");
		printf("tapez 0 pour sotir \n");
		printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
		scanf("%d",&opperation);
		switch(opperation)
		{
			case 1 :
			{
				remplissage(t);
			}
			break;
			case 2 :
			{
				ajouter(t,n,m);
				n++;
				affichage(t,n);
			}
			break;
			case 3 :
			{
				int x;
				printf("entrer le reference de medicament chercher \n");
				scanf("%d",&x);
				recherche(t,n,x);
			}
			break;
			case 4 :
			{
				affichage(t,n);
			}
			break;
			case 5 :
			{
				int x;
				printf("entrer le reference \n");
				scanf("%d",&x);
				supprimer(t,n,x);
				n--;
				affichage(t,n);
			}
			break;
			case 6 : 
			{
				struct medicament y;
				int a;
				printf("entrer le reference \n");
				scanf("%d",&a);
				modifier(t,n,a,y);
				affichage(t,n);
			}
			break;
			case 7 :
			{
				int nbe=affichage_repture(t,n);
				commande(tab,nbe);
				sauvegarder_commande(tab,nbe);
				
			}
			break;
			case 8 :
			{
				char c[20];
				printf("donner la categorie \n");
				scanf("%s",&c);
				affichage_catg(t,n,c);
			}
			break;
			case 9 : 
			{
				affichage_plus_cher(t,n);
			}
			break;
			case 10 :
			{
				affichage_moins_cher(t,n);
			}
			break;
			case 11 :
			{
				moyenne(t,n);
			}
			break;
			case 12 : 
			{
				plus_rontable(t,n);
			}
			break;
			case 13 : 
			{
				sauvegarder(t,n);
			}
			break;
			case 14 :
			{
				cherche_par_char(t,n);
			}
			break;
			case 0 : 
			{
				printf("mercii !! \n ");
			}
			break;
			default :
			{
				printf("entrer un nombre qui est existe dans le menu \n");
			}
			break;
		}
		
	}while(opperation!=0);
	return 0;
}
