use CS3100Final;

-- Creation of views for the Nutrition Director's usage. Goal is to provide all the necessary data for
-- him/her to make analysese in order to increase efficiency and cut down on losses. These views display
-- the raw data collected in the tables in a more concise manner with all basic calculations done.
-- These views also ensure that the Nutrition Director has easy access to his/her data without needing
-- any database skills.

-- #1
CREATE VIEW StudentList AS

SELECT
	FirstName,
    LastName,
    Grade
FROM Students
ORDER BY FirstName,LastName,Grade;

-- #2
CREATE View MealStatus AS

SELECT
	MealStatus,
    FirstName,
    LastName
FROM Students
ORDER BY MealStatus, FirstName, LastName;

-- #3
CREATE VIEW DailyTransactions AS

SELECT
	t.TransactionDate,
    COUNT(m.MealID) AS 'Number of Meals Served',
    concat('$', round((SUM(t.Amount)/100), 2)) AS 'Sum of Meal Cost per Day'
FROM Meals m
INNER JOIN Transactions t
ON m.MealID = t.MealID
GROUP BY TransactionDate;

-- #4
CREATE VIEW FreeMealTotal AS

select
	count(m.MealID) as 'Total Free Meals',
    concat('$',round((sum(m.MealCost)/100),2)) as 'Free Meal Reimbursement Total',
    s.MealStatus
from Meals m
inner join Transactions t
on m.MealID = t.MealID
inner join Students s
on t.StudentID = s.StudentID
where MealStatus = 'Free';

-- #5
CREATE VIEW ReducedMealTotal AS

select
	count(m.MealID) as 'Total Reduced Meals',
    concat('$',round((sum(m.MealCost)/100),2)-round((sum(t.Amount)/100),2)) as 'Reduced Meal Reimbursement Total',
    s.MealStatus
from Meals m
left join Transactions t
on m.MealID = t.MealID
left join Students s
on t.StudentID = s.StudentID
where MealStatus = 'Reduced'
group by MealStatus;

-- #6
CREATE VIEW StudentPayments AS

select
	s.StudentID,
    concat(s.FirstName," ",s.LastName) as 'Student Name',
    t.TransactionID,
    t.TransactionDate,
    t.TransactionTime,
    concat('$',round(t.Amount/100,2)) as 'Transaction Amount'
from Transactions t
left join Students s
on t.StudentID = s.StudentID;

-- #7
CREATE VIEW StudentBalance AS

select
	concat(s.FirstName, ' ', s.LastName) as 'Name',
    concat('$', round((sum(t.Amount)/100), 2)) as 'AmountDue',
    concat('$', round((p.PaymentAmount/100), 2)) as 'AmountPaid'
from Students s
left join Transactions t
on s.StudentID = t.StudentID
left join Payment p
on t.StudentID = p.StudentID
group by s.StudentID;

-- Now that views have been created, here are examples of how the data will be displayed for each view.

-- #1
select *
from StudentList;

-- #2
select *
from MealStatus;

-- #3
select *
from DailyTransactions;

-- #4
select *
from FreeMealTotal;

-- #5
select *
from ReducedMealTotal;

-- #6
select *
from StudentPayments;

-- #7
select *
from StudentBalance;