# Observable Vector Container

#### Lösung

Wir haben es offensichtlich mit einem Anwendungsfall des  *Observer* Patterns zu tun.
Dieses Muster beschreibt ein Objekt, in der Regel als *Subject* bezeichnet,
das eine Liste abhängiger Objekte verwaltet, die als *Observer* bezeichnet werden,
und benachrichtigt diese über jegliche Zustandsänderung,
indem eine ihrer Methoden aufgerufen wird. Das folgende Klassendiagramm beschreibt eine mögliche
Musterimplementierung für das vorgeschlagene Problem:

<img src="dp_xxx.svg" width="700">

Abbildung 1: Schematische Darstellung des *Observer* Patterns im Anwendungsfall *Observable Vector Container*.


`Observable_vector` ist eine Klasse, die ein `std::vector`-Objekt umschließt und die geforderten Operationen
zur Verfügung stellt. Die Klasse enthält auch eine Liste von Zeigern auf `collection_observer`-Objekte.
Dies ist ein Basisklasse für Objekte, die über Statusänderungen eines `Observable_vector`-Objekts informiert werden möchten.
Die Klasse hat eine virtuelle Methode namens `collection_changed` mit einem
Argument des Typs `collection_changed_notification`, das nähere Informationen zu einer Zustandsänderung enthält.
Ändert sich der interne Status eines `Observable_vector`-Objekts, wird diese Methode 
bei allen registrierten Beobachtern aufgerufen.
Beobachter können dem `Observable_vector`-Objekt mit `add_observer` hinzugefügt werden
oder durch `remove_observer` von diesem wieder entfernt werden.



```cpp
To be done
```


#### Quellcode

[Siehe hier](../ObservableVectorContainer.cpp)

---

[Zurück](Readme.md)

---
