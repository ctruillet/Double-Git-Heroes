# Double-Git-Heroes - L2 Info

###### Fonction Main

* Déclaration des variables (structure Coordonnees [point], [dt], ...)

* Appel des fonctions d'initialisation (cf. *Entrées*, *Position* et *Fichier*)

* Appel des fonctions de calcul et de stockage des points (cf. *Position* et *Fichier*)

* Appel des fonctions d'affichage (cf. *Gnuplot*)

###### Librairies

* Entrées

  * Demande de la position initiale ([x], [y], [z] et [Tmax])
  
  * Demande des parametres ([σ],[β] et [ρ] ecrit respectivement [S], [B] et [P]).

  * Demande de la MàJ de la vitesse ([dt])
  

* Position

  * Création de la structure [Coordonnees]

  * Initialisation de la position

  * Calcul de la nouvelle position en fonction des coordonées, dt et des parametres
  

* Fichier - position.txt

  * Initialisation du fichier (mode [w+]) 

  * Ouverture (mode [a]) et ecriture de la position en format [temps x y z]

  * Ouverture (mode [r]) et lecture des positions
  
  
* Log - .log
  
  * Initialisation d'un nouveau fichier .log (mode [w+]) (name : TIME.log)
  
  * Ouverture (mode [a]) et ecriture du log
  

* Gnuplot

  * Tracer la courbe

  * Afficher le temps par un changement de couleur (dégradé temporel )


#### A faire - 16/11

* Sections Librairies (5 sections)

  * Fonction

    * Que fait-elle ?

    * Que prend t-elle en entrée ? Que renvoit-elle ?

    * Quelles autres fonctions utilise t-elle ?

* Section Dépendance des librairies

* Section Organisation du Programme Principal

* Section Difficultées attendues & Solutions
