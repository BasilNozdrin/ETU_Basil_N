CREATE DATABASE service_station;
USE service_station;


CREATE TABLE Auto (
    registration_number CHAR(10) PRIMARY KEY,
    brand VARCHAR(30),
    color VARCHAR(30) NULL,
    year_of_manufacture YEAR,
    owner_first_name VARCHAR(30),
    owner_last_name VARCHAR(30),
    owner_patronymic VARCHAR(30) NULL
);

INSERT INTO Auto (registration_number, brand, color, year_of_manufacture, owner_first_name, owner_last_name)
VALUES('0000000001', 'Nissan Leaf', 'White', 2001, 'Amy', 'Smith');

INSERT INTO Auto (registration_number, brand, color, year_of_manufacture, owner_first_name, owner_last_name)
VALUES('0004560241', 'Nissan Patrol', 'Red', 1998, 'Jan', 'Baker');

INSERT INTO Auto (registration_number, brand, color, year_of_manufacture, owner_first_name, owner_last_name)
VALUES('0032897400', 'Porsche 718', 'White', 1996, 'Joseph', 'North');

INSERT INTO Auto (registration_number, brand, color, year_of_manufacture, owner_first_name, owner_last_name)
VALUES('3439092342', 'Porsche 911 GT2 RS', 'Pink', 2006, 'Isaac', 'Kelly');

INSERT INTO Auto (registration_number, brand, color, year_of_manufacture, owner_first_name, owner_last_name)
VALUES('1235111111', 'Audi A3', 'Black', 2000, 'Sue', 'Gill');

INSERT INTO Auto (registration_number, brand, color, year_of_manufacture, owner_first_name, owner_last_name)
VALUES('0009873645', 'Volkswagen Passat', 'Black', 2000, 'Sue', 'Gill');

INSERT INTO Auto (registration_number, brand, color, year_of_manufacture, owner_first_name, owner_last_name, owner_patronymic)
VALUES('0012364726', 'Audi A6', 'White', 1995, 'Sergey', 'Ivanov', 'Ivanovich');

INSERT INTO Auto (registration_number, brand, color, year_of_manufacture, owner_first_name, owner_last_name, owner_patronymic)
VALUES('0918237342', 'Ford Focus', 'Black', 2007, 'Aleksey', 'Smirnov' , 'Aleksandrovich');

INSERT INTO Auto (registration_number, brand, color, year_of_manufacture, owner_first_name, owner_last_name, owner_patronymic)
VALUES('9998876363', 'Ford Fiesta', 'Blue', 2003, 'Ivan', 'Popov', 'Sergeevich');

INSERT INTO Auto (registration_number, brand, color, year_of_manufacture, owner_first_name, owner_last_name, owner_patronymic)
VALUES('1230000003', 'Volkswagen Golf', 'White', 1999, 'Kirill', 'Petrov' ,'Ivanovich');












CREATE TABLE Employee (
    employee_id SERIAL PRIMARY KEY,
    last_name VARCHAR(30),
    first_name VARCHAR(30),
    patronymic VARCHAR(30) NULL,
    speciality VARCHAR(50),
    experience FLOAT(3,1),
    grade TINYINT UNSIGNED 
);

INSERT INTO Employee (last_name, first_name, speciality, experience, grade)
VALUES('Berry', 'Jessica', 'Mechanic', 3.4, 3);

INSERT INTO Employee (last_name, first_name, speciality, experience, grade)
VALUES('Quinn', 'Kylie', 'Diagnostician', 2.9, 2);

INSERT INTO Employee (last_name, first_name, speciality, experience, grade)
VALUES('Paterson', 'Sonia', 'Electrician', 4.0, 2);

INSERT INTO Employee (last_name, first_name, speciality, experience, grade)
VALUES('Grant', 'Robert', 'Repairer', 2.0, 3);

INSERT INTO Employee (last_name, first_name, speciality, experience, grade)
VALUES('McLean', 'Alan', 'Assistant', 1.0, 1);

INSERT INTO Employee (last_name, first_name, patronymic, speciality, experience, grade)
VALUES('Ivanov', 'Ivan', 'Invanovich', 'Mechanic', 3.0, 5);












CREATE TABLE Customer (
    customer_id SERIAL PRIMARY KEY,
    last_name VARCHAR(30),
    first_name VARCHAR(30),
    patronymic VARCHAR(30) NULL,
    date_of_birth DATE,
    registration VARCHAR(50) 
);

INSERT INTO Customer (last_name, first_name, date_of_birth, registration)
VALUES('Kelly', 'Isaac', '1995-02-02', 'Rockaway township, New Jersey, USA');

INSERT INTO Customer (last_name, first_name, date_of_birth, registration)
VALUES('Smith', 'Amy', '1992-01-13', 'Starland country, Alberta, Canada');

INSERT INTO Customer (last_name, first_name, date_of_birth, registration)
VALUES('Baker', 'Jan', '1988-12-23', 'Garfield country, Montana, Canada');

INSERT INTO Customer (last_name, first_name, date_of_birth, registration)
VALUES('North', 'Joseph', '2000-07-22', 'West Yorkshire, United Kingdom');

INSERT INTO Customer (last_name, first_name, date_of_birth, registration)
VALUES('Gill', 'Sue', '1991-02-12', 'Greater London, United Kingdom');

INSERT INTO Customer (last_name, first_name, patronymic, date_of_birth, registration)
VALUES('Ivanov', 'Sergey', 'Ivanovich','2000-02-12', 'Moscow, Russia');

INSERT INTO Customer (last_name, first_name, patronymic, date_of_birth, registration)
VALUES('Smirnov', 'Aleksey', 'Aleksandrovich','1994-06-12', 'Saint Petersburg, Russia');

INSERT INTO Customer (last_name, first_name, patronymic, date_of_birth, registration)
VALUES('Popov', 'Ivan', 'Sergeevich','1991-04-13', 'Saint Petersburg, Russia');

INSERT INTO Customer (last_name, first_name, patronymic, date_of_birth, registration)
VALUES('Petrov', 'Kirill', 'Ivanovich','1991-11-22', 'Moscow, Russia');






CREATE TABLE RepairOrder (
    order_id SERIAL PRIMARY KEY,
    order_date DATE
);



INSERT INTO RepairOrder (order_date)
VALUES('2020-02-02');

INSERT INTO RepairOrder (order_date)
VALUES('2020-12-24');

INSERT INTO RepairOrder (order_date)
VALUES('2020-08-29');

INSERT INTO RepairOrder (order_date)
VALUES('2020-12-11');

INSERT INTO RepairOrder (order_date)
VALUES('2020-04-22');

INSERT INTO RepairOrder (order_date)
VALUES('2020-03-02');

INSERT INTO RepairOrder (order_date)
VALUES('2022-03-02');

INSERT INTO RepairOrder (order_date)
VALUES('2022-03-02');







CREATE TABLE Services  (
    title VARCHAR(100) PRIMARY KEY,
    price DEC(8,2) UNSIGNED
);

INSERT INTO Services (title, price)
VALUES('painting', 500.80);

INSERT INTO Services (title, price)
VALUES('engine repair', 999.99);

INSERT INTO Services (title, price)
VALUES('transmission repair', 300.50);

INSERT INTO Services (title, price)
VALUES('glass repair', 449.99);

INSERT INTO Services (title, price)
VALUES('cleaning', 200.00);












CREATE TABLE RepairWorks  (
    work_id SERIAL,
    title VARCHAR(100),
    employee_id BIGINT UNSIGNED,
    order_id BIGINT UNSIGNED,
    return_date DATE NULL,
    PRIMARY KEY (work_id, title, employee_id, order_id),
    FOREIGN KEY (title)  REFERENCES Services (title),
    FOREIGN KEY (employee_id)  REFERENCES Employee (employee_id),
    FOREIGN KEY (order_id)  REFERENCES RepairOrder (order_id)
);

INSERT INTO RepairWorks (title, employee_id, order_id)
VALUES('painting', 1, 1);

INSERT INTO RepairWorks (title, employee_id, order_id)
VALUES('cleaning', 3, 2);

INSERT INTO RepairWorks (title, employee_id, order_id)
VALUES('cleaning', 4, 3);

INSERT INTO RepairWorks (title, employee_id, order_id)
VALUES('cleaning', 1, 4);

INSERT INTO RepairWorks (title, employee_id, order_id)
VALUES('painting', 5, 5);

INSERT INTO RepairWorks (title, employee_id, order_id, return_date)
VALUES('glass repair', 4, 6, '2020-09-03');

INSERT INTO RepairWorks (title, employee_id, order_id, return_date)
VALUES('glass repair', 1, 5, '2020-05-11');

INSERT INTO RepairWorks (title, employee_id, order_id, return_date)
VALUES('glass repair', 2, 6, '2020-10-12');

INSERT INTO RepairWorks (title, employee_id, order_id, return_date)
VALUES('glass repair', 3, 7, '2020-07-01');












CREATE TABLE CustomerList (
    id SERIAL,
    registration_number CHAR(10),
    order_id BIGINT UNSIGNED,
    customer_id BIGINT UNSIGNED,
    title VARCHAR(100),

    PRIMARY KEY (id, registration_number, order_id, customer_id, title),

    FOREIGN KEY (registration_number)  REFERENCES Auto (registration_number),
    FOREIGN KEY (order_id)  REFERENCES RepairOrder (order_id),
    FOREIGN KEY (customer_id)  REFERENCES Customer (customer_id),
    FOREIGN KEY (title)  REFERENCES Services (title)
);



INSERT INTO CustomerList (registration_number, order_id, customer_id, title)
VALUES('0000000001',2,2,'painting');

INSERT INTO CustomerList (registration_number, order_id, customer_id, title)
VALUES('0000000001',2,2,'engine repair');

INSERT INTO CustomerList (registration_number, order_id, customer_id, title)
VALUES('0000000001',2,2,'cleaning');


INSERT INTO CustomerList (registration_number, order_id, customer_id, title)
VALUES('0004560241',1,2,'cleaning');

INSERT INTO CustomerList (registration_number, order_id, customer_id, title)
VALUES('0032897400',4,3,'cleaning');

INSERT INTO CustomerList (registration_number, order_id, customer_id, title)
VALUES('3439092342',1,4,'transmission repair');

INSERT INTO CustomerList (registration_number, order_id, customer_id, title)
VALUES('0918237342',1,3,'transmission repair');

INSERT INTO CustomerList (registration_number, order_id, customer_id, title)
VALUES('0012364726', 2, 2, 'cleaning');

INSERT INTO CustomerList (registration_number, order_id, customer_id, title)
VALUES('0918237342',3,3,'cleaning');

INSERT INTO CustomerList (registration_number, order_id, customer_id, title)
VALUES('0012364726',1,2,'cleaning');

INSERT INTO CustomerList (registration_number, order_id, customer_id, title)
VALUES('0012364726',5,4,'glass repair');

INSERT INTO CustomerList (registration_number, order_id, customer_id, title)
VALUES('3439092342',6,4,'glass repair');

INSERT INTO CustomerList (registration_number, order_id, customer_id, title)
VALUES('3439092342',7,4,'glass repair');
















# -- 1) фамилия, имя, отчество и адрес владельца автомобиля с данным номером государственной регистрации?
SELECT owner_first_name, owner_last_name, owner_patronymic, registration FROM Auto, Customer WHERE (
    registration_number = '0004560241' AND
    first_name = owner_first_name AND last_name = owner_last_name AND (
        patronymic = owner_patronymic OR (patronymic IS NULL AND owner_patronymic IS NULL)
    )
);



# -- 2) Марка и год выпуска автомобиля данного владельца?
SELECT brand, year_of_manufacture FROM Auto WHERE owner_first_name = 'Amy' AND owner_last_name = 'Smith';


# -- 3) Перечень устраненных неисправностей в автомобиле данного владельца?
SELECT title FROM CustomerList 
INNER JOIN Auto ON CustomerList.registration_number = Auto.registration_number
WHERE owner_first_name = 'Amy' AND owner_last_name='Smith';


# -- 4) фамилия, имя, отчество работника станции, устранявшего данную неисправность в автомобиле данного клиента, и время ее устранения?
SELECT Employee.first_name, Employee.last_name, Employee.patronymic, RepairWorks.return_date  FROM CustomerList 
INNER JOIN Customer ON Customer.customer_id = CustomerList.customer_id
INNER JOIN RepairWorks ON RepairWorks.order_id = CustomerList.order_id AND RepairWorks.title = 'glass repair'
INNER JOIN Employee ON Employee.employee_id = RepairWorks.employee_id
WHERE Customer.first_name = 'Joseph' AND Customer.last_name = 'North';



# -- 5) фамилия, имя, отчество клиентов, сдавших в ремонт автомобили с указанным типом неисправности?
SELECT first_name, last_name, patronymic FROM CustomerList
INNER JOIN Customer ON CustomerList.customer_id = Customer.customer_id
WHERE title = 'transmission repair'




