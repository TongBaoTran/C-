# Distance and Neighbouring Points

## 1. Task 1

Zur einfachen Identifizierung sollen für jedes Hindernis/jeden Punkt eine Zeichenkette ("A", "B", ... im Beispiel oben),  dessen Koordinaten (x, y)  im lokalen Koordinatensystem und der Abstand zum Ursprung gespeichert werden. Schreiben Sie die Typdefinition für eine Struktur mit diesen vier Daten sowie einem Zeiger auf das darauf folgende Listenelement als Komponenten/Variablen der Struktur.)/
To simply identify them each obstacle/point shall store a string ("A", "B", ... in example above), its coordinate (x, y) in the local coordinate system and its distance to the origin. Write a type definition for a structure with these four data as well as a pointer to the next list element as components/variables of the structure.  

Teilaufgabe 2/Subtask 2

Schreiben Sie eine Funktion zur Berechnung des euklidischen Abstands d zweier Hindernisse/Punkte P1 und P2 mit den Koordinaten (x1,y1) und (x2,y2) nach der Formel: d=(x1−x2)2+(y1−y2)2‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾√ und geben d als Funktionswert zurück./
Write a function to calculate the Euclidian distance d of two obstacles/points P1 and P2 with coordinates (x1,y1) and (x2,y2) by the formula: d=(x1−x2)2+(y1−y2)2‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾√ and return d as function value.

Teilaufgabe 3/Subtask 3

Schreiben Sie eine Funktion, die für eine Liste von Hindernissen/Punkten als ersten und ein Hindernis/einen Punkt als zweiten Parameter einen Zeiger auf das nach Abstand nächstliegende Hindernis/den nach Abstand nächstliegenden Punkt zurück liefert. Beachten Sie, dass ein Hindernis/Punkt nicht zu sich selbst (Abstand 0) zurück gegeben wird, sowie dass es mindestens zwei Hindernisse/Punkte geben muss, ansonsten soll der Nullzeiger nullptr zurück gegeben werden./
Write a function with a list of obstacles/points as first and one obstacle/point as second parameter calculating the neareast other obstacle/point to it and returning it as pointer. Take care that an obstacle/point does not return itself (distance 0) as well as that at least two obstacles/points need to exist, otherwise a null pointer nullptr shall be returned.

Teilaufgabe 4/Subtask 4

Schreiben Sie eine Funktion, die in eine nach Abstand vom Ursprung des Koordinatensystems aufsteigend sortierte Liste von Hindernissen/Punkten als ersten Parameter hat und als zweiten Parameter einen Zeiger auf ein neues Hindernis/einen neuen Punkt. Sortieren Sie im Rumpf dieses neue Hindernis/diesen neuen Punkt in die Liste ein und geben einen Zeiger auf den (neuen) Kopf der Liste von Hindernissen/Punkten zurück./
Write a function with a list of obstacles/points sorted by distance from the origin of the coordinate system as first parameter and a pointer to a new obstacle/point as second parameter. In its body insert sorted this new obstacle/point into the list and return a pointer to the (new) head of the list of obstacles/points.

Teilaufgabe 5/Subtask 5

Schreiben Sie eine Funktion, die die Liste aller Hindernisse/Punkte formatiert ausgibt (alle Zahlen mit sechs Zeichen und zwei Nachkommastellen). Bei dieser Ausgabe sollen neben der identifizierenden Zeichenkette des Hindernisses/Punkts, dessen Koordinaten und dessen Abstand zusätzlich das jeweils nach Abstand nächste Hindernis/der nach Abstand nächste Nachbarpunkt zu diesem bestimmt und ausgegeben werden (rufen Sie dazu jeweils die Funktion aus Teilaufgabe 3 auf; siehe Beispiel unten)./
Write a function to output formatted the list of obstacles/points (all numbers with six characters and two digits after decimal point). Beside the identifying string of the obstacle/point, its coordinates and its distance additionally the nearest neighbour obstacle/point to it shall be found and outputted (for each call the function from subtask 3; see example below).

Teilaufgabe/Subtask 6

Schreiben Sie eine Funktion, die die gesamte Liste aller Hindernisse/Punkte auf dem Heap löscht./
Write a function to delete the whole list of all obstacles/points completely on the heap.

Teilaufgabe 7/Subtask 7

In einer Schleife in der Funktion main sollen beliebig viele Hindernisse/Punkte eingegeben und aufsteigend nach Abstand einsortiert in einer Liste gespeichert werden - rufen Sie hierzu für jedes eingegebene Hindernis/jeden eingegebenen Punkt die Funktion aus Teilaufgabe 4 auf. Nach dem Eingabeende soll die nach Abstand sortierte Liste über einen Aufruf der in Teilaufgabe 5 definierten Funktion ausgegeben werden. Zuletzt soll die gesamte Liste wieder gelöscht werden über einen Aufruf der in Teilaufgabe 6 definierten Funktion./
In a loop in function main arbitrary many of such obstacles/points shall be inputted and stored in a list sorted by distance in ascending order - call for each inputted obstacle/point the function from subtask 4. After the end of input output the list by calling the function from subtask 5. Last delete the whole list by calling the function from subtask 6.
