# Airport Arrivals and Departures

## Subtask 1
Time points at airports are always defined including a time zone.
Define a C++11 enumeration implemented by unsigned numbers with at least following eight time zones: ACT, CET, CST, EST, GMT, MSK, PST, UTC 

## Subtask 2
Define a C++11 enumeration with two values arrival and departure.

## Subtask 3
Define a class with name LocalTime. This class shall have following members:
* a private integer attribute minutes storing the minutes since midnight of a day (saving one variable instead of two variables for hour and minute).
* a private attribute for the time zone of enumeration data type defined in subtask 1.
* a public standard constructor initialising the minutes to -1 (for clock time yet not set) and the time zone to CET.
* a public overloaded constructor with three parameters for the hour, minute and a time zone with default parameter CET initialising the two attributes - minutes calculated  respectively (hint: in the body simply call the following member function).
* a public method with name set_time with an hour and a minute value as parameters calculating the minutes since midnight and assigning the resulting minutes value to the respective attribute. Check that hour and minute are given correctly otherwise write an error message and assign value -1.
* two public methods with names get_hour and get_minute without parameters calculating the hour or the minute and returning the result (hint: use integer division by 60 with rest).
* a public method with name is_valid without parameters returning false for a negative value for the minutes value and true otherwise.
