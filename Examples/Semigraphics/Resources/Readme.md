# Semigraphisches Videospiel

#### Motivation

Stellen wir uns vor, dass wir ein retro-basiertes Videospiel auf semigraphischer Basis programmieren,
in dem tausende von Charakteren auf dem Schlachtfeld kämpfen müssen.
Jeder Charakter ist ein Objekt, das beispielsweise eine grafische Darstellung, ein Verhalten,
Waffen und Informationen über seinen Standort und seine Gesundheit enthält.
Das Erstellen einer solchen Anzahl von Objekten benötigt viel Speicher.

Wir können dies verbessern, indem wir die allgemeinen Informationen wie grafische Darstellung und Verhalten teilen.
Gesundheit und Standort variieren jedoch.

#### Aufgabe

Schreiben Sie ein Programm,
das eine Klasse `Character` zur Darstellung einer Spielfigur verwendet.
Die beiden Informationen "Farbe einer Figur" und "Zeichensatz" - zur Vereinfachung des Beispiel 
zwei Variablen des Typs

```cpp
std::string m_color;
std::string m_font;
```

sollen dabei von allen Charakteren wiederverwendet werden.

Ein konkreter Charakter - eine Instanz der Klasse `AConcreteCharacter` - besitzt eine Methode

```cpp
void render(int x, int y);
```

Die beiden Variablen variieren, es können als mehrere konkrete Charaktere existieren, 
die dieselben Farbe und denselbe Zeichensatz besitzen, aber an unterschiedlichen Positionen *x* und *y*
auf dem Spielfeld dargestellt werden. 

Für die Verwaltung der vorhandenen `Character`-Objekte realisieren Sie eine `CharacterFactory` Klasse.
Ein Objekt des Typs

```cpp
std::unordered_map<std::string, Character> m_characterMap;
```

verwaltet die *intrinsischen* Zustände aller Charaktere.

Schreiben Sie eine Testfunktion, die ein oder mehrere konkrete Charaktere erzeugt und mit `render` 
auf dem Spielfeld "zeichnet".



#### Lösung

[Siehe hier](Solution.md)

---

[Zurück](../../../Readme.md)

---
