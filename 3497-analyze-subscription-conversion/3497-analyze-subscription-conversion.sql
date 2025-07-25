# Write your MySQL query statement below
SELECT user_id,
    ROUND(
        SUM(CASE
            WHEN activity_type = 'free_trial' THEN activity_duration ELSE 0
        END) / SUM(CASE
            WHEN activity_type = 'free_trial' THEN 1 ELSE 0
        END), 2
    ) AS trial_avg_duration,
    ROUND(
        SUM(CASE
            WHEN activity_type = 'paid' THEN activity_duration ELSE 0
        END) / SUM(CASE
            WHEN activity_type = 'paid' THEN 1 ELSE 0
        END), 2
    ) AS paid_avg_duration
FROM UserActivity
WHERE user_id in (
    SELECT  user_id FROM UserActivity WHERE activity_type != 'cancelled' GROUP BY user_id HAVING COUNT(DISTINCT activity_type) = 2
) GROUP BY user_id;