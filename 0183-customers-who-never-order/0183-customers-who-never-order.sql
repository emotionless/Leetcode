# Write your MySQL query statement below
SELECT name as Customers FROM Customers where id not in (SELECT customerId FROM Orders); 
