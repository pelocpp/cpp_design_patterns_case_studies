# Pointer to Implementation (*Pimpl*)

#### Einleitung

*Pimpl* steht f�r *Pointer to Implementation* und ist eine Technik, die es erm�glicht,
die Implementierungsdetails von der Definition einer Schnittstelle zu trennen.
Dies hat den Vorteil, dass es das �ndern der Implementierung erm�glicht,
ohne dabei �nderungen an der Schnittstelle vorzunehmen.
Der gr��te Vorteil aber liegt darin, dass es die Notwendigkeit vermeidet,
in einem solchen Fall den betroffenen Quellcode neu zu kompilieren
Bibliotheken, die das *Pimpl*-Idiom beherzigen, k�nnen auf einfache Weise ausgetauscht werden,
wenn sich nur die Implementierungsdetails �ndern.


#### Aufgabe

Betrachten Sie die folgende Klasse und stellen Sie diese auf Basis des *Pimpl*-Idiom geeignet um.

Die Klasse repr�sentiert ein graphisches Steuerelement (*User Control*), das drei
Eigenschaften f�r Text, Gr��e und Sichtbarkeit besitzt. Jedes Mal,
wenn diese Eigenschaften ge�ndert werden, wird das Steuerelement neu gezeichnet.
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
nicht ohne Hilfestellung schaffen, so finden Sie im L�sungsteil eine entsprechende Verfahrensanweisung vor.

###### Zusatzaufgabe 1: Kopier- und Verschiebesemantik

Die urspr�ngliche Klasse `Control` war sowohl kopierbar als auch verschiebbar:

```cpp
Control ctrl;
ctrl.resize(100, 200);

Control c2 = ctrl; // copy: compiles
c2.show();

Control c3 = std::move(c2); // move: compiles
c3.hide();
```

Die umstrukturierte Klasse `Control` ist nur verschiebbar, nicht kopierbar.
Dies liegt darin begr�ndet, dass diese Variante der Klasse `Control` eine Instanzvariable
des Typs `std::unique_ptr<>` besitzt - und `std::unique_ptr<>`-Objekte sind bekanntlich nicht kopierbar.

Erstellen Sie eine weitere Variante der `Control`-Klasse, die sowohl
die Kopier- als auch die Verschiebesemantik unterst�tzt.

###### Zusatzaufgabe 2: Aufteilung des Projekts in mehrere Dateien

Die `ControlPimpl`-Klasse - also die *Pimpl*-Klasse - muss nicht zwingend in der Implementierungsdatei
der Ausgangsklasse definiert werden. Erg�nzen Sie ihr Projekt um zwei weitere Dateien `ControlPimpl.h` und `ControlPimpl.cpp`,
in denen Sie die Klasse `ControlPimpl` deklarieren und definieren.

---

Das *Pimpl*-Idiom erm�glicht das Ausblenden der internen Implementierung einer Klasse
vor den Benutzern dieser Klasse. Dies bietet mehrere Vorteile:

  * Eine unkomplizierte, �bersichtliche Schnittstelle f�r eine Klasse, die die Clients sehen.
  * �nderungen in der internen Implementierung wirken sich nicht auf die �ffentliche Schnittstelle aus!
    Eine Abw�rtskompatibilit�t f�r neuere Versionen einer Bibliothek ist gegeben (solange die �ffentliche Schnittstelle unver�ndert bleibt).
  * Clients einer Klasse, die das *Pimpl*-Idiom verwendetn, m�ssen nicht neu kompiliert werden,
    wenn �nderungen an der internen Implementierung vorgenommen werden.
    Dies f�hrt zu k�rzeren �bersetzungszeiten.
  * Die Header-Datei der Ausgangsklasse muss nicht die Header-Dateien f�r die im privaten Bereich verwendeten Typen und Funktionen enthalten.
    Dies f�hrt wiederum zu k�rzeren �bersetzungszeiten.

Es gibt aber auch einige Nachteile bei Betrachtung des *Pimpl*-Idioms:

  * Es gibt mehr Quellcode zum Schreiben und Pflegen.
  * Der Quellcode ist m�glicherweise weniger lesbar sein, da es eine zus�tzliche Indirektionsstufe gibt,
    so dass Implementierungsdetails in anderen Dateien nachgeschlagen werden m�ssen.
    In diesem Rezept ist die Definition der *Pimpl*-Klasse in derselben Quellcodedatei bereitgestellt wie
    die �ffentliche Klasse, aber in der Praxis k�nnte dies auch in getrennten Dateien erfolgen.
  * Prinzipiell gibt es einen geringf�gigen zus�tzlichen Laufzeitaufwand auf Grund der zus�tzlichen Indirektionsstufe.
    In der Praxis sollte dies aber keine Rolle spielen.
  * Dieser Ansatz funktioniert nicht mit `protected` Instanzvariablen,
    da diese f�r abgeleitete Klassen verf�gbar sein m�ssen.
  * Dieser Ansatz funktioniert nicht mit privaten, `virtual` deklarierten
    Methoden, die in der Klasse erscheinen m�ssen, entweder weil
    sie Methoden einer Basisklasse �berschreiben oder weil sie zum �berschreiben in einer abgeleiteten Klasse
    verf�gbar sein m�ssen.


###### Zusatzaufgabe 1



###### Zusatzaufgabe 2



#### L�sung

[Siehe hier](Solution.md)

---

[Zur�ck](../../../Readme.md)

---
