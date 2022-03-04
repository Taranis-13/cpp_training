#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

/*test commentaire*/

class matrice
{
private:
 				int li,col;
                double**tab;
                double val;	                
public:
			
//Quelques constructeurs

 //saisie manuelle d'une matrice
 matrice(int , int );            


//matrice  pleine de val 
matrice(int li, int col, double val);           

//déclaration par un nouveau caractère
matrice(const matrice &ch) ;


//destructeur                         
~matrice(); 
                         
//affichage d'une matrice                          
void afficher();

//enregistrer une matrice dans un fichier
void save();

//......................................................
//somme de matrices

matrice operator+(const matrice &m1);
                                                                                    
};                         

//********************************************************

//Quelques constructeurs

 //saisie manuelle d'une matrice
 // voir https://www.developpez.net/forums/d1198207/c-cpp/cpp/debuter/exercice-matrice-cpp/
matrice::matrice(int li, int col)
           //li(n),col(p)                    //variante amusante !!                        
{
           this->li=li;
            this->col=col;
            this->val=val;
          tab=new double *[li];
          for(int i = 0;i < col;++i) tab[i] = new double[li];
           //tab=  tab[li][col];
            cout<<"saisie des termes de la matrice "<<li<<"*"<<col<<endl;
            for(int i=0;i<li;i++)
            {
                    for(int j=0;j<col;j++)
                    {
                    cout<<"ligne "<<i+1<<"  colonne  "<<j+1<<"   ";
                    scanf("%lg",&val);
                    tab[i][j]=val;                   
                    }
            }
            
}

//matrice  pleine de val 
matrice::matrice(int li, int col, double val) 
{
            this->li=li;
            this->col=col;
            this->val=val;
           tab=new double *[li];
          for(int i = 0;i < col;++i) tab[i] = new double[li];
            
            for(int i=0;i<li;i++)
            {
                    for(int j=0;j<col;j++)
                    {
                   
                    tab[i][j]=val;                   
                    }
            }
} 



//destructeur                         
matrice::~matrice()               
{
            delete[] tab;
            //cout<<"destruction"<<endl;
            //system("pause");
} 

//********************************************************* 
//Definition des fonctions
void matrice::afficher()
{
     cout<<"nb de lignes:   "<<li<<endl;
     cout<<"nb de colonnes: "<<col<<endl;
      for(int i=0;i<li;i++)
      {               for(int j=0;j<col;j++)
                      
                      {
                      cout<<tab[i][j]; 
                      
                      }
      cout<<endl;
      } 
cout<<endl;     
} 

//enregistrer une matrice dans un fichier
//void matrice::save()
//{       FILE *P_FICHIER; /* pointeur sur FILE (FILE est une structure)*/
/*        char NOM_FICHIER[30];
        int  NB_ENREG;

        //Créer et remplir le fichier 
        printf("Entrez le nom du fichier à créer : ");
        scanf("%s", NOM_FICHIER);
        P_FICHIER = fopen(NOM_FICHIER, "w");  /* write */  
  /*      NB_ENREG=li*col;
         
        for(int i=0;i<li;i++)
        {
          for(int j=0;j<col;j++)
          {    
          val=tab[i][j];
          fprintf(P_FICHIER, "%Lf\n",val);
          }
         }
         fclose(P_FICHIER);
}
 */    
                         
//somme de matrices
matrice matrice::operator+(const matrice &m1)  
{
        int n=m1.li;
        int p=m1.col;
        matrice r(n , p,0);
        this->tab= tab;
        //cout<<li<<endl;
        
        if(n!=li||p!=col) 
        	{ cout<<"Erreur; dimensions incompatibles     "<<endl ;
       		}
        else
        	{
			
			for(int i=0; i<n; i++)
        		{
                for(int j=0; j<p; j++)
                	{
                
                	r.tab[i][j]=m1.tab[i][j]+tab[i][j];
                	}
                 
         		}
       			

			}
return r;			
}

       
//Le main      
int main(int argc, char *argv[])

{   //utilisation des différents constructeurs
int l;int c;
printf("Entrez le nombre l de lignes et le nombre c de colonnes: ");
cout<<"lignes";
cin>>l;
cout<<"colonnes";
cin>>c;

    matrice A(l,c);                
    //matrice p(2,2);
    matrice q(2,2,1); // matrice pleine de 1
	A.afficher(); 
    //p.afficher();
    q.afficher();
    matrice x=A+q;
    x.afficher(); // affiche même si l'opération est impossible !!!!
    //x.save();
    system("pause");
    return 0;
}
