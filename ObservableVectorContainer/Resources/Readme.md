# Observable Vector Container

#### Aufgabe

Schreiben Sie eine Klassenschablone, die sich wie die Standardklasse `std::vector` verh�lt,
aber registrierte Objekte �ber interne Zustands�nderungen informieren kann.
Die Klasse sollte mindestens die folgenden Operationen bereitstellen:

  * Verschiedene Konstruktoren zum Erstellen neuer Instanzen der Klasse
  * Wertzuweisungsoperator `operator=` um dem Container Werte zuzuweisen
  * Methode `push_back`, um ein neues Element am Ende des Containers hinzuzuf�gen
  * Methode `pop_back`, um das letzte Element aus dem Container zu entfernen
  * Methode `clear`, um alle Elemente des Containers zu entfernen
  * Methode `size`, um die Anzahl der Elemente des Containers zu bestimmen
  * Methode `empty`, die angibt, ob der Container leer ist oder Elemente enth�lt

Bei einem Aufruf von 
`operator=`, `push_back`, `pop_back` und `clear` sind angemeldete Clients �ber den Statuswechse zu informieren.
Die Benachrichtigung sollte die Art der �nderung beschreiben und, falls dies der Fall ist,
den Index des Elements enthalten, das ge�ndert wurde (z.B. Element hinzugef�gt oder entfernt).

Welches klassische Entwurfsmuster bietet sich zur Realisierung an?

Schreiben Sie eine Testfunktion, die alle beschriebenen Methoden und Operatoren testet.

###### Zusatzaufgabe


#### L�sung

[Siehe hier](Solution.md)

---

[Zur�ck](../../Readme.md)

---
