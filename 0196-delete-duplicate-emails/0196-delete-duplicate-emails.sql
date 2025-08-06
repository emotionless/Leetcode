# Write your MySQL query statement below
WITH RANKED AS (
    SELECT min(id) as id FROM Person GROUP BY EMAIL
)
DELETE FROM Person WHERE id NOT IN (select id FROM RANKED);