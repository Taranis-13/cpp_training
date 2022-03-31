#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdexcept>
#include <cstring>
#include <cmath>
using namespace std;

/*test commentaire*/

class matrice
{
private:
 				
                double**tab;
                double val;	 
				int li,col;            
public:
			
//Quelques constructeurs

 //saisie manuelle d'une matrice
 matrice(int , int );  
 
 // déclaration d'une matrice de dimensions inconnues         
matrice();

//matrice  pleine de val 
matrice(int li, int col, double val);  

//matrice identité n
 Id(int li);       

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

//différence de matrices
matrice operator-(const matrice &m1);

//produit de matrices
matrice operator*(const matrice &m1);

// copie de matrices
void copy(const matrice &m);

// extraction de la diagonale inverse d'une matrice
 Invdiag (const matrice &m) ; //
 
// nombre de lignes
int lineof();

// norme vectorielle
double norme();
                                                                               
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
            this->val=val;
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

//matrice identité
matrice::Id(int li)
{this->li=li;
this->col=li;
tab=new double *[li];
          for(int i = 0;i < li;++i) tab[i] = new double[col];
for(int i=0;i<li;i++)
            {
                    for(int j=0;j<col;j++)
                    {if(i==j) tab[i][j]=1;
                    else
                    tab[i][j]=0;
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
        
        //cout<<li<<endl;  
        //cout<<col<<endl;
        
        if(n==li&&p==col) //li et col sont les dimensions de la première matrice
        	{
			for(int i=0; i<n; i++)
        		{
                for(int j=0; j<p; j++)
                	{
                
                	r.tab[i][j]=m1.tab[i][j]+tab[i][j];
                	}
                 
         		}
       		
       		return(r);
		   	
			}
        else
        	{ throw invalid_argument("Erreur; dimensions incompatibles     ");    
        	
        	}
}

//différence de matrices
matrice matrice::operator-(const matrice &m1)  
{
        int n=m1.li;
        int p=m1.col;
        matrice r(n,p,0);
        
        //cout<<li<<endl;  //li et col sont les dimensions de la matrice A
        //cout<<col<<endl;
        int c;
        if(n==li&&p==col) 
        	{
			for(int i=0; i<n; i++)
        		{
                for(int j=0; j<p; j++)
                	{
                
                	r.tab[i][j]=tab[i][j]-m1.tab[i][j];
                	}
                 
         		}
       		
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
        
        //cout<<n<<endl;  
        //cout<<col<<endl;
        
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
       		
		   return(r);	
			}
        else
        	{ throw invalid_argument("Erreur; dimensions incompatibles     ");  
       		}		
}


// copie de matrices de mêmes dimensions
void matrice::copy(const matrice &m)
{ 
	int l=li;
	int c=col;
	for(int i=0;i<l;i++)
		{
		for(int j=0;i<l;i++)
		tab[i][j]=m.tab[i][j];	//m2 est copiée dans m1 ; m1.copy(m2)
		}
	
}


// diagonale
matrice::Invdiag(const matrice &m)
{
	int n=m.li;
	this->li=n;  //permet de dimensionner la matrice D du main
	this->col=n;
      
 	tab=new double *[n];
          for(int i = 0;i < n;++i) tab[i] = new double[n];
          
       for(int i=0; i<n; i++) 
       	{	for(int j=0; j<n; j++)
       		{ if(i==j) tab[i][j]=1/m.tab[i][j];
       		else 
       		tab[i][j]=0;
       		
			}
       }   
}


// nombre de lignes
int matrice::lineof()
{
	
	return(li);
}

// norme vectorielle
double matrice::norme()
{
	
	double n=0;
	for(int i=0;i<li;i++)
		{
		for(int j=0;j<col;j++)	
			{n=n+abs(tab[i][j]);
			}
			n=n/li;
		}
	return(n);
}



 //********************************************************************************      
//Le main      
int main(int argc, char *argv[])
{
	matrice A;      				// matrices de l'équation Au=b
    A.read();
    A.afficher();
    
    matrice b;      
    b.read();
    b.afficher();
 
		int l;			 
	l=A.lineof();

	matrice I;
	I.Id(l);  						// Identité
	//I.afficher();


	matrice D;						//La dimension de D est assurée par la fonction Invdiag()
	D.Invdiag(A);
	//D.afficher();
	
	
	matrice J=I-D*A; 				//Matrice dite de Jacobi
	//J.afficher();
	
	/* Début de la resolution */

	
	matrice u(l,1,0);   			//initialisations arbitraires
	double Erreur=100;
					
	while (Erreur>0.00001)			// iterations
		{
			matrice v=J*u+D*b;
			Erreur=(u-v).norme();
			u.copy(v);
			if(Erreur>10000000) 
				{
				cout<<" Non convergence    "<<endl;
				EXIT_FAILURE;
				break;
				}
				
		}		
			if(Erreur<0.00001) 
			{
				cout<<" Solution du systeme    "<<endl;	
				u.afficher();   			// solution du systême
			}
			
return(0);	
}



