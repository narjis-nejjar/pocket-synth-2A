# Test du DAC – Validation matérielle

## Objectif

Valider le bon fonctionnement du DAC du microcontrôleur STM32 avant son utilisation dans le projet **Pocket Synth**.

---

## Méthodologie

Le test est réalisé en plusieurs étapes :

1. Génération d’un signal sinusoïdal lent (~1 Hz)
2. Observation du signal via une LED connectée à la sortie DAC
3. Vérification de la variation d’intensité lumineuse
4. Augmentation progressive de la fréquence
5. Observation du signal à l’oscilloscope

---

## Résultat

* Variation visible de la luminosité de la LED → DAC fonctionnel
* Signal sinusoïdal observable à l’oscilloscope
* Validation de la chaîne de conversion numérique → analogique

---

## Conclusion

## Le DAC est fonctionnel et peut être utilisé pour la génération audio dans le projet final.

