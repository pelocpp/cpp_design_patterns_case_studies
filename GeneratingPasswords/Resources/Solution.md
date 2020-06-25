# Password-Generator

#### Lösung

Das hier beschriebene Problem ist ein typischer Anwendungsfall für das *Composite Pattern* Entwurfsmuster.

Dieses Entwurfsmuster setzt Objekte in Baumhierarchien zusammen und ermöglicht
auf diese Weise die Behandlung von Gruppen (oder Bäumen) von Objekten auf die gleiche Weise wie einzelne Objekte des gleichen Typs.
Das folgende Klassendiagramm
zeigt eine Hierarchie von Klassen, die zum Generieren von Kennwörtern verwendet werden können:

`password_generator` ist die Basisklasse und verfügt über mehrere virtuelle Methoden:
`generate` gibt eine neue zufällige Zeichenfolge zurück, `length` gibt die Länge
der Zeichenfolgen an, die zu erzeugen sind.
allowed_chars gibt eine Zeichenfolge mit allen Zeichen zurück, die zum Generieren verwendet werden dürfen.
add fügt einem zusammengesetzten Generator eine neue untergeordnete Komponente hinzu.
`basic_password_generator` wird von dieser Basisklasse abgeleitet
und definiert einen Generator mit einer Mindestlänge.
`digit_generator`, `symbol_generator`, `Upper_letter_generator`,
und `lower_letter_generator` werden von `basic_password_generator` und abgeleitet und
überschreiben allow_char, um Teilmengen von Zeichen zu definieren,
die zum Generieren von zufälligen Texten verwendet werden dürfen.






ALT

Dieses Entwurfsmuster ermöglicht das Hinzufügen von Verhalten zu einem Objekt, ohne andere Objekte desselben Typs zu beeinflussen.
Das wird erreicht durch das Einhüllen eines Objekts in ein anderes Objekt.
Mehrere dieser so genannten *Decorator* Objekte lassen sich miteinander verknüpfen
(aufeinander stapeln), wobei jedes Mal eine neue Funkionalität hinzugefügt wird.
In unserem  Beispiel besteht die Funktionalität darin,
dass ein bestimmtes Passwort eine oder mehrere bestimmte Anforderung(en) erfüllt.

Das folgende Klassendiagramm beschreibt das *Decorator Pattern* Entwurfsmuster
zum Überprüfen von Kennwörtern:

<img src="dp_password_validator.png" width="700">

Abbildung 1: Schematische Darstellung des *Decorator* Patterns im Anwendungsfall *Passwortcheck*.

`PasswordValidator` ist eine Basisklasse und verfügt über eine 
virtuelle Methode namens `validate` mit einem `std::string`-Parameter,
der ein zu überprüfendes Passwort entgegennimmt.
`LengthValidator` wird abgeleitet von `PasswordValidator`.
Diese Klasse implementiert die obligatorische Passwortanforderung bezüglich der Mindestlänge.
`PasswordValidatorDecorator` wird auch von `PasswordValidator` abgeleitet,
besitzt als Instanzvariable aber nur eine `PasswordValidator`-Referenz.
Die `validate`-Implementierung dieser Klasse delegiert den Aufruf einfach an `validate`-Methode
des referenzierten `PasswordValidator`-Objekts weiter.
Die anderen Klassen
`DigitPasswordValidator`, `SymbolPasswordValidator` und
`CasePasswordValidator` werden ebenfalls von der Klasse `PasswordValidatorDecorator` abgeleitet
und implementieren zusätzliche Anforderungen an die Passwortstärke.

Auf diese Weise können Sie ein `LengthValidator`-Objekt (Minimalanforderung)
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

[Zurück](Readme.md)

---
