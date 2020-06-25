# Password-Generator

#### L�sung

Das hier beschriebene Problem ist ein typischer Anwendungsfall f�r das *Composite Pattern* Entwurfsmuster.

Dieses Entwurfsmuster setzt Objekte in Baumhierarchien zusammen und erm�glicht
auf diese Weise die Behandlung von Gruppen (oder B�umen) von Objekten auf die gleiche Weise wie einzelne Objekte des gleichen Typs.
Das folgende Klassendiagramm
zeigt eine Hierarchie von Klassen, die zum Generieren von Kennw�rtern verwendet werden k�nnen:

`password_generator` ist die Basisklasse und verf�gt �ber mehrere virtuelle Methoden:
`generate` gibt eine neue zuf�llige Zeichenfolge zur�ck, `length` gibt die L�nge
der Zeichenfolgen an, die zu erzeugen sind.
allowed_chars gibt eine Zeichenfolge mit allen Zeichen zur�ck, die zum Generieren verwendet werden d�rfen.
add f�gt einem zusammengesetzten Generator eine neue untergeordnete Komponente hinzu.
`basic_password_generator` wird von dieser Basisklasse abgeleitet
und definiert einen Generator mit einer Mindestl�nge.
`digit_generator`, `symbol_generator`, `Upper_letter_generator`,
und `lower_letter_generator` werden von `basic_password_generator` und abgeleitet und
�berschreiben allow_char, um Teilmengen von Zeichen zu definieren,
die zum Generieren von zuf�lligen Texten verwendet werden d�rfen.






ALT

Dieses Entwurfsmuster erm�glicht das Hinzuf�gen von Verhalten zu einem Objekt, ohne andere Objekte desselben Typs zu beeinflussen.
Das wird erreicht durch das Einh�llen eines Objekts in ein anderes Objekt.
Mehrere dieser so genannten *Decorator* Objekte lassen sich miteinander verkn�pfen
(aufeinander stapeln), wobei jedes Mal eine neue Funkionalit�t hinzugef�gt wird.
In unserem  Beispiel besteht die Funktionalit�t darin,
dass ein bestimmtes Passwort eine oder mehrere bestimmte Anforderung(en) erf�llt.

Das folgende Klassendiagramm beschreibt das *Decorator Pattern* Entwurfsmuster
zum �berpr�fen von Kennw�rtern:

<img src="dp_password_validator.png" width="700">

Abbildung 1: Schematische Darstellung des *Decorator* Patterns im Anwendungsfall *Passwortcheck*.

`PasswordValidator` ist eine Basisklasse und verf�gt �ber eine 
virtuelle Methode namens `validate` mit einem `std::string`-Parameter,
der ein zu �berpr�fendes Passwort entgegennimmt.
`LengthValidator` wird abgeleitet von `PasswordValidator`.
Diese Klasse implementiert die obligatorische Passwortanforderung bez�glich der Mindestl�nge.
`PasswordValidatorDecorator` wird auch von `PasswordValidator` abgeleitet,
besitzt als Instanzvariable aber nur eine `PasswordValidator`-Referenz.
Die `validate`-Implementierung dieser Klasse delegiert den Aufruf einfach an `validate`-Methode
des referenzierten `PasswordValidator`-Objekts weiter.
Die anderen Klassen
`DigitPasswordValidator`, `SymbolPasswordValidator` und
`CasePasswordValidator` werden ebenfalls von der Klasse `PasswordValidatorDecorator` abgeleitet
und implementieren zus�tzliche Anforderungen an die Passwortst�rke.

Auf diese Weise k�nnen Sie ein `LengthValidator`-Objekt (Minimalanforderung)
wie folgt "*dekorieren*":

```cpp
std::unique_ptr<SymbolPasswordValidator> validator =
    std::make_unique<SymbolPasswordValidator>(
        std::make_unique<CasePasswordValidator>(
            std::make_unique<DigitPasswordValidator>(
                std::make_unique<LengthValidator>(8))));

boolvalid = validator->validate("IchBinEinPasswort");
```


#### Quellcode

[Siehe hier](../ValidatingPasswords.cpp)

---

[Zur�ck](Readme.md)

---
