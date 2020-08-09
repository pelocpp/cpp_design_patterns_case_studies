# Semigraphisches Videospiel

#### L�sung

Das hier beschriebene Problem ist ein typischer Anwendungsfall des *Flyweight* Entwurfsmusters.

Die Details der L�sung entnehmen Sie dem Quellcode.

#### Hinweis:

Die Arbeitsweise des `CharacterFactory`-Objekts l�sst sich gut an den Ausgaben beobachten.

1. Variante: 

Der Pool mit intrinsischen `Character`-Objekten ist zu Beginn leer.

*Ausgabe*:

```cpp
CharacterFactory: Can't find this character, creating new one.
Character: Position (100, 0) with shared state [ Color: Green - Font: Arial]
CharacterFactory: Reusing existing character.
Character: Position (600, 200) with shared state [ Color: Green - Font: Arial]
CharacterFactory: Can't find this character, creating new one.
Character: Position (0, 500) with shared state [ Color: Blue - Font: Arial]
CharacterFactory: Can't find this character, creating new one.
Character: Position (300, 600) with shared state [ Color: Black - Font: Arial]
CharacterFactory: Reusing existing character.
Character: Position (600, 0) with shared state [ Color: Black - Font: Arial]
CharacterFactory: Can't find this character, creating new one.
Character: Position (300, 600) with shared state [ Color: Red - Font: Arial]
CharacterFactory: Reusing existing character.
Character: Position (100, 500) with shared state [ Color: Green - Font: Arial]
CharacterFactory: Can't find this character, creating new one.
Character: Position (200, 200) with shared state [ Color: White - Font: Arial]
CharacterFactory: Can't find this character, creating new one.
Character: Position (200, 0) with shared state [ Color: Magenta - Font: Arial]
CharacterFactory: Reusing existing character.
Character: Position (600, 200) with shared state [ Color: Magenta - Font: Arial]
CharacterFactory: Reusing existing character.
Character: Position (100, 0) with shared state [ Color: Black - Font: Arial]
CharacterFactory: Reusing existing character.
Character: Position (600, 100) with shared state [ Color: Blue - Font: Arial]
CharacterFactory: Reusing existing character.
Character: Position (200, 600) with shared state [ Color: Red - Font: Arial]
CharacterFactory: Reusing existing character.
Character: Position (200, 0) with shared state [ Color: White - Font: Arial]
CharacterFactory: Reusing existing character.
Character: Position (600, 400) with shared state [ Color: Blue - Font: Arial]
```

Man gut an den Ausgaben erkennen, dass jedes `Character`-Objekt bei erster Verwendung neu angelegt wird.


2. Variante: 

Der Pool mit intrinsischen `Character`-Objekten ist zu Beginn mit einer Reihe von Objekten vorbelegt.

*Ausgabe*:

```cpp
CharacterFactory: Reusing existing character.
Character: Position (100, 0) with shared state [ Color: Green - Font: Arial]
CharacterFactory: Reusing existing character.
Character: Position (600, 200) with shared state [ Color: Green - Font: Arial]
CharacterFactory: Reusing existing character.
Character: Position (0, 500) with shared state [ Color: Blue - Font: Arial]
CharacterFactory: Can't find this character, creating new one.
Character: Position (300, 600) with shared state [ Color: Black - Font: Arial]
CharacterFactory: Reusing existing character.
Character: Position (600, 0) with shared state [ Color: Black - Font: Arial]
CharacterFactory: Reusing existing character.
Character: Position (300, 600) with shared state [ Color: Red - Font: Arial]
CharacterFactory: Reusing existing character.
Character: Position (100, 500) with shared state [ Color: Green - Font: Arial]
CharacterFactory: Can't find this character, creating new one.
Character: Position (200, 200) with shared state [ Color: White - Font: Arial]
CharacterFactory: Can't find this character, creating new one.
Character: Position (200, 0) with shared state [ Color: Magenta - Font: Arial]
CharacterFactory: Reusing existing character.
Character: Position (600, 200) with shared state [ Color: Magenta - Font: Arial]
CharacterFactory: Reusing existing character.
Character: Position (100, 0) with shared state [ Color: Black - Font: Arial]
CharacterFactory: Reusing existing character.
Character: Position (600, 100) with shared state [ Color: Blue - Font: Arial]
CharacterFactory: Reusing existing character.
Character: Position (200, 600) with shared state [ Color: Red - Font: Arial]
CharacterFactory: Reusing existing character.
Character: Position (200, 0) with shared state [ Color: White - Font: Arial]
CharacterFactory: Reusing existing character.
Character: Position (600, 400) with shared state [ Color: Blue - Font: Arial]
```

Man gut an den Ausgaben erkennen, dass vorhandene `Character`-Objekte bei erster Verwendung wieder
verwendet werden.

#### Literaturhinweis

Die Anregung zum diesem Beispiel finden Sie unter

[The Flyweight Pattern](https://medium.com/@mlbors/the-flyweight-pattern-ff4ef2a8f377)


#### Quellcode

[Siehe hier](../Semigraphics.cpp)

---

[Zur�ck](Readme.md)

---