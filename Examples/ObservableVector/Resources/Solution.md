# Observable Vector Container

#### L�sung

Wir haben es offensichtlich mit einem Anwendungsfall des *Observer* Patterns zu tun.
Dieses Muster beschreibt ein Objekt, in der Regel als *Subject* bezeichnet,
das eine Liste abh�ngiger Objekte verwaltet, die als *Observer* bezeichnet werden,
und benachrichtigt diese �ber jegliche Zustands�nderung,
indem eine ihrer Methoden aufgerufen wird. Das folgende Klassendiagramm beschreibt eine m�gliche
Musterimplementierung f�r das vorgeschlagene Problem:

<img src="dp_observable_vector.svg" width="800">

Abbildung 1: Schematische Darstellung des *Observer* Patterns im Anwendungsfall *Observable Vector Container*.


`ObservableVector` ist eine Klasse, die ein `std::vector`-Objekt umschlie�t und die geforderten Operationen
zur Verf�gung stellt. Die Klasse enth�lt auch eine Liste von Zeigern auf `CollectionObserver`-Objekte.
Dies ist ein Basisklasse f�r Objekte, die �ber Status�nderungen eines `ObservableVector`-Objekts informiert werden m�chten.
Die Klasse hat eine virtuelle Methode namens `collectionChanged` mit einem
Argument des Typs `CollectionChangeNotification`, das n�here Informationen zu einer Zustands�nderung enth�lt.
�ndert sich der interne Status eines `ObservableVector`-Objekts, wird diese Methode 
bei allen registrierten Beobachtern aufgerufen.
Beobachter k�nnen dem `ObservableVector`-Objekt mit `addObserver` hinzugef�gt werden
oder durch `removeObserver` von diesem wieder entfernt werden.


```cpp
ObservableVector<int> v;
Observer o;
v.addObserver(&o);
v.push_back(1);
v.push_back(2);
v.pop_back();
v.clear();
v.removeObserver(&o);
v.push_back(3);
v.push_back(4);
v.addObserver(&o);
ObservableVector<int> v2{ 1,2,3 };
v = v2;
v = ObservableVector<int>{ 7,8,9 };
```

*Ausgabe*: 

```cpp
action: add, indexes: 0
action: add, indexes: 1
action: remove, indexes: 2
action: clear
action: assign
action: assign
```


#### Quellcode

[Siehe hier](../ObservableVectorContainer.cpp)

---

[Zur�ck](Readme.md)

---
