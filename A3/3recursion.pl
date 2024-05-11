/* Rules */
foo(X, Y, Z) :-     /* Stopping Condition */
    Y =< 0,
    Z is X+1, !.
foo(X, Y, Z) :-     /* Stopping Condition */
    X =< 0,
    Z is Y+1, !.
foo(X, Y, Z) :-     /* Size-N Problem */
    X < Y,
    X1 is X-2,
    foo(X1, Y, Z1), /* Size-M Problem */
    Z is X+2+Z1.    /* Size-N Solution from Size-M */
foo(X, Y, Z) :-     /* Size-N Problem */
    X >= Y,
    Y1 is Y-3,
    foo(X, Y1, Z1), /* Size-M Problem */
    Z is Y+3+Z1.    /* Size-N Solution from Size-M */

q1 :-
    foo(5, 6, Total),
    write('Answer: '), write(Total), nl.
