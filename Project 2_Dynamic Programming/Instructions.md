# Distance and Neighbouring Points

## 1. Task 1

To simply identify them each obstacle/point shall store a string ("A", "B", ... in example above), its coordinate (x, y) in the local coordinate system and its distance to the origin. Write a type definition for a structure with these four data as well as a pointer to the next list element as components/variables of the structure.  

## 2. Task 2

Write a function to calculate the Euclidian distance d of two obstacles/points P1 and P2 with coordinates (x1,y1) and (x2,y2) by the formula: d=sqrt((x1−x2)^2+(y1−y2)^2) and return d as function value.

## 3. Task 3
Write a function with a list of obstacles/points as first and one obstacle/point as second parameter calculating the neareast other obstacle/point to it and returning it as pointer. Take care that an obstacle/point does not return itself (distance 0) as well as that at least two obstacles/points need to exist, otherwise a null pointer nullptr shall be returned.

## 4. Task 4
Write a function with a list of obstacles/points sorted by distance from the origin of the coordinate system as first parameter and a pointer to a new obstacle/point as second parameter. In its body insert sorted this new obstacle/point into the list and return a pointer to the (new) head of the list of obstacles/points.

## 5. Task 5
Write a function to output formatted the list of obstacles/points (all numbers with six characters and two digits after decimal point). Beside the identifying string of the obstacle/point, its coordinates and its distance additionally the nearest neighbour obstacle/point to it shall be found and outputted (for each call the function from subtask 3; see example below).

## 6. Task 6
Write a function to delete the whole list of all obstacles/points completely on the heap.

## 7. Task 7
In a loop in function main arbitrary many of such obstacles/points shall be inputted and stored in a list sorted by distance in ascending order - call for each inputted obstacle/point the function from subtask 4. After the end of input output the list by calling the function from subtask 5. Last delete the whole list by calling the function from subtask 6.
