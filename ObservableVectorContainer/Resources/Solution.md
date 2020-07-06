# Observable Vector Container

#### L�sung

Wir haben es offensichtlich mit einem Anwendungsfall des  *Observer* Patterns zu tun.
Dieses Muster beschreibt ein Objekt, in der Regel als *Subject* bezeichnet,
das eine Liste abh�ngiger Objekte verwaltet, die als *Observer* bezeichnet werden,
und benachrichtigt diese �ber jegliche Zustands�nderung,
indem eine ihrer Methoden aufgerufen wird. Das folgende Klassendiagramm beschreibt eine m�gliche
Musterimplementierung f�r das vorgeschlagene Problem:

<img src="dp_xxx.svg" width="700">

Abbildung 1: Schematische Darstellung des *Observer* Patterns im Anwendungsfall *Observable Vector Container*.


`Observable_vector` ist eine Klasse, die ein `std::vector`-Objekt umschlie�t und die geforderten Operationen
zur Verf�gung stellt. Die Klasse enth�lt auch eine Liste von Zeigern auf `collection_observer`-Objekte.
Dies ist ein Basisklasse f�r Objekte, die �ber Status�nderungen eines `Observable_vector`-Objekts informiert werden m�chten.
Die Klasse hat eine virtuelle Methode namens `collection_changed` mit einem
Argument des Typs `collection_changed_notification`, das n�here Informationen zu einer Zustands�nderung enth�lt.
�ndert sich der interne Status eines `Observable_vector`-Objekts, wird diese Methode 
bei allen registrierten Beobachtern aufgerufen.
Beobachter k�nnen dem `Observable_vector`-Objekt mit `add_observer` hinzugef�gt werden
oder durch `remove_observer` von diesem wieder entfernt werden.



```cpp
To be done
```


#### Quellcode

[Siehe hier](../ObservableVectorContainer.cpp)

---

[Zur�ck](Readme.md)

---
