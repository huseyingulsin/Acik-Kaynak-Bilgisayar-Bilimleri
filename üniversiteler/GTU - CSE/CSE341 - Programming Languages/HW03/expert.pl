% Knowledge
% student information
% student(id, course, handicapped)
student(1, [math, physics, chemistry], false).
student(2, [math, biology, chemistry], true).
student(3, [math, physics], false).
student(4, [math, chemistry], false).
student(5, [math], true).
student(6, [physics, chemistry], false).
student(7, [physics, biology], false).

% instructor info
% instructor(id, course, item)
instructor(gokturk, math, textbook).
instructor(ysa, biology, glass).
instructor(erdogan, physics, textbook).
instructor(yakup, chemistry, tube).

% room info
% room(id, capacity, item-list)
% ! occupency info is not included
room(z23, 20, [textbook, glass]).
room(z06, 20, [textbook, tube]).
room(z10, 10, [textbook, handicapped]).

% occupancy info
% occupancy(room-id, hour, course)
occupancy(z23, 1, math).
occupancy(z23, 2, math).
occupancy(z06, 3, biology).
occupancy(z06, 4, biology).
occupancy(z10, 5, physics).
occupancy(z10, 6, physics).
occupancy(z10, 7, chemistry).
occupancy(z10, 8, chemistry).


% course info
% course(id, instructor, capacity, hour, room, item list)
course(math, gokturk, 20, [1, 2], z23, [textbook]).
course(biology, ysa, 20, [3, 4], z06, [glass]).
course(physics, erdogan, 20, [5, 6], z10, [textbook, handicapped]).
course(chemistry, yakup, 20, [7, 8], z10, [tube]).


% Rules

% check if there is a conflict from occupancy
conflict(Course1, Course2) :-
    course(Course1, _, _, Hours1, _, _),
    course(Course2, _, _, Hours2, _, _),
    % check hours, if equals return false
    Hours1 = Hours2.


% check can given room assigned to given class
can_assign_course_room(Course, Room) :-
    course(Course, _, _, _, Room, _).

% check which room can assigned given class
which_room_can_assigned(Course) :-
    course(Course, _, _, _, Room, _),
    room(Room, _, _),
    format('~w can be assigned to ~w', [Course, Room]).

% check can student be assigned to given class
can_assign_student_course(Student, Course) :-
    student(Student, CourseList, _),
    member(Course, CourseList).

% find whcih class can a student be assigned
which_course_can_assigned(Student) :-
    student(Student, CourseList, _),
    member(Course, CourseList),
    course(Course, _, _, _, _, _),
    format('~w can be assigned to ~w', [Student, Course]).