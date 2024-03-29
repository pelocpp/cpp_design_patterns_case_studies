# Semigraphisches Videospiel

#### Motivation

Stellen wir uns vor, dass wir ein retro-basiertes Videospiel auf semigraphischer Basis programmieren,
in dem tausende von Charakteren auf dem Schlachtfeld k�mpfen.
Jeder Charakter ist ein Objekt, das beispielsweise eine grafische Darstellung, ein Verhalten,
Waffen und Informationen �ber seinen Standort und seine Gesundheit besitzt.
Das Erstellen einer solchen Anzahl von Objekten ben�tigt viel Speicher.

Wir k�nnen dies verbessern, indem wir die allgemeinen Informationen wie grafische Darstellung und Verhalten teilen.
Gesundheit und Standort variieren jedoch.

#### Aufgabe

Schreiben Sie ein Programm,
das eine Klasse `Character` zur Darstellung einer Spielfigur realisiert.
Die beiden Informationen &ldquo;Farbe einer Figur&rdquo; und &ldquo;Zeichensatz f�r Textausgaben&rdquo;sind zur Vereinfachung des Beispiels 
durch zwei Variablen des Typs

```cpp
std::string m_color;
std::string m_font;
```

von allen Charakteren wiederzuverwenden.

Ein konkreter Charakter &ndash; eine Instanz der Klasse `ConcreteCharacter` &ndash; besitzt eine Methode

```cpp
void render(int x, int y);
```

Die beiden Variablen `x` und `y` variieren, es k�nnen als mehrere konkrete Charaktere existieren, 
die dieselbe Farbe und denselben Zeichensatz besitzen, aber an unterschiedlichen Positionen *x* und *y*
auf dem Spielfeld dargestellt werden. 

F�r die Verwaltung der vorhandenen `Character`-Objekte realisieren Sie eine `CharacterFactory` Klasse.
Ein Objekt des Typs

```cpp
std::unordered_map<std::string, Character> m_characterMap;
```

verwaltet die *intrinsischen* Zust�nde aller Charaktere.

Schreiben Sie eine Testfunktion, die ein oder mehrere konkrete Charaktere erzeugt und mit `render` 
auf dem Spielfeld &ldquo;zeichnet&rdquo;.



#### L�sung

[Siehe hier](Solution.md)

---

[Zur�ck](../../../Readme.md)

---
