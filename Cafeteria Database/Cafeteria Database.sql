create schema CS3100Final;

use CS3100Final;

create table Students (
	StudentID varchar(6) NOT NULL,
    FirstName varchar(50) NOT NULL,
    LastName varchar(50) NOT NULL,
    Grade int(2) NOT NULL,
    MealStatus varchar(25),
    LastTransaction date,
    ParentID varchar(6),
    Primary key (StudentID),
    foreign key (ParentID) references Parents(ParentID)
    );

insert into Students (StudentID, FirstName, LastName, Grade, MealStatus, LastTransaction, ParentID)
	values
		('SGD5JD', 'Brage', 'Warwick', 03, 'Full', '2019-12-06', 'P30S6Z'),
        ('S6GNBB', 'Isa', 'Marmo', 03, 'Full', '2019-12-06', 'PT3AYY'),
        ('S2TBR0', 'Guntram', 'Quirke', 04, 'Free', '2019-12-06', 'PPFYEM'),
        ('S9X9Z2', 'Liam', 'George', 04, 'Reduced', '2019-12-06', 'PWJVMP'),
        ('SKBA5I', 'Gunda', 'Blau', 03, 'Full', '2019-12-05', 'P6YWS5'),
        ('SGWBSW', 'Wenzel', 'Leclair', 04, 'Full', '2019-12-06', 'P3JYFJ'),
        ('ST14ET', 'Larissa', 'Strat', 03, 'Free', '2019-12-06', 'PGOQ1G'),
        ('SU074O', 'Sylvester', 'Sly', 04, 'Reduced', '2019-12-06', 'PHNUQB');
    
Create table Parents (
	ParentID varchar(6) NOT NULL,
    FirstName varchar(50),
    LastName varchar(50) NOT NULL,
    AdressLine1 varchar(250),
    AdressLine2 varchar(250),
    City varchar(50),
    State varchar(15),
    Zip int(9),
    PhoneNumber varchar(15),
    Email varchar(50),
    Primary Key (ParentID)
    );

insert into Parents (ParentID, FirstName, LastName, AdressLine1, AdressLine2, City, State, Zip, PhoneNumber, Email) 
values 
    ('P30S6Z', 'Lisa', 'Warwick', '3404 Oral Lake Road', ' ', 'Eden Prairie', 'MN', 55344, '763-228-5330', 'warwickL@gmail.com'), 
    ('PT3AYY', 'Teresa', 'Marmo', '4574 Lowes Alley', ' ', 'Afton', 'MN', 55001, '740-336-3509', 'marmo@icloud.com'), 
    ('PPFYEM', 'Joop', 'Quirke', '2074 Murphy Court', 'Appt. 301', 'Eagan', 'MN', 55121, '952-215-6733', 'joop@gmail.com'), 
    ('PWJVMP', 'Presley', 'George', '3320 Eagle Lane', ' ', 'Bigfork', 'MN', 56628, '218-743-1140','pgeorge@outlook.com'), 
    ('P6YWS5', 'Cord', 'Blau', '5006 Hillcrest Circle', ' ', 'Crystal', 'MN', 55429, '763-513-1317', 'LEcordONblau@gmail.com'), 
    ('P3JYFJ', 'Faustino', 'Leclair', '3474 Lauel Lee', ' ', 'Burnsville', 'MN', 55337, '651-808-7526', 'faule@gmail.com'), 
    ('PGOQ1G', 'Garfield', 'Strat', '211 B Street', ' ', 'Maplewood', 'MN', 55119, '651-501-6840', 'gstrat@hotmail.com'), 
    ('PHNUQB', 'Benedict', 'Sly', '4930 Rocket Drive', ' ', 'Minneapolis', 'MN', 55406, '612-877-2881', 'slymanb@icloud.com');

create table Transactions (
	TransactionID varchar(7) NOT NULL,
    TransactionDate date,
    TransactionTime time,
    Amount int(4),
    StudentID varchar(6),
    MealID varchar(5),
    primary key (TransactionID),
    foreign Key (StudentID) references Students(StudentID),
    foreign Key (MealID) references Meals(MealID)
    );
    
insert into Transactions (TransactionID, TransactionDate, TransactionTime, Amount, StudentID, MealID)
values
	('3862475', '2019-12-06', '11:04:00', 0300, 'SGD5JD', 'XY520'),
    ('3238846', '2019-12-06', '11:14:00', 0300, 'S6GNBB', 'XY530'),
    ('5452304', '2019-12-06', '11:19:00', 0300, 'SGWBSW', 'XY540'),
    ('7623356', '2019-12-06', '11:42:00', 0040, 'S9X9Z2', 'XY550'),
    ('3935717', '2019-12-06', '11:43:00', 0040, 'SU074O', 'XY560'),
    ('7056589', '2019-12-06', '11:58:00', 0000, 'S2TBR0', 'XY520'),
    ('8297181', '2019-12-06', '12:11:00', 0000, 'ST14ET', 'XY530'),
    ('6329423', '2019-12-05', '12:21:00', 0300, 'SGD5JD', 'XY540'),
    ('5087640', '2019-12-05', '12:25:00', 0300, 'S6GNBB', 'XY550'),
    ('3627336', '2019-12-05', '12:27:00', 0300, 'SGWBSW', 'XY560'),
    ('7335663', '2019-12-05', '12:36:00', 0300, 'SKBA5I', 'XY520'),
    ('2336355', '2019-12-05', '12:42:00', 0040, 'S9X9Z2', 'XY530'),
    ('3830167', '2019-12-05', '12:44:00', 0040, 'SU074O', 'XY540'),
    ('9674887', '2019-12-05', '12:51:00', 0000, 'S2TBR0', 'XY550'),
    ('6551464', '2019-12-05', '12:54:00', 0000, 'ST14ET', 'XY560');
    
create table Payment (
	PaymentID varchar(6) NOT NULL,
    PaymentType varchar(25),
    PaymentAmount int(6),
    StudentID varchar(6),
    primary key (PaymentID),
    foreign key (StudentID) references Students(StudentID)
    );
    
insert into Payment (PaymentID, PaymentType, PaymentAmount, StudentID)
values
	('P2110', 'Cash', 000600, 'SGD5JD'),
    ('P7557', 'Cash', 000600, 'S6GNBB'),
    ('P2961', 'Card', 000600, 'SGWBSW'),
    ('P9066', 'Card', 000300, 'SKBA5I'),
    ('P3824', 'Cash', 000080, 'S9X9Z2'),
    ('P6726', 'Card', 000080, 'SU074O');

describe Payment;
    
create table Meals (
	MealID varchar(5) NOT NULL,
    MealDescription varchar(250),
    MealCost int(4),
    primary key (MealID)
    );

insert into Meals (MealID, MealDescription, MealCost)
values
	('XY520', 'Chicken Nuggets, Glazed Sweet Potatoes, Chilled Mixed Fruit, Choice of Milk', 0300),
    ('XY530', 'Bean Nachos, Corn Whole Kernel, Apple Slices w/ Cinnamon, Choice of Milk', 0300),
    ('XY540', 'PBJ w/ Cheesestick, Fresh Mango, Fresh Cucumber w/ Dip, Choice of Milk', 0300),
    ('XY550', 'Chili Beef With Beans, Cornbread, Chilled Pears, Choice of Milk', 0300),
    ('XY560', 'Deli Sandwich w/ Lettuce & Tomato, Mini Carrots, Fresh Grapes, Choice of Milk', 0300);