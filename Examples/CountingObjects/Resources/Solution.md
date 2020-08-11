# Counting Objects

#### L�sung

Das hier beschriebene Problem ist ein typischer Anwendungsfall des *Composite* Entwurfsmusters
und im weiteren Verlauf des *Visitor* Entwurfsmusters

Die Details der L�sung entnehmen Sie dem Quellcode.


#### Hinweis:

Im Quellcode finden Sie noch eine weitere Zusatzaufgabe realisiert vor,
n�mlich die Bestimmung der maximalen Verschachtelungs�tiefe des Objektbaums.

Neben den `visit`-Methoden braucht die Visitor�schnitt�stelle noch eine weitere Methode,
die das Verlassen eines Kompositobjekts anzeigt, wie nennen sie `leave`.
Diese Methode muss nun auch durch die entsprechede `accept`-Methode in der Objektstruktur aufgerufen werden.

Wenn sich nun eine Operation f�r die Verschachtelungs�tiefe des Objektbaums �interessiert�,
muss sie nur dement�sprechend die `leave`-Methode implemen�tieren.
In dieser Methode muss nur eine Instanzvariable,
die die Ver�schachtelungs�tiefe repr�sentiert, dekrementiert werden,
w�hrend sie in der dazugeh�rigen `visit`-Methode inkrementiert wird.


#### Literaturhinweis

Die Anregung zum diesem Beispiel finden Sie unter

[Das Besucher-Muster (Visitor Pattern) in C++](http://www.oop-trainer.de/Themen/Visitor.html)


#### Quellcode

[Siehe hier](../CountingObjects.cpp)

---

[Zur�ck](Readme.md)

---
