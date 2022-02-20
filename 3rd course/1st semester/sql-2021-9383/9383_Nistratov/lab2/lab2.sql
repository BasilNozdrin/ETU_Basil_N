CREATE DATABASE competition;
USE competition;

CREATE TABLE Team (
	team_name VARCHAR(20),
    team_city VARCHAR(50),
    place smallint unsigned NULL,
    coach VARCHAR(50),
  	PRIMARY KEY (team_name, team_city)
);

INSERT INTO Team (team_name, team_city, place, coach)
VALUES('Zenit', 'Saint-Petersburg', 5, 'Andreev A.A');

INSERT INTO Team (team_name, team_city, coach)
VALUES('PGA', 'BRAZIL', 'Pergo O');

INSERT INTO Team (team_name, team_city, place, coach)
VALUES('Barcelona', 'Spain', 1, 'Salami P.G');

INSERT INTO Team (team_name, team_city, place, coach)
VALUES('Lion', 'France', 2, 'Mercilavi G');

INSERT INTO Team (team_name, team_city, coach)
VALUES('Milan', 'France', 'Giorvano J.J');


CREATE TABLE Matchevent (
  event_id bigint unsigned AUTO_INCREMENT PRIMARY KEY,
  event_date DATE,
  price decimal(10, 2)
);

INSERT INTO Matchevent (event_date, price)
VALUES('2012-12-30', 1000.12);

INSERT INTO Matchevent (event_date, price)
VALUES('15.03.2015', 1500);

INSERT INTO Matchevent (event_date, price)
VALUES('18.07.2019', 700.99);

INSERT INTO Matchevent (event_date, price)
VALUES('15.06.2015', 550);

INSERT INTO Matchevent (event_date, price)
VALUES('18.11.2021', 9999.99);



CREATE TABLE Stadium (
	name VARCHAR(50) PRIMARY KEY,
    city VARCHAR(50),
  	size bigint unsigned
);

INSERT INTO Stadium (name, city, size)
VALUES('Power', 'Moscow', 10000);

INSERT INTO Stadium (name, city, size)
VALUES('California stadium', 'California', 3000);

INSERT INTO Stadium (name, city, size)
VALUES('LLSP', 'Tokyo', 100000);

INSERT INTO Stadium (name, city, size)
VALUES('Beaver Stadium', '	North America', 106572);

INSERT INTO Stadium (name, city, size)
VALUES('Camp Nou', 'Barcelona', 99354);

CREATE TABLE Player  (
    number smallint unsigned,
    team_name VARCHAR(20),
    team_city VARCHAR(50),
    name varchar(20),
    second_name varchar(20),
	patronymic varchar(20) NULL,
  	age tinyint unsigned,
  	amplua enum('Guardian', 'Attacker', 'Goalkeper'),
    PRIMARY KEY (number, team_name, team_city),
    FOREIGN KEY (team_name, team_city)  REFERENCES Team (team_name, team_city)
);

INSERT INTO Player (number, team_name, team_city, name, second_name, age, amplua)
VALUES (21, 'PGA', 'BRAZIL', 'Pedro', 'Aliaze', 24, 'Guardian');

INSERT INTO Player (number, team_name, team_city, name, second_name, age, amplua)
VALUES (1, 'PGA', 'BRAZIL', 'Chili', 'Anome', 29, 'Attacker');

INSERT INTO Player (number, team_name, team_city, name, second_name, patronymic, age, amplua)
VALUES (4, 'PGA', 'BRAZIL', 'Lamami', 'Salsa', 'Gevo', 18, 'Attacker');

INSERT INTO Player (number, team_name, team_city, name, second_name, age, amplua)
VALUES (11, 'Zenit', 'Saint-Petersburg', 'Andrey', 'Morozov', 25, 'Guardian');

INSERT INTO Player (number, team_name, team_city, name, second_name, age, amplua)
VALUES (3, 'Zenit', 'Saint-Petersburg', 'Sergey', 'Petrov', 18, 'Guardian');

INSERT INTO Player (number, team_name, team_city, name, second_name, patronymic, age, amplua)
VALUES (4, 'Zenit', 'Saint-Petersburg', 'Vladimir', 'Mashkov', 'Andreevich', 23, 'Goalkeper');

INSERT INTO Player (number, team_name, team_city, name, second_name, age, amplua)
VALUES (3, 'Barcelona', 'Spain', 'Barachelo', 'Si', 19, 'Attacker');

INSERT INTO Player (number, team_name, team_city, name, second_name, patronymic, age, amplua)
VALUES (4, 'Barcelona', 'Spain', 'Kero', 'Messo', 'El', 32, 'Goalkeper');


CREATE TABLE Goal  (
    ball_id SERIAL,
    event_id bigint unsigned,
    number smallint unsigned,
    team_name VARCHAR(20),
    team_city VARCHAR(50),
    PRIMARY KEY (ball_id, event_id, number, team_name, team_city),
    FOREIGN KEY (number, team_name, team_city)  REFERENCES Player (number, team_name, team_city),
  	FOREIGN KEY (event_id)  REFERENCES Matchevent (event_id)
);

INSERT INTO Goal (event_id, number, team_name, team_city)
VALUES (1, 21, 'PGA', 'BRAZIL');

INSERT INTO Goal (event_id, number, team_name, team_city)
VALUES (2, 3, 'Zenit', 'Saint-Petersburg');

INSERT INTO Goal (event_id, number, team_name, team_city)
VALUES (2, 3, 'Zenit', 'Saint-Petersburg');

INSERT INTO Goal (event_id, number, team_name, team_city)
VALUES (3, 3, 'Zenit', 'Saint-Petersburg');

INSERT INTO Goal (event_id, number, team_name, team_city)
VALUES (3, 3, 'Barcelona', 'Spain');

INSERT INTO Goal (event_id, number, team_name, team_city)
VALUES (3, 4, 'Barcelona', 'Spain');

CREATE TABLE Participant (
    participant_id SERIAL,
    team_name VARCHAR(20),
    team_city VARCHAR(50),
    event_id bigint unsigned,
    name VARCHAR(50),
    PRIMARY KEY (team_name, team_city, event_id, name),
    FOREIGN KEY (team_name, team_city)  REFERENCES Team (team_name, team_city),
  	FOREIGN KEY (event_id)  REFERENCES Matchevent (event_id),
    FOREIGN KEY (name)  REFERENCES Stadium (name)
);

INSERT INTO Participant (team_name, team_city, event_id, name)
VALUES ('PGA', 'BRAZIL', 1, 'LLSP');

INSERT INTO Participant (team_name, team_city, event_id, name)
VALUES ('Zenit', 'Saint-Petersburg', 1, 'LLSP');

INSERT INTO Participant (team_name, team_city, event_id, name)
VALUES ('Zenit', 'Saint-Petersburg', 2, 'Power');

INSERT INTO Participant (team_name, team_city, event_id, name)
VALUES ('Barcelona', 'Spain', 2, 'Power');

INSERT INTO Participant (team_name, team_city, event_id, name)
VALUES ('Zenit', 'Saint-Petersburg', 3, 'LLSP');

INSERT INTO Participant (team_name, team_city, event_id, name)
VALUES ('Barcelona', 'Spain', 3, 'LLSP');

# Даты встреч указанной команды, ее противники и счет?
SELECT event_date, team_name as enemy, (SELECT COUNT(*) from GOAL
WHERE team_name = 'Zenit' AND GOAL.event_id = participant.event_id
GROUP BY team_city,team_name) as Scored,
(SELECT COUNT(*) from GOAL
WHERE team_name != 'Zenit' AND GOAL.event_id = participant.event_id
GROUP BY team_city,team_name) as Missed
from participant
INNER JOIN matchevent m on participant.event_id = m.event_id
WHERE m.event_id in (SELECT event_id FROM participant z WHERE z.team_name = 'Zenit') AND team_name != 'Zenit';

# Номера и фамилии игроков команд, участвовавших во встрече, которая проходила в указанный день в указанном городе?
SELECT number, second_name FROM player
LEFT JOIN participant p ON player.team_name = p.team_name and player.team_city = p.team_city
LEFT JOIN matchevent m on p.event_id = m.event_id
LEFT JOIN stadium s on p.name = s.name
WHERE event_date = '2012-12-30' AND city = 'Tokyo';

#Цена, билета на матч между указанными командами?
SELECT price FROM matchevent
INNER JOIN participant p on matchevent.event_id = p.event_id
WHERE p.team_name = 'Zenit' and p.event_id in (SELECT event_id FROM participant WHERE team_name = 'Barcelona');

#Игрок, забивший в турнире наибольшее количество мячей?
SELECT * FROM player
INNER JOIN (SELECT * from goal
group by number,team_name, team_city
ORDER BY COUNT(*) DESC
LIMIT 1) as v ON player.number = v.number and player.team_city = v.team_city and player.team_name = v.team_name;

# Самый молодой участник турнира ?
SELECT * FROM Player
WHERE age = (
	SELECT MIN(age) FROM Player
);

#Команды, занявшие призовые места?
SELECT * from team
WHERE place BETWEEN 1 and 3;