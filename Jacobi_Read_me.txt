Ce script résoud un systême de n équations à n inconnues Au=b par la méthode itérative de Jacobi.
Dans la démo nous prendrons n=20.(20 inconnues)
La méthode donne la solution u seulement s'il y a convergence (ie la norme de la matrice nde Jacobi nommée J est inférieur à 1).
Vous pourrez exécuter le script dans les deux cas:
_premier cas Charger la matrice 20*20 A_Conv.txt puis la constante Const.txt
_second cas Charger A_noConv.txt et la même constante pour observer la non convergence.
( dans ce cas une autre méthode comme la résolution de Gauss pourrait trouver la solution).
Cette version démo suit volontairement les expressions matricielles de la théorie, ce qui la rend sur le plan informatique pas du tout optimisée 
Les matrice Id et D par exemple occupent de la moire inutile par des 0 
