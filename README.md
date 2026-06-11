# Pocket Synth – Projet 2A

## Description

Le **Pocket Synth** est un synthétiseur audio embarqué réalisé sur microcontrôleur STM32.
Il permet de générer des sons en temps réel, de modifier le son via des filtres numériques et de contrôler le tempo à l’aide d’un potentiomètre.


## Fonctionnalités

* 🎹 Génération de notes via un clavier (keypad 4x4)
* 🎛️ Sélection d’effets audio (filtres IIR)
* 🔊 Sortie audio via DAC
* 🎚️ Réglage du tempo avec un potentiomètre (ADC)
* ▶️ Mode séquenceur (lecture automatique)
* 💡 Indication visuelle avec LED


## Spécifications techniques
Microcontrôleur : STM32F303RE
Fréquence d’échantillonnage : 22.038 kHz
Résolution DAC : 12 bits (0–4095)
Traitement : temps réel (interruptions)
Séquenceur : 16 pas

##  Architecture du système

Le système repose sur une architecture temps réel basée sur interruptions :

- TIM2 : génération audio à ~22 kHz 
- DAC : conversion numérique → analogique (12 bits)
- ADC : acquisition du potentiomètre (contrôle tempo)
- GPIO : gestion led + bouton

Le traitement audio est entièrement réalisé en interruption afin de garantir un fonctionnement temps réel sans jitter perceptible.


##  Traitement du signal

* Génération d’un signal carré
* Application de filtres numériques IIR
* Conversion du signal : DAC 12 bits



##  Partie matérielle

* Clavier 4x4 (PmodKypd)
* Potentiomètre 
* Haut-parleur (via DAC + filtre RC)
* LED + bouton poussoir



##  Utilisation

1. Alimenter la carte STM32
2. Appuyer sur une touche pour jouer une note
3. Utiliser A/B/C/D pour changer d’effet
4. Ajuster le potentiomètre pour modifier le tempo
5. Utiliser le bouton pour activer/désactiver le séquenceur


## Choix techniques
Filtre IIR :
faible coût de calcul (adapté temps réel)
implémentation efficace (forme directe II transposée)
Fréquence 22 kHz :
compromis qualité audio / charge CPU
Timers matériels :
précision temporelle
réduction du jitter

##  Améliorations possibles

* Ajout d’effets audio avancés (delay, reverb)
* Interface utilisateur plus avancée
* Sauvegarde de séquences





**Projet réalisé dans le cadre du projet 2A à l’ENSISA**
