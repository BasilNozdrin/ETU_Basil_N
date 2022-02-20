create table Shop
(
    id_shop int not null primary key AUTO_INCREMENT,
  
    class enum ('1', '2', '3'),
    name_shop varchar(30)
);

create table Base
(
    name_base varchar(20) not null primary key
);

create table Product
(
    code_ int not null primary key AUTO_INCREMENT,
  
    name_product varchar(15),
    sort varchar(15)
);

create table Section
(
  
    id_section int not null primary key AUTO_INCREMENT,
    id_shop int not null,
  
    name_section varchar(20),
    surname_head varchar(20),
    name_head varchar(15),
    midname_head varchar(15) null,
    FOREIGN KEY (id_shop) REFERENCES Shop(id_shop)
);

create table Sale
(
    id_sale serial not null primary key,
    id_section int not null,
    id_shop int not null,
    code_ int not null,
  
    price decimal(10,2) not null,
    count_sale int unsigned,
    FOREIGN KEY (id_section) REFERENCES Section(id_section),
    FOREIGN KEY (id_shop) REFERENCES Shop(id_shop),
    FOREIGN KEY (code_) REFERENCES Product(code_)
);
  
  
create table Buy
(
    id_buy serial not null,
    id_shop int not null,
    id_section int not null,
    name_base varchar(20),
    code_ int not null,
  
    price_buy decimal(10,2),
    count_buy int unsigned,
    data_buy date,
    FOREIGN KEY (id_shop) REFERENCES Shop(id_shop),
    FOREIGN KEY (id_section) REFERENCES Section(id_section),
    FOREIGN KEY (name_base) REFERENCES Base(name_base),
    FOREIGN KEY (code_) REFERENCES Product(code_)
);

create table Product_in_shop
(
    id_product_in_shop serial not null primary key,
    id_shop int not null,
    id_section int not null,
    code_ int not null,
  
    price_in_section decimal(10,2),
    count_in_shop int unsigned,
    FOREIGN KEY (id_shop) REFERENCES Shop(id_shop),
    FOREIGN KEY (id_section) REFERENCES Section(id_section),
    FOREIGN KEY (code_) REFERENCES Product(code_)
);

create table Product_in_base
(
    id_product_in_base serial not null primary key,
    name_base varchar(20),
    code_ int not null,
  
    price_in_base decimal(10,2),
    count_in_base int unsigned,  
    FOREIGN KEY (name_base) REFERENCES Base(name_base),
    FOREIGN KEY (code_) REFERENCES Product(code_)
);


INSERT INTO Shop (class, name_shop) VALUES (1, 'Dixi');
INSERT INTO Shop (class, name_shop) VALUES (1, 'Pyaterochka');
INSERT INTO Shop (class, name_shop) VALUES (2, 'Perecresrok');
INSERT INTO Shop (class, name_shop) VALUES (2, 'Karusel');
INSERT INTO Shop (class, name_shop) VALUES (3, 'Real');

INSERT INTO Base (name_base) VALUES ('1');
INSERT INTO Base (name_base) VALUES ('2');
INSERT INTO Base (name_base) VALUES ('3');
INSERT INTO Base (name_base) VALUES ('4');
INSERT INTO Base (name_base) VALUES ('5');

INSERT INTO Product (code_, name_product, sort) VALUES (111, 'Chicken', 'SORT1');
INSERT INTO Product (code_, name_product, sort) VALUES (211, 'Lastochka', 'SORT2');
INSERT INTO Product (code_, name_product, sort) VALUES (121, 'Pork', 'SORT1');
INSERT INTO Product (code_, name_product, sort) VALUES (311, 'Tomato', 'SORT3');
INSERT INTO Product (code_, name_product, sort) VALUES (331, 'Carrot', 'SORT3');
INSERT INTO Product (code_, name_product, sort) VALUES (112, 'Turkey', 'SORT1');
INSERT INTO Product (code_, name_product, sort) VALUES (113, 'Chicken', 'SORT3');
INSERT INTO Product (code_, name_product, sort) VALUES (212, 'Step', 'SORT2');
INSERT INTO Product (code_, name_product, sort) VALUES (213, 'Rafaello', 'SORT1');

INSERT INTO Product (code_, name_product, sort) VALUES (200, 'Romashka', 'SORT3');
INSERT INTO Product (code_, name_product, sort) VALUES (220, '35', 'SORT2');
INSERT INTO Product (code_, name_product, sort) VALUES (100, 'Turkey', 'SORT3');


INSERT INTO Section (id_section, id_shop, name_section, surname_head, name_head, midname_head) VALUES (1, 1, 'Meat', 'Ivanova', 'Anna', 'Ivanovna');

 INSERT INTO Section (id_section, id_shop, name_section, surname_head, name_head, midname_head) VALUES (2, 1, 'Sweets', 'Petrov', 'Egor', 'Alexandrovich');

INSERT INTO Section (id_section, id_shop, name_section, surname_head, name_head, midname_head) VALUES (3, 2, 'Meat', 'Larin', 'Michil', 'Sergeevich');

INSERT INTO Section (id_section, id_shop, name_section, surname_head, name_head, midname_head) VALUES (4, 2, 'Sweets', 'Sidorova', 'Alina', 'Alekseevna');

INSERT INTO Section (id_section, id_shop, name_section, surname_head, midname_head) VALUES (5, 4, 'Meat', 'Logvinenko', 'Svetlana');


INSERT INTO Sale (id_section, id_shop, code_, price, count_sale) VALUES (1, 1, 112, 10.9, 2);

INSERT INTO Sale (id_section, id_shop, code_, price, count_sale) VALUES (1, 1, 100, 100, 3);
 
INSERT INTO Sale (id_section, id_shop, code_, price, count_sale) VALUES (1, 1, 111, 120.88, 1);
 
INSERT INTO Sale (id_section, id_shop, code_, price, count_sale) VALUES (2, 1, 200, 53.5, 1);
 
INSERT INTO Sale (id_section, id_shop, code_, price, count_sale) VALUES (2, 1, 220, 49.1, 2);



INSERT INTO Buy (id_buy, id_shop, id_section, name_base, code_, price_buy, count_buy, data_buy) VALUES (1, 1, 1, '1', 111, 10.8, 2, '2021-01-08');

INSERT INTO Buy (id_buy, id_shop, id_section, name_base, code_, price_buy, count_buy, data_buy) VALUES (2, 2, 1, '1', 112, 22.8, 1, '2021-02-18');

INSERT INTO Buy (id_buy, id_shop, id_section, name_base, code_, price_buy, count_buy, data_buy) VALUES (3, 3, 1, '1', 113, 33.3, 2, '2021-03-05');

INSERT INTO Buy (id_buy, id_shop, id_section, name_base, code_, price_buy, count_buy, data_buy) VALUES (4, 4, 1, '1', 100, 44.78, 4, '2021-04-12');

INSERT INTO Buy (id_buy, id_shop, id_section, name_base, code_, price_buy, count_buy, data_buy) VALUES (5, 5, 1, '2', 200, 51.22, 1, '2021-05-29');



INSERT INTO Product_in_shop (id_product_in_shop, id_shop, id_section, code_, price_in_section, count_in_shop) VALUES (1, 1, 1, 111, 10.8, 20);

INSERT INTO Product_in_shop (id_product_in_shop, id_shop, id_section, code_, price_in_section, count_in_shop) VALUES (2, 1, 1, 112, 22.8, 10);

INSERT INTO Product_in_shop (id_product_in_shop, id_shop, id_section, code_, price_in_section, count_in_shop) VALUES (3, 2, 1, 113, 30.8, 15);

INSERT INTO Product_in_shop (id_product_in_shop, id_shop, id_section, code_, price_in_section, count_in_shop) VALUES (4, 2, 1, 112, 22.8, 11);

INSERT INTO Product_in_shop (id_product_in_shop, id_shop, id_section, code_, price_in_section, count_in_shop) VALUES (5, 3, 1, 113, 30.8, 10);

INSERT INTO Product_in_shop (id_product_in_shop, id_shop, id_section, code_, price_in_section, count_in_shop) VALUES (6, 1, 2, 212, 21.8, 15);

INSERT INTO Product_in_shop (id_product_in_shop, id_shop, id_section, code_, price_in_section, count_in_shop) VALUES (7, 1, 2, 213, 15.8, 10);



INSERT INTO Product_in_base (id_product_in_base, name_base, code_, price_in_base, count_in_base) VALUES (1, '1', 111, 5.8, 1000);

INSERT INTO Product_in_base (id_product_in_base, name_base, code_, price_in_base, count_in_base) VALUES (2, '1', 211, 25.8, 2000);

INSERT INTO Product_in_base (id_product_in_base, name_base, code_, price_in_base, count_in_base) VALUES (3, '1', 311, 35.8, 1500);

INSERT INTO Product_in_base (id_product_in_base, name_base, code_, price_in_base, count_in_base) VALUES (4, '1', 212, 3.8, 200);

INSERT INTO Product_in_base (id_product_in_base, name_base, code_, price_in_base, count_in_base) VALUES (5, '1', 213, 21.8, 1100);

INSERT INTO Product_in_base (id_product_in_base, name_base, code_, price_in_base, count_in_base) VALUES (6, '2', 212, 3.8, 200);

INSERT INTO Product_in_base (id_product_in_base, name_base, code_, price_in_base, count_in_base) VALUES (7, '2', 213, 21.8, 1100);
#"Какие продукты имеются на базе?"
SELECT name_base AS "Название базы", code_ AS "Штрих-код" FROM Product_in_base
WHERE name_base = '1';

#Какие отсутствующие товары может заказать магазин на базе
select code_ AS "Штрих-код", price_in_base AS "Цена", name_base AS "Название базы" from Product_in_base where code_ not in (select code_ from Product_in_shop) 
or code_ in (select code_ from Product_in_shop where count_in_shop = 0);

#Какие товары, и в каком количестве имеются в отделе магазина?  (результат для 1 магазина)
SELECT Product.name_product AS "Товары", Product.sort AS "Сорт", Section.name_section AS "Название отдела", Product_in_shop.count_in_shop AS "Количество" FROM Product_in_shop
INNER JOIN Section ON Section.id_section = Product_in_shop.id_section 
LEFT JOIN Product ON Product.code_ = Product_in_shop.code_
WHERE Product_in_shop.id_shop = 1
ORDER BY Section.name_section DESC;

#Список заведующих отделами магазина?
SELECT name_shop AS "Магазин", name_section AS "Название отдела", surname_head AS "Фамилия заведущего", name_head AS "Имя заведущего", midname_head AS "Отчество заведущего" FROM Section
INNER JOIN Shop ON Shop.id_shop = Section.id_shop
ORDER BY Shop.name_shop DESC;


#Суммарная стоимость товара в каждом отделе?
SELECT Section.name_section AS"Название отдела", Product_in_shop.id_section AS "Отдел", SUM(Product_in_shop.count_in_shop * Product_in_shop.price_in_section) AS "Суммарная стоимость товара" FROM Product_in_shop
INNER JOIN Section On Section.id_section = Product_in_shop.id_section
GROUP BY Product_in_shop.id_section;

#На каких базах, и в каких количествах есть товар нужного наименования?
SELECT code_ AS "Нужный товар", name_base AS "Название базы", count_in_base AS "Количество" FROM Product_in_base
WHERE (code_=111);
