📘 README – Contrôle LED STM32 avec Python
📌 Objectif

Ce projet permet de contrôler la LED LD2 d’une carte STM32 depuis un ordinateur via une interface graphique Python.

L’utilisateur peut allumer ou éteindre la LED en cliquant sur des boutons.

⚙️ Principe de fonctionnement

La communication entre Python et la STM32 se fait via USB (UART / port série).

Python (interface Tkinter)
        ↓
   Port série USB (COM)
        ↓
      STM32
        ↓
   GPIO PA5 → LED LD2
🖥️ Partie Python
Interface graphique réalisée avec Tkinter
Communication série avec PySerial
Deux boutons :
ON → envoie "ON\n"
OFF → envoie "OFF\n"

Python envoie des commandes texte vers la carte STM32.

🔌 Partie STM32
UART2 configuré à 115200 bauds
GPIO PA5 configuré en sortie (LED LD2)
Réception des données caractère par caractère
Lecture d’une commande complète terminée par \n

Actions :

"ON" → LED allumée
"OFF" → LED éteinte
📂 Matériel utilisé
Carte STM32 (Nucleo ou équivalent)
LED LD2 (intégrée à la carte)
Câble USB vers PC
🚀 Lancement du projet
STM32 :
Compiler et flasher le programme via STM32CubeIDE
Python :

Installer la bibliothèque :

pip install pyserial

Lancer l’interface :

python interface_led.py

Résultat:
Interface avec deux boutons
Contrôle de la LED en temps réel
Communication stable entre PC et STM32