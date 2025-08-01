# Write your MySQL query statement below
SELECT transaction_date,
SUM(
    CASE
        WHEN  AMOUNT%2 = 1 THEN AMOUNT
        ELSE 0
    END 
) AS odd_sum,
SUM(
    CASE
        WHEN  AMOUNT%2 = 0 THEN AMOUNT
        ELSE 0
    END 
) AS even_sum
FROM transactions
GROUP BY transaction_date;