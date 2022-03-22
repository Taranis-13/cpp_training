#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdexcept>
#include <cstring>
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
 
 // déclaration d'une matrice de dimensions inconnues         
matrice();

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

// importation d'une matrice
void read();

//somme de matrices
matrice operator+(const matrice &m1);

//produit de matrices
matrice operator*(const matrice &m1);
                                                                                    
};                         

//********************************************************

//Quelques constructeurs

matrice::matrice(void)
{
}

 //saisie manuelle d'une matrice
 // voir https://www.developpez.net/forums/d1198207/c-cpp/cpp/debuter/exercice-matrice-cpp/
 
matrice::matrice( int li,  int col)
                              
{		
            this->li=li; 
            this->col=col;
            //this->val=val;  ligne inutile
          tab=new double *[li];
          for(int i = 0;i < li;++i) tab[i] = new double[col];
           //tab=  tab[li][col];
            cout<<"saisie des termes de la matrice "<<li<<"*"<<col<<endl;
            for(int i=0;i<li;i++)
            {
                    for(int j=0;j<col;j++)
                    {
                    cout<<"ligne "<<i+1<<"  colonne  "<<j+1<<"   ";
                    scanf("%lf",&val);
                    //cin>>val;
                    tab[i][j]=val;                   
                    }
            }
            
}

//matrice  pleine de val 
matrice::matrice(int li, int col, double val) 
{
            this->li=li;
            this->col=col;
            this->val=val+2;
           tab=new double *[li];
          for(int i = 0;i < li;++i) tab[i] = new double[col];
            
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
                      cout<<tab[i][j]<<"   "; 
                      
                      }
      cout<<endl;
      } 
cout<<endl;     
} 

//enregistrer une matrice dans un fichier
// les deux premières valeurs sont les dimensions de la matrice;  
 void matrice::save()
{       
    char NOM_FICHIER[30];
        
    cout<<"Entrez le nom du fichier à créer; n'oubliez pas ***.txt : ";
    cin>>NOM_FICHIER;
  	ofstream FICHIER(NOM_FICHIER, ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
 
        if(!FICHIER.is_open())
        cout << "Impossible d'ouvrir le fichier en écriture !" << endl;
        else
        {	FICHIER<<li<<"	"<<col<<"\n";  //enregistrement du nombre de lignes et de colonnes /FICHIER<<li<<"	"<<col<<"\n";
 		for(int i=0;i<li;i++)
        	{
          	for(int j=0;j<col-1;j++)
          		{    
          		val=this->tab[i][j];
          		//cout<<val<<endl;		// affichage provisoire         	
          		FICHIER<<val<<"	";  	// enregistrement de la ligne i; délimiteur tab
    			}
    			val=this->tab[i][col-1];
    			FICHIER<<val<<"\n";		//enregistrement du dernier terme de le ligne i et saut de ligne
    		}
           FICHIER.close();  
		}		
}

// importation d'une matrice d'un fichier texte
// 
void matrice::read()
{
	char NOM_FICHIER[20];	
	
 	cout<<"Entrez le nom du fichier à ouvrir : ";
 	cin>>NOM_FICHIER;
 	ifstream FICHIER(NOM_FICHIER);
 	cout<<"Lecture du fichier:     ";
 	if(!FICHIER.is_open())
 		cout << "Impossible d'ouvrir le fichier en lecture !" << endl;
 	else
 		{
 		
 		 FICHIER>>li>>col;   			// importation des dimensions de la matrice
 		cout<<li<<"	"<<col<<endl;
 		tab=new double *[li];
        for(int i = 0;i <li;++i) tab[i] = new double[col];
 		
		 for(int i=0;i<li;i++)
            {
            for(int j=0;j<col;j++)
                {
                   
                FICHIER>>tab[i][j];                   
                }
            }
 	FICHIER.close(); 
		}		
}
//somme de matrices
matrice matrice::operator+(const matrice &m1)  
{
        int n=m1.li;
        int p=m1.col;
        matrice r(n,p,0);
        
        cout<<li<<endl;  //li et col sont les dimensions de la matrice A
        cout<<col<<endl;
        int c;
        if(n==li&&p==col) 
        	{
			for(int i=0; i<n; i++)
        		{
                for(int j=0; j<p; j++)
                	{
                
                	r.tab[i][j]=m1.tab[i][j]+tab[i][j];
                	}
                 
         		}
       		cout<<"Resultat de la somme:   "<<endl;
       		return(r);
		   	
			}
        else
        	{ throw invalid_argument("Erreur; dimensions incompatibles     ");    
        	
        	}
}

			   		
//produit de matrices
matrice matrice::operator*(const matrice &m1)  
{
        int n=m1.li;
        int p=m1.col;
        matrice r(li,p,0);
        
        cout<<n<<endl;  
        cout<<col<<endl;
        
        if(n==col) // le nombre de colonnes de A doit être celui des lignes de m1
        	{
			for(int i=0; i<li; i++)
        		{
                for(int j=0; j<p; j++)
                	{
                	for(int k=0; k<n; k++)
                		{
					
                		r.tab[i][j]=r.tab[i][j]+tab[i][k]*m1.tab[k][j];
                		}
                	}                 
         		}
       		cout<<"Resultat du produit:   "<<endl;
		   return(r);	
			}
        else
        	{ throw invalid_argument("Erreur; dimensions incompatibles     ");  
       		}		
}




 //********************************************************************************      
//Le main      
int main(int argc, char *argv[])

{   cout<<"Ce petit programme vous permet d'importer deux matrices A et B des fichiers A.txt et B.txt"<<endl;
cout<<"Ensuite la somme A+B et le produit A*B seront calculés; vous pourrez enregistrer les rsultats"<<endl;
matrice A;  
    A.read();
    A.afficher();
matrice B;
	B.read();
	B.afficher();
	
matrice S=A+B;   
    S.afficher();
    
matrice P=A*B;	
	P.afficher();
cout<<"Enregitremet des résultats dans les fichiers S.txt et P.txt (ou autres .txt selon votre choix "<<endl;
S.save();
P.save();

return(0) ;
}
