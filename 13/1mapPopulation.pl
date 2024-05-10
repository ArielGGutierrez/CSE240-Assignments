/* Facts */
edge(washington, oregon).
edge(washington, idaho).
edge(oregon, idaho).
edge(oregon, california).
edge(california, nevada).
edge(idaho, montana).
edge(idaho, wyoming).
edge(idaho, nevada).
edge(idaho, utah).
edge(nevada, utah).
edge(nevada, arizona).
edge(arizona, new_mexico).
edge(montana, north_dakota).
edge(montana, south_dakota).
edge(montana, wyoming).
edge(wyoming, south_dakota).
edge(wyoming, nebraska).
edge(wyoming, colorado).
edge(colorado, nebraska).
edge(colorado, kansas).
edge(colorado, oklahoma).
edge(new_mexico, oklahoma).
edge(new_mexico, texas).
edge(north_dakota, south_dakota).
edge(north_dakota, minnesota).
edge(south_dakota, minnesota).
edge(south_dakota, iowa).
edge(south_dakota, nebraska).
edge(nebraska, kansas).
edge(nebraska, iowa).
edge(nebraska, missouri).
edge(kansas, missouri).
edge(kansas, oklahoma).
edge(oklahoma, missouri).
edge(oklahoma, texas).
edge(minnesota, iowa).
edge(iowa, missouri).

color(washington, red).
color(oregon, purple).
color(california, green).
color(idaho, green).
color(nevada, red).
color(utah, green). /* Should be purple */
color(arizona, yellow).
color(montana, yellow).
color(wyoming, red).
color(colorado, green).
color(new_mexico, red).
color(north_dakota, green).
color(south_dakota, purple).
color(nebraska, yellow).
color(kansas, red).
color(oklahoma, yellow).
color(texas, green).
color(minnesota, red).
color(iowa, green).
color(missouri, purple).

population(washington, 7).
population(oregon, 4).
population(california, 39).
population(idaho, 2).
population(nevada, 3).
population(utah, 3).
population(arizona, 8).
population(montana, 1).
population(wyoming, 1).
population(colorado, 6).
population(new_mexico, 2).
population(north_dakota, 1).
population(south_dakota, 1).
population(nebraska, 2).
population(kansas, 3).
population(oklahoma, 4).
population(texas, 30).
population(minnesota, 6).
population(iowa, 3).
population(missouri, 6).

/* Rules */
adjacent(X,Y) :- 
    edge(X, Y);
    edge(Y, X).

miscolor(S1, S2, Color1) :- 
    adjacent(S1, S2),
    color(S1, Color1),
    color(S2, Color1).

totalpopulation([],0).
totalpopulation([[_|Population]|Tail], Total) :-
    totalpopulation(Tail, Total1),
    Total is Total1+Population.

q1 :-
    miscolor(S1, S2, Color1),  
    write(S1), write(' and '), write(S2),  
    write(' have conflict color: '), write(Color1), nl, 
    totalpopulation([[washington, 7],
                      [oregon, 4],
                      [california, 39],
                      [idaho, 2],
                      [nevada, 3],
                      [utah, 3],
                      [arizona, 8],
                      [montana, 1],
                      [wyoming, 1],
                      [colorado, 6],
                      [new_mexico, 2],
                      [north_dakota, 1],
                      [south_dakota, 1],
                      [nebraska, 2],
                      [kansas, 3],
                      [oklahoma, 4],
                      [texas, 30],
                      [minnesota, 6],
                      [iowa, 3],
                      [missouri, 6]],
                    Total),  
    write('Total = '),  
    write(Total), nl.
