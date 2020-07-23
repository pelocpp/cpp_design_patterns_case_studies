# Password-Generator

#### L�sung

Das hier beschriebene Problem ist ein typischer Anwendungsfall f�r das *Composite Pattern* Entwurfsmuster.

Dieses Entwurfsmuster setzt Objekte in Baumhierarchien zusammen und erm�glicht
auf diese Weise die Behandlung von Gruppen (oder B�umen) von Objekten auf die gleiche Weise wie einzelne Objekte des gleichen Typs.
Das folgende Klassendiagramm
zeigt eine Hierarchie von Klassen, die zum Generieren von Passw�rtern verwendet werden k�nnten:

<img src="dp_password_generator.svg" width="800">

Abbildung 1: Schematische Darstellung des *Composite* Patterns im Anwendungsfall *PasswortGenerator*.

`PasswordGenerator` ist die Basisklasse und verf�gt �ber mehrere virtuelle Methoden:
`generate` gibt eine zuf�llig generierte Zeichenfolge zur�ck, `length` die L�nge
der Zeichenfolge.
`allowedChars` gibt eine Zeichenfolge mit allen Zeichen zur�ck,
die zum Generieren verwendet werden d�rfen. Also zum Beispiel `"0123456789"` im Falle
der Klasse `DigitGenerator`.
`BasicPasswordGenerator` wird von dieser Basisklasse abgeleitet
und definiert einen Generator mit einer Mindestl�nge.
`DigitGenerator`, `SymbolGenerator`, `UpperLetterGenerator`
und `LowerLetterGenerator` werden von `BasicPasswordGenerator` abgeleitet und
�berschreiben allesamt `allowedChars`, um die jeweiligen Teilmengen von Zeichen zu definieren,
die zum Generieren von zuf�lligen Texten verwendet werden d�rfen.
Nat�rlich besitzen sie auch eine Methode `generate`, um an Hand dieser Vorgaben
ein Passwort zu generieren.

*Beispiel*:

```cpp
std::unique_ptr<DigitGenerator> digiGen = std::make_unique<DigitGenerator>(4);
password = digiGen->generate(engine);
std::cout << "DigitGenerator:       " << password << std::endl;
```

Neben den einzelnen Spezialklassen f�r die Generierung eines Passworts
an Hand einer bestimmten Regel gibt es auch einen *zusammengesetzten* Generator:
Klasse `CompositePasswordGenerator`. Diese Klasse
repr�sentiert gewisserma�en ein Kompositum von einer oder mehrerer
untergeordneter Spezialklassen.
`add` f�gt einem zusammengesetzten Generator eine untergeordnete Komponente hinzu.
Die Klasse `CompositePasswordGenerator` besitzt ebenfalls eine Methode `generate`,
diese nimmt die Hilfe der unterlagerten Spezialklassen in Anspruch.

*Beispiel*:

```cpp
CompositePasswordGenerator compositeGenerator;
compositeGenerator.add(std::make_unique<UpperLetterGenerator>(8));
compositeGenerator.add(std::make_unique<LowerLetterGenerator>(8));
password = compositeGenerator.generate(engine);
std::cout << "CompositeGenerator:   " << password << std::endl;
```


#### Quellcode

[Siehe hier](../GeneratingPasswords.cpp)

---

[Zur�ck](Readme.md)

---
