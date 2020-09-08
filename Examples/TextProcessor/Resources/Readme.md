# Ein Textprozessor

#### Aufgabe

Wir betrachten in dieser Aufgabe einen Textprozessor,
zumindest in Ans�tzen. Aufgabe dieses Textprozessor ist es,
unformatierten Text, also Zeichenketten entgegenzunehmen,
und diese formatiert auszugeben. Handelt es sich dabei um
eine Aufz�hlung, also mehrere Zeichenketten (Liste von Zeichenketten),
dann sollten diese nach der Ausgabe so in Erscheinung treten:

  * just
  * like
  * this

Wenn Sie �ber verschiedene popul�re Ausgabeformate nachdenken,
wissen Sie wahrscheinlich, dass 
Sie jedes Element einzeln mit einem zus�tzlichen Markup ausgeben m�ssen.
Bei Textformaten wie HTML oder LaTeX muss die Liste zus�tzlich
mit einem Anfangs-Tag gestartet und einem Ende-Tag beendet werden.
Man kann folglich Beobachtung machen, dass die Verarbeitung von Listen - 
in welchem Format auch immer - �hnlich erfolgt,
die Art und Weise in der konkreten Ausgabe aber unterschiedlich ist.
Jedes Ausgabeformat kann mit einer separaten Strategie behandelt werden.

#### Hinweise

##### Klasse `ListStrategy`:

Zur Strategie geh�ren drei Methoden `start`, `add` und `end`,
wie die eingangs gemachten �berlegungen nahe legen.
Definieren Sie eine Strategieklasse `ListStrategy`,
die diese drei Methoden mit den folgenden Schnittstellen beschreibt:

```cpp
void start(std::ostringstream&);
void addListItem(std::ostringstream&, const std::string& item);
void end(std::ostringstream&);
```

Die Ausgabe des Textprozessors soll dabei in ein Objekt des Typs
`ostringstream` erfolgen.

##### Klasse `HtmlListStrategy`:

Realisieren Sie eine Klasse `HtmlListStrategy`, die die Schnittstelle
`ListStrategy` implementiert. Beachten Sie dabei:
In HTML wird eine Liste mit dem Tag `<ul>` eingeleitet,
und mit dem Tag `</ul>` abgeschlossen.
Die einzelnen Elemente der Aufz�hlung sind in `<li>` bzw. `</li>` einzuschlie�en.

##### Klasse `MarkdownListStrategy`:

Realisieren Sie eine Klasse `MarkdownListStrategy`, die die Schnittstelle
`ListStrategy` implementiert. Beachten Sie dabei:
In Markdown kennen Listen keine Anfangs- und Endetag.
Die einzelnen Elemente der Aufz�hlung sind mit `__*` einzuleiten (2 f�hrende Blanks).

##### Klasse `TextProzessor`:

Die Klasse `TextProzessor` kann Ausgaben in verschiedenen Formaten t�tigen.
Zur Unterscheidung bietet sich ein Aufz�hlungstyp an:

```cpp
enum class OutputFormat
{
    Markdown,
    Html
};
```

Mindestens drei �ffentliche Methoden muss die Klasse `TextProzessor` besitzen:

```cpp
void setOutputFormat(const OutputFormat);
void appendList(const std::vector<std::string>&);
void print();
```

Mit `setOutputFormat` vermerkt sich das `TextProzessor`-Objekt intern,
in welchem Format die Textverarbeitung zu erfolgen hat.
Die Methoden `appendList` nimmt eine Liste von Zeichenketten entgegen,
die eine Aufz�hlung bilden. `print` schlie�lich gibt den Text
auf der Konsole aus. 

---

[Zur�ck](../../../Readme.md)

---
