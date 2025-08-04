# Write your MySQL query statement below
WITH RANKED AS (
    SELECT DISTINCT(p_id) FROM Tree WHERE p_id IS NOT NULL
)
SELECT t.id,
    CASE
        WHEN  t.p_id is NULL THEN 'Root'
        WHEN r.p_id is NOT NULL  THEN  'Inner'
        ELSE 'Leaf'
    END AS type
FROM Tree t
LEFT JOIN RANKED r ON t.id = r.p_id