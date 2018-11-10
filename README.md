# Double-Git-Heroes - L2 Info

###### Fonction Main

* Déclaration des variables (structure Coordonnees [point], [dt], ...)

* Appel des fonctions d'initialisation (cf. *Entrées*, *Position* et *Fichier*)

* Appel des fonctions de calcul et de stockage des points (cf. *Position* et *Fichier*)

* Appel des fonctions d'affichage (cf. *Gnuplot*)

###### Librairies

* Entrées

  * Demande des parametres ([σ],[β] et [ρ] ecrit respectivement [S], [B] et [P]).

  * Demande de la position initiale ([x], [y], [z] et [Tmax])

  * Demande de la MàJ de la vitesse ([dt])

  * Demande de la définition des parametres (vie la notation polonaise inversée)

* Position

  * Création de la structure [Coordonnees]

  * Initialisation de la position

  * Calcul de la nouvelle position en fonction des coordonées, dt et des parametres

* Fichier

  * Initialisation du fichier BdD 

  * Ouverture (mode [a]) et ecriture de la position en format [temps x y z]

  * Ouverture (mode [r]) et lecture des positions

* Gnuplot

  * Tracer la courbe

  * Afficher

    * OU la vitesse par des vecteurs

    * OU la vitesse par une couleur

    * OU le temps par un changement de couleur


#### A faire - 16/11

* Sections Librairies (4 sections)

  * Fonction

    * Que fait-elle ?

    * Que prend t-elle en entrée ? Que renvoit-elle ?

    * Quelles autres fonctions utilise t-elle ?

* Section Dépendance des librairies

* Section Organisation du Programme Principal

* Section Difficultées attendues & Solutions
