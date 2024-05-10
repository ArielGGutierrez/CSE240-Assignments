/* Facts */
school(alex, cidse).
school(jennifer, ssebe).
school(michael, normal).

subjects(alex, computer_science).
subjects(alex, software_eng).
subjects(jennifer, construction_eng).
subjects(jennifer, environmental_eng).
subjects(michael, english).
subjects(michael, informatics).

course(computer_science, 'CSE240').
course(computer_science, 'CSE310').
course(computer_science, 'CSE445').
course(software_eng, 'SER222').
course(software_eng, 'SER321').
course(software_eng, 'SER322').
course(construction_eng, 'CNE210').
course(construction_eng, 'CNE213').
course(construction_eng, 'CNE243').
course(environmental_eng, 'EVE214').
course(environmental_eng, 'EVE261').
course(english, 'ENG101').
course(english, 'ENG102').
course(informatics, 'CPI111').
course(informatics, 'CPI211').
course(informatics, 'CPI311').

/* Rules */
info(Student, Info) :-
    school(Student, Info);
    subjects(Student, Info).

schedule(Student, Class) :-
    subjects(Student, Subject),
    course(Subject, Class).

q1 :-
    info(alex, Y),
    write('Info: '), write(Y), nl.

q2 :-
    schedule(jennifer, Z),
    write('Schedule: '), write(Z), nl.
