# Simulation einer Verkehrsampel (*TrafficLight*)

#### Aufgabe

Schreiben Sie ein C++-Programm, dass die drei Phasen eine Verkehrsampel (Rot, Gr�n, Gelb)
in einer Konsolen-Anwendung simuliert. Nach jedem Phasenwechsel soll in der Konsole
eine entsprechende Ausgabe erscheinen:

*Ausgabe*:

```cpp
TrafficLight: Variant 01
Red Light
Green Light
Yellow Light
Red Light
Green Light
... 
... 
... 
```

Welches klassische Entwurfsmuster bietet sich zur Realisierung an?

###### Zusatzaufgabe 1

Vielleicht ist es Ihnen schon aufgefallen:
Die meisten Menschen in Deutschland denken, dass eine Ampel nur drei verschiedene Schaltphasen hat, n�mlich gr�n, gelb und rot!
Das ist aber verkehrt, nach rot wird die Ampel nicht wieder gelb sondern **rot-gelb**!

Erweitern Sie die vorliegende L�sung so, dass sie vier Ampelphasen besitzt.

###### Zusatzaufgabe 2

Zus�tzlich zum eigentlich zu w�hlenden Entwurfsmuster bietet sich in der 
Realisierung ein zweites Entwurfsmuster an: Das *Singleton* Muster.

Erstellen Sie eine zweite Realisierung, die die erste Implementierung
um die Integration des *Singleton* Musters erg�nzt.

#### L�sung

[Siehe hier](Solution.md)

---

[Zur�ck](../../Readme.md)

---
