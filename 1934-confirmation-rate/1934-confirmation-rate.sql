# Write your MySQL query statement below
WITH RANKED AS (
    SELECT user_id,
    ROUND(
    SUM(
        CASE
            WHEN ACTION = 'confirmed' THEN 1
            ELSE 0
        END
    ) / COUNT(action), 2) AS confirmation_rate
    FROM Confirmations
    GROUP BY user_id
)
SELECT s.user_id, IF(c.confirmation_rate IS NOT NULL, c.confirmation_rate, 0) AS confirmation_rate
FROM Signups s
LEFT JOIN RANKED c
ON s.user_id = c.user_id