% Knowledge
flight(antalya,izmir,2).
flight(antalya,erzincan,3).
flight(antalya,diyarbakir,4).

flight(ankara,izmir,6).
flight(ankara,istanbul,1).
flight(ankara,rize,5).
flight(ankara,van,4).
flight(ankara,diyarbakir,8).

flight(izmir,istanbul,2).
flight(izmir,ankara,6).
flight(izmir,antalya,2).

flight(istanbul,ankara,1).
flight(istanbul,rize,4).
flight(istanbul,izmir,2).

flight(rize,ankara,5).
flight(rize,istanbul,4).

flight(van,gaziantep,3).
flight(van,ankara,4).

flight(diyarbakir,antalya,4).
flight(diyarbakir,ankara,8).

flight(canakkale,erzincan,6).

flight(erzincan,antalya,3).

flight(erzincan,canakkale,6).

flight(gaziantep,van,3).


% Rules

% I know PDF gives X,Y,C but I prefer to giving meaningful names

% check if there is a flight from City Departure to City Arrive with Cost
route(Departure, Arrive, Cost) :-
    flight(Departure, Arrive, Cost).

% list all cities from Departure
route(Departure, Arrive, Cost) :-
    flight(Departure, City, Cost1),
    route(City, Arrive, Cost2),
    Cost is Cost1 + Cost2.




