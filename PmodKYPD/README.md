Clavier PmodKYPD (4x4)

Objectif:

Ce programme permet de tester et valider le fonctionnement du clavier matriciel 4x4 (PmodKYPD) avant son intégration dans le projet principal Pocket Synth.

Principe de fonctionnement:

Le clavier est organisé sous forme de matrice :

4 lignes (rows)
4 colonnes (columns)

Le scan matriciel consiste à :

Mettre toutes les lignes à l’état haut (HIGH)
Activer une seule ligne à la fois (mise à LOW)
Lire l’état des colonnes
Détecter une touche si une colonne passe à LOW
Associer la position (ligne, colonne) à une valeur via un tableau

Implémentation :
Les lignes sont configurées en sorties GPIO
Les colonnes sont configurées en entrées avec résistances de pull-up
Une fonction Keypad_Scan() réalise le balayage complet
Un anti-rebond logiciel est implémenté avec HAL_Delay(20)
Une attente de relâchement de touche évite les répétitions

Résultat:

Le programme permet de :

Détecter correctement les touches pressées
Identifier chaque touche du clavier
