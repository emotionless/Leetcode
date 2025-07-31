# Write your MySQL query statement below
WITH Ranked AS (
    SELECT student_id, subject,
    FIRST_VALUE(score) OVER (PARTITION BY student_id, subject ORDER BY exam_date ASC) as first_score,
    LAST_VALUE(score) OVER (PARTITION BY student_id, subject ORDER BY exam_date ROWS BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING) as latest_score
    FROM Scores 
    -- GROUP BY student_id, subject
)
SELECT DISTINCT * FROM Ranked 
WHERE first_score <  latest_score
ORDER BY student_id, subject;
