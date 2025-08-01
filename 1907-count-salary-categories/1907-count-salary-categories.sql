# Write your MySQL query statement below
SELECT 'Low Salary' AS category, 
       COUNT(if(income<20000,1,null)) AS accounts_count
FROM Accounts

UNION ALL

SELECT 'Average Salary' AS category, 
       COUNT(if(income>=20000 AND income<=50000,1,null)) AS accounts_count
FROM Accounts

UNION ALL

SELECT 'High Salary' AS category, 
       COUNT(if(income>50000,1,null)) AS accounts_count
FROM Accounts


