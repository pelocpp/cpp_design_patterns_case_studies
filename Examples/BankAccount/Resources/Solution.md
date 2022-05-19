# Bankkonten eines Bankinstituts

#### Lösung

Das hier beschriebene Problem ist ein typischer Anwendungsfall des *Command Pattern* Entwurfsmusters.

Aus Grund von Demonstrationszwecken hat die `BankAccount`-Klasse
eine minimalistische Implementierung mit einem gewissen Startguthaben. 

Es gibt in dieser Klasse die beiden Methoden `deposit` und `withdraw`,
aber anstatt diese Methoden direkt zu verwenden,
erstellen wir eine separate Klasse `BankAccountCommand`, die als Backup von der abstrakten Klasse `Command`
ableitet.

In der Anwendung werden zwei `BankAccount`-Objekte angelegt
und simulieren die Überweisung von 300€ von einem Bankkonto auf das andere.

Jedes Kommando (`Command`) &ndash; sprich jedes `BankAccountCommand`-Objekt &ndash; bezieht sich auf ein bestimmtes Bankkonto,
sodass es weiß, auf welchem Konto es arbeiten soll.

Das folgende Klassendiagramm zeigt eine mögliche Implementierung des Entwurfsmuster für dieses Problem:

<img src="dp_bank_accounts.svg" width="800">

*Abbildung* 1: Schematische Darstellung des *Command* Patterns im Anwendungsfall &ldquo;*Bankkonten eines Bankinstituts*&rdquo;.

*Zusatzaufgabe*:

Betrachten Sie *Abbildung* 1 genau: Welches Manko erkennen Sie in der Klasse `Transactions`?
Wie könnten Sie dieses Manko beheben?

---

Im Quellcode finden Sie eine Umsetzung des Beispiels mit und ohne `Invoker`-Klasse vor.
Die etwas einachere Variante (also ohne `Invoker`-Klasse) sieht so aus:

*Beispiel*:

```cpp
BankAccount ba1{ 1000 };
BankAccount ba2{ 1000 };

std::vector<BankAccountCommand> transactions
{
    BankAccountCommand{ba1, BankAccountCommand::Action::withdraw, 300},
    BankAccountCommand{ba2, BankAccountCommand::Action::deposit, 300}
};

for (const auto& transaction : transactions) {
    transaction.execute();
}

std::cout << ba1.geBalance() << std::endl;
std::cout << ba2.geBalance() << std::endl;
```

*Ausgabe*:

```
700
1300
```

---

*Zusatzaufgabe*:

In der Klasse `Transactions` sollte der Vektor 

```cpp
std::vector<BankAccountCommand> m_transactions;
```

Elemente des Typs `Command` haben, also keine `BankAccountCommand`-Objekte.
Da die Klasse  `Command` abstrakt ist, müsste der Vektor Zeiger (Raw-Zeiger oder Smart Pointer) enthalten.

---

#### Quellcode

[Siehe hier](../BankAccount.cpp)

---

[Zurück](Readme.md)

---
