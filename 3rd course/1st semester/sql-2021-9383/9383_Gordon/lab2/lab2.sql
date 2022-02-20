create table Class
(
	number tinyint unsigned not null,
	letter varchar(1) not null,
	primary key (number, letter)
);

create table Pupil
(
	birth_certificate varchar(11) not null,
	number tinyint unsigned not null,
	letter varchar(1) not null,
	first_name varchar(15) not null,
	last_name varchar(15) not null,
	midname varchar(15) null,
	constraint birth_certificate
		unique (birth_certificate),
	constraint Pupil_ibfk_1
		foreign key (number, letter) references Class (number, letter),
	constraint primary key(birth_certificate)
);

create index number
	on Pupil (number, letter);

create table Subject
(
	id serial,
	name varchar(15) not null,
	constraint primary key(id)
);

create table Grades
(
	quarter tinyint unsigned not null,
	subject_id bigint unsigned,
	birth_certificate varchar(11) not null,
	grade tinyint unsigned null,
	primary key (quarter, subject_id, birth_certificate),
	constraint Grades_ibfk_1
		foreign key (subject_id) references Subject (id),
	constraint Grades_ibfk_2
		foreign key (birth_certificate) references Pupil (birth_certificate)
);

create index birth_certificate
	on Grades (birth_certificate);

create table Teacher
(
	passport int unsigned not null,
	first_name varchar(15) not null,
	last_name varchar(15) not null,
	midname varchar(15) null,
	constraint passport
		unique (passport),
	constraint primary key(passport)
);

create table Cabinet
(
	number smallint unsigned not null,
	passport int unsigned null,
	constraint number
		unique (number),
	constraint Cabinet_ibfk_1
		foreign key (passport) references Teacher (passport),
	constraint primary key(number)
);

create table Schedule
(
	lesson_number tinyint unsigned not null,
	data date not null,
	passport int unsigned not null,
	cabinet_number smallint unsigned null,
	class_number tinyint unsigned null,
	class_letter varchar(1) null,
	id_subject bigint unsigned not null,
	primary key (lesson_number, data, passport),
	constraint Schedule_ibfk_1
		foreign key (passport) references Teacher (passport),
	constraint Schedule_ibfk_2
		foreign key (Cabinet_number) references Cabinet (number),
	constraint Schedule_ibfk_3
		foreign key (Class_number, Class_letter) references Class (number, letter),
	constraint Schedule_ibfk_4
		foreign key (id_Subject) references Subject (id)
);

create index Class_number
	on Schedule (Class_number, Class_letter);

insert into Class values(1, 'A');
insert into Class values(2, 'C');
insert into Class values(3, 'A');
insert into Class values(3, 'B');
insert into Class values(4, 'A');

insert into Pupil values('IV-MU090200', 1, 'A', 'Dmitry', 'Gordon', 'Alexandrovich');
insert into Pupil values('I-ZI190200', 1, 'A', 'Egor', 'Lisauskas', 'Pavlovich');
insert into Pupil values('II-DA290200', 2, 'C', 'Pavel', 'Pikalov', 'Fedorovich');
insert into Pupil values('IV-NE390200', 2, 'C', 'Andrey', 'Belyakov', 'Alexandrovich');
insert into Pupil values('II-SI190200', 3, 'A', 'Pjotr', 'Shapovalov', null);
insert into Pupil values('II-NO190200', 3, 'A', 'Alexey', 'Tarannikov', null);
insert into Pupil values('I-TE190170', 3, 'B', 'Artem', 'Stepanov', null);
insert into Pupil values('I-MI190170', 3, 'B', 'Artem', 'Lukyanov', null);
insert into Pupil values('IV-KS190200', 4, 'A', 'Olesya', 'Malinina', null);
insert into Pupil values('IX-ZG190200', 4, 'A', 'Vadim', 'Efimov', null);

insert into Subject values(default, 'Physics');
insert into Subject values(default, 'Russian');
insert into Subject values(default, 'Math');
insert into Subject values(default, 'Informatics');
insert into Subject values(default, 'English');

insert into Teacher values(1000000000, 'Mihail', 'Blage', null);
insert into Teacher values(2000000000, 'Derevo', 'Koren', null);
insert into Teacher values(3000000000, 'Zolotoy', 'Gar', null);
insert into Teacher values(4000000000, 'Pjotr', 'Junior', null);
insert into Teacher values(4000000001, 'Michael', 'Jordan', null);

insert into Cabinet values(33, 4000000001);
insert into Cabinet values(314, 2000000000);
insert into Cabinet values(3, 3000000000);
insert into Cabinet values(1, 1000000000);
insert into Cabinet values(25, 4000000000);

insert into Grades values(1, 2, 'IV-MU090200', 2);
insert into Grades values(1, 2, 'I-ZI190200', 3);
insert into Grades values(1, 5, 'II-DA290200', 3);
insert into Grades values(1, 5, 'IV-NE390200', 3);
insert into Grades values(1, 4, 'II-SI190200', 4);
insert into Grades values(1, 4, 'II-NO190200', 5);
insert into Grades values(1, 1, 'I-TE190170', 5);
insert into Grades values(1, 1, 'I-MI190170', 5);
insert into Grades values(1, 4, 'IV-KS190200', 5);
insert into Grades values(1, 5, 'IX-ZG190200', 5);

insert into Schedule values(1, DATE '2021-11-15', 1000000000, 1, 1, 'A', 2);
insert into Schedule values(1, DATE '2021-11-15', 4000000001, 33, 4, 'A', 4);
insert into Schedule values(1, DATE '2021-11-16', 1000000000, 1, 4, 'A', 2);
insert into Schedule values(2, DATE '2021-11-16', 4000000001, 33, 1, 'A', 4);
insert into Schedule values(1, DATE '2021-11-17', 4000000000, 25, 2, 'C', 5);
insert into Schedule values(2, DATE '2021-11-17', 4000000001, 33, 3, 'B', 4);
insert into Schedule values(1, DATE '2021-11-18', 4000000001, 33, 3, 'A', 4);
insert into Schedule values(2, DATE '2021-11-18', 1000000000, 1, 3, 'A', 2);
insert into Schedule values(1, DATE '2021-11-19', 2000000000, 314, 2, 'C', 3);
insert into Schedule values(2, DATE '2021-11-19', 3000000000, 3, 3, 'B', 1);

select id_subject, name from Schedule INNER JOIN Subject ON Schedule.id_subject = Subject.id
where lesson_number = 1 and data = DATE'2021-11-15' and cabinet_number = 33;

select distinct class_number, class_letter, first_name, last_name, midname from Schedule INNER JOIN Teacher ON Schedule.passport = Teacher.passport
where class_number = 1 and class_letter = 'A';

select cabinet_number from Schedule
where data = DATE'2021-11-17' and class_number = 3 and class_letter = 'B' and lesson_number = 2;

select distinct class_number, class_letter from Schedule JOIN Subject ON id_subject = Subject.id INNER JOIN Teacher ON Schedule.passport = Teacher.passport
where name = 'Informatics' and last_name = 'Jordan'
ORDER BY class_number;

select lesson_number as Номер_урока, name AS Название_предмета, cabinet_number AS Кабинет, last_name AS Фамилия_учителя from Schedule JOIN Subject ON Schedule.id_subject = Subject.id
JOIN Teacher ON Schedule.passport = Teacher.passport
where data = DATE'2021-11-18' and class_number = 3 and class_letter ='A'
ORDER BY lesson_number;

select number, letter, count(number) AS Amount from Pupil
group by number, letter;