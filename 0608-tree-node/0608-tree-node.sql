# Write your MySQL query statement below
SELECT id,
    CASE
        WHEN  p_id is NULL THEN 'Root'
        WHEN id IN (SELECT DISTINCT(p_id) FROM Tree WHERE p_id IS NOT NULL) THEN  'Inner'
        ELSE 'Leaf'
    END AS type
FROM Tree;