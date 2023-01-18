#include <stdio.h>
#define TAILLE 7
#include <string.h>
typedef enum {VRAI=1, FAUX=0} Bouleen;

void initG(unsigned int tabl[TAILLE][TAILLE]){
	for(int i=0;i<7;i++)
		for(int j=0;j<7;j++)
			tabl[i][j]=0;
	}

void afficheG(unsigned int tabl[TAILLE][TAILLE],unsigned int nbC){
	printf("\n 1  2  3  4  5  6  7 			Coup no: %u\n",nbC);
	for(int i=0;i<7;i++)
		{for(int j=0;j<7;j++)
			{if (tabl[i][j]==0)
				printf(" . ");
			else if (tabl[i][j]==1)
				printf(" X ");
			else if (tabl[i][j]==2)
				printf(" O ");
			else printf(" ? ");
			}
		printf("\n");
		}
	printf(" 1  2  3  4  5  6  7 ");
	printf("\n\n");
	}

unsigned int placeJeton(int numJoueur, unsigned int numCol, unsigned int tabl[TAILLE][TAILLE]){
	if (numJoueur==1)
		{int i=7;
		while(i>0)
			{if (tabl[i-1][numCol-1]==0)
				{tabl[i-1][numCol-1]=1;
				break;
				}
			else 
				{i--;}
			}
		}
	else
		{int i=7;
		while(i>0)
			{if (tabl[i-1][numCol-1]==0)
				{tabl[i-1][numCol-1]=2;
				break;
				}
			else 
				{i--;}
			}
		}
	}

Bouleen estPleine(unsigned int numC, unsigned int tabl[TAILLE][TAILLE]){
	int i=7;
	while(numC>=0)
		{
		if (i==0)
			{printf("\nLa colonne est PLEINE.\n\n");
			return VRAI;
			break;}
		if (tabl[i-1][numC-1]==0)
			{return FAUX;
			break;
			}
		else
			{i--;}
		}
	}

/**
 * C program to print heart star pattern with center name
 */
 

 
int heart(char name[20])
{
    int i, j, n=10;

    int len;


    len = strlen(name);

    // Print upper part of the heart shape
    for(i=n/2; i<=n; i+=2)
    {
        for(j=1; j<n-i; j+=2)
        {
            printf(" ");
        }
 
        for(j=1; j<=i; j++)
        {
            printf("*");
        }
 
        for(j=1; j<=n-i; j++)
        {
            printf(" ");
        }
 
        for(j=1; j<=i; j++)
        {
            printf("*");
        }
 
        printf("\n");
    }
 
    // Prints lower triangular part of the pattern
    for(i=n; i>=1; i--)
    {
        for(j=i; j<n; j++)
        {
            printf(" ");
        }
        
        // Print the name
        if(i == n) 
        {
            for(j=1; j<=(n * 2-len)/2; j++)
            {
                printf("*");
            }   

            printf("%s", name);

            for(j=1; j<(n*2-len)/2; j++)
            {
                printf("*");
            }
        }
        else 
        {
            for(j=1; j<=(i*2)-1; j++)
            {
                printf("*");
            }
        }
 
        printf("\n");
    }
 
    return 0;
}

Bouleen estGagne(unsigned int numJou,unsigned int tabl[TAILLE][TAILLE]){
	//Vertical Test
	for(int i=0;i<4;i++)
		{for(int j=0;j<7;j++)
			{if ((tabl[i][j]==numJou && tabl[i+1][j]==numJou) && (tabl[i+2][j]==numJou && tabl[i+3][j]==numJou))
				{return VRAI;
				break;}
			}
		}

	//Horizontal Test
	for(int i=0;i<7;i++)
		{for(int j=0;j<4;j++)
			{if ((tabl[i][j]==numJou && tabl[i][j+1]==numJou) && (tabl[i][j+2]==numJou && tabl[i][j+3]==numJou))
				{return VRAI;
				break;}
			}
		}
	//Diagonal Test (Descending)
	for(int i=0;i<4;i++)
		{for(int j=0;j<4;j++)
			{if ((tabl[i][j]==numJou && tabl[i+1][j+1]==numJou) && (tabl[i+2][j+2]==numJou && tabl[i+3][j+3]==numJou))
				{return VRAI;
				break;}
			}
		}
	//Diagonal Test (Ascending)
	for(int i=6;i>2;i--)
		{for(int j=0;j<4;j++)
			{if ((tabl[i][j]==numJou && tabl[i-1][j+1]==numJou) && (tabl[i-2][j+2]==numJou && tabl[i-3][j+3]==numJou))
				{return VRAI;
				break;}
			}
		}
	return FAUX;
	}
	
	
	


void main(){
	char Hadi[20],Badr[20];
	unsigned int grille[TAILLE][TAILLE];

	printf("Nom du joueur1:");
	scanf("%s",Hadi);   

	printf("Nom du joueur2:");
	scanf("%s",Badr);
	//Les deux joueurs
	printf("\nBienvenue %s et %s\n\n",Hadi,Badr);
	
	unsigned int nbCoups = 0;
	initG(grille);
	afficheG(grille,nbCoups);
	unsigned int colonneI;
	int pleineCond;
	
	while(nbCoups<49)
		{unsigned int joueur;
		joueur = nbCoups%2;
		joueur = joueur+1;
		if (joueur==1)
			{do
				{printf("%s dans quelle colonne souhaitez-vous déposer un jeton?",Hadi);
				scanf("%u",&colonneI);
				pleineCond=estPleine(colonneI,grille);
				
				}
			while((colonneI>7 || colonneI<0) || pleineCond);
			nbCoups++;
			placeJeton(joueur,colonneI,grille);
			afficheG(grille,nbCoups);
			}
		else
			{do
				{printf("%s dans quelle colonne souhaitez-vous déposer un jeton?",Badr);
				scanf("%u",&colonneI);
				pleineCond=estPleine(colonneI,grille);
				
				}
			while((colonneI>7 || colonneI<0) || pleineCond);
			nbCoups++;
			placeJeton(joueur,colonneI,grille);
			afficheG(grille,nbCoups);
			}
		int gagneCond=estGagne(joueur,grille);
		if(gagneCond)
			{if(joueur==1)
				{printf("\nBRAVO, %s YOU HAVE WON\nWHAT ARE YOU GONNA DO WITH THE 10 MILLIONS $ NOW?\n\n",Hadi);
				heart(Hadi);}
			else
				{printf("\nBRAVO, %s YOU HAVE WON\nWHAT ARE YOU GONNA DO WITH THE 10 MILLIONS $ NOW?\n\n",Badr);
				heart(Badr);}





			nbCoups=50;

			}
		}
	

	}
