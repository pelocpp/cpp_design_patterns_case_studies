# Pointer to Implementation (*Pimpl*)

#### Einleitung

*Pimpl* steht für *Pointer to Implementation* und ist eine Technik, die es ermöglicht,
die Implementierungsdetails von der Definition einer Schnittstelle zu trennen.
Dies hat den Vorteil, dass es das Ändern der Implementierung ermöglicht,
ohne dabei Änderungen an der Schnittstelle vorzunehmen.
Der größte Vorteil aber liegt darin, dass es die Notwendigkeit vermeidet,
in einem solchen Fall den betroffenen Quellcode neu zu kompilieren
Bibliotheken, die das *Pimpl*-Idiom beherzigen, können auf einfache Weise ausgetauscht werden,
wenn sich nur die Implementierungsdetails ändern.


#### Aufgabe

Betrachten Sie die folgende Klasse und stellen Sie diese auf Basis des *Pimpl*-Idiom geeignet um.

Die Klasse repräsentiert ein graphisches Steuerelement (*User Control*), das drei
Eigenschaften für Text, Größe und Sichtbarkeit besitzt. Jedes Mal,
wenn diese Eigenschaften geändert werden, wird das Steuerelement neu gezeichnet.
In unserem Fall bedeutet "neu zeichnen", dass die entsprechenden Werte in der Konsole ausgegeben werden.

*Klasse* `Control` - Headerdatei:

```cpp
class Control {
private:
    // properties
    std::string m_text;
    int m_width = 0;
    int m_height = 0;
    bool m_visible = true;

    // private methods
    void draw();

public:
    // public class interface
    Control();
    void setText(std::string);
    void resize(const int width, const int height);
    void show();
    void hide();
};
```

*Klasse* `Control` - Implementierungsdatei:

```cpp
// implementation of private methods
void Control::draw()
{
    std::cout
        << "no pimple control "
        << std::endl
        << " visible: "
        << std::boolalpha
        << m_visible
        << std::noboolalpha
        << std::endl
        << " size: "
        << m_width
        << ", "
        << m_height
        << std::endl
        << " text: "
        << m_text
        << std::endl;
}

// implementation of public interface
Control::Control() : m_text(""), m_width(0), m_height(0), m_visible(true) {}

void Control::setText(std::string text)
{
    m_text = text;
    draw();
}

void Control::resize(const int width, const int height) {
    m_width = width;
    m_height = height;
    draw();
}

void Control::show()
{
    m_visible = true;
    draw();
}

void Control::hide() {
    m_visible = false;
    draw();
}
```

Sollten Sie die Umstrukturierung der Klasse `Control`
nicht ohne Hilfestellung schaffen, so finden Sie im Lösungsteil eine entsprechende Verfahrensanweisung vor.

---

Das *Pimpl*-Idiom ermöglicht das Ausblenden der internen Implementierung einer Klasse
vor den Benutzern dieser Klasse. Dies bietet mehrere Vorteile:

  * Eine unkomplizierte, übersichtliche Schnittstelle für eine Klasse, die die Clients sehen.
  * Änderungen in der internen Implementierung wirken sich nicht auf die öffentliche Schnittstelle aus!
    Eine Abwärtskompatibilität für neuere Versionen einer Bibliothek ist gegeben (solange die öffentliche Schnittstelle unverändert bleibt).
  * Clients einer Klasse, die das *Pimpl*-Idiom verwendetn, müssen nicht neu kompiliert werden,
    wenn Änderungen an der internen Implementierung vorgenommen werden.
    Dies führt zu kürzeren Übersetzungszeiten.
  * Die Header-Datei der Ausgangsklasse muss nicht die Header-Dateien für die im privaten Bereich verwendeten Typen und Funktionen enthalten.
    Dies führt wiederum zu kürzeren Übersetzungszeiten.

Es gibt aber auch einige Nachteile bei Betrachtung des *Pimpl*-Idioms:

  * Es gibt mehr Quellcode zum Schreiben und Pflegen.
  * Der Quellcode ist möglicherweise weniger lesbar sein, da es eine zusätzliche Indirektionsstufe gibt,
    so dass Implementierungsdetails in anderen Dateien nachgeschlagen werden müssen.
    In diesem Rezept ist die Definition der *Pimpl*-Klasse in derselben Quellcodedatei bereitgestellt wie
    die öffentliche Klasse, aber in der Praxis könnte dies auch in getrennten Dateien erfolgen.
  * Prinzipiell gibt es einen geringfügigen zusätzlichen Laufzeitaufwand auf Grund der zusätzlichen Indirektionsstufe.
    In der Praxis sollte dies aber keine Rolle spielen.
  * Dieser Ansatz funktioniert nicht mit `protected` Instanzvariablen,
    da diese für abgeleitete Klassen verfügbar sein müssen.
  * Dieser Ansatz funktioniert nicht mit privaten, `virtual` deklarierten
    Methoden, die in der Klasse erscheinen müssen, entweder weil
    sie Methoden einer Basisklasse überschreiben oder weil sie zum Überschreiben in einer abgeleiteten Klasse
    verfügbar sein müssen.


###### Zusatzaufgabe 1



###### Zusatzaufgabe 2



#### Lösung

[Siehe hier](Solution.md)

---

[Zurück](../../Readme.md)

---
