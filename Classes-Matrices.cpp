#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdexcept>
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
           
          tab=new double *[li];
          for(int i = 0;i < li;++i) tab[i] = new double[col];
          
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
        
        printf("Entrez le nom du fichier à créer; n'oubliez pas ***.txt : ");
        cin>>NOM_FICHIER;
  ofstream FICHIER(NOM_FICHIER, ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
 
        if(!FICHIER.is_open())
        cout << "Impossible d'ouvrir le fichier en écriture !" << endl;
        else
        {	FICHIER<<li<<"	"<<col<<"	";  //enregistrement du nombre de lignes et de colonnes /FICHIER<<li<<"	"<<col<<"\n";
 			for(int i=0;i<li;i++)
        	{
          	for(int j=0;j<col;j++)
          		{    
          		val=this->tab[i][j];
          		cout<<val<<endl;
          	
          		FICHIER<<val<<"	";  // enregistrement de termes de la matrice; délimiteur tab
    			}
    		}
           FICHIER.close();  
		}		
}

// importation d'une matrice d'un fichier texte

void matrice::read()
{
	char NOM_FICHIER[30];	
	
 	cout<<"Entrez le nom du fichier à ouvrir : ";
 	cin>>NOM_FICHIER;
 	ifstream FICHIER(NOM_FICHIER);
 	
 	
 	if(!FICHIER.is_open())
 		cout << "Impossible d'ouvrir le fichier en lecture !" << endl;
 	else
 		{ FICHIER>>li>>col;   // importation des dimensions de la matrice
 		cout<<li<<"	"<<col<<endl;
 		tab=new double *[li];
          for(int i = 0;i < li;++i) tab[i] = new double[col];
            
            for(int i=0;i<li;i++)
            {
                    for(int j=0;j<col;j++)
                    {
                   
                    FICHIER>>tab[i][j];                   
                    }
            }
 		 		
		 } 
 	FICHIER.close(); 
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
        	{ throw invalid_argument("Erreur; dimensions incompatibles     ");    // à perfectionner  	
        	
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
/*int l;int c;
cout<<"Entrez le nombre l de lignes et le nombre c de colonnes: "<<endl;
cout<<"lignes";
cin>>l;
cout<<"colonnes";
cin>>c;*/
{   //utilisation des différents constructeurs


    matrice A(2,2);  		// pour saisie manuelle              
	A.afficher(); 
	matrice B(2,2);			// (2,2) pour aucune erreur; (2,3) erreur dans somme ; (3,2) erreur à somme et produit
	B.afficher();
	
	matrice q(2,2,1); 		// matrice pleine de 1 de dimension 2*2
    q.afficher();
try {
    matrice x=A+B;  		// somme de matrices avec gestion d'exeptions 
    x.afficher(); 			//résultat
    x.save();				// pour enregistrer dans un fichier .txt
	}
catch (invalid_argument& e)	// gestion de l'exception
	{
		cerr << e.what() << endl;
        cout<<"Try again with right values: l=2, c=2   "<<endl;
        
        matrice C(2,2);
        matrice x=A+C;  		// somme de matrices 
    	x.afficher(); 			//résultat
	}

   /* Importetion de matrice */    
    matrice y;  
    y.read();	// prendre le fichier Mat55.txt ; y matrice carrée 5*5
    y.afficher();
    matrice s=y+y;
    s.afficher();
    
try{
    	matrice z=A*y;// un produit A*B
    	z.afficher();
	}
catch (invalid_argument& e)	// gestion de l'exception		
	{
		cerr << e.what() << endl;
        cout<<"Try again with right values:  c=nombre de colonnes de y   "<<endl;
        
        matrice C(2,4);
        matrice z=A*C;  		// somme de matrices 
    	z.afficher(); 			//résultat
	}	
	
return(0);
}
