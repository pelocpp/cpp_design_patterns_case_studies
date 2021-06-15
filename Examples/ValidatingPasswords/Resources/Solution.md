# Passwortcheck

#### L�sung

Das hier beschriebene Problem ist ein typischer Anwendungsfall f�r das &ldquo;Decorator Pattern&rdquo; Entwurfsmuster.
Dieses Entwurfsmuster erm�glicht das Hinzuf�gen von Verhalten zu einem Objekt, ohne andere Objekte desselben Typs zu beeinflussen.
Das wird erreicht durch das Einh�llen eines Objekts in ein anderes Objekt.
Mehrere dieser so genannten *Decorator*-Objekte lassen sich miteinander verkn�pfen
(aufeinander stapeln), wobei jedes Mal eine neue Funktionalit�t hinzugef�gt wird.
In unserem  Beispiel besteht die Funktionalit�t darin,
dass ein bestimmtes Passwort eine oder mehrere bestimmte Anforderung(en) erf�llen muss.

Das folgende Klassendiagramm beschreibt das *Decorator Pattern* Entwurfsmuster
zum �berpr�fen von Kennw�rtern:

<img src="dp_password_validator.svg" width="700">

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
std::unique_ptr<PasswordValidator> validator {
    std::make_unique<SymbolPasswordValidator>(
        std::make_unique<CasePasswordValidator>(
            std::make_unique<DigitPasswordValidator>(
                std::make_unique<LengthValidator>(8))))
};

bool valid { validator->validate("IchBinEinPasswort") };
```


#### Quellcode

[Siehe hier](../ValidatingPasswords.cpp)

---

[Zur�ck](Readme.md)

---
