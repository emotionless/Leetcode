# Write your MySQL query statement below
SELECT DISTINCT(product_id) as product_id FROM Products where low_fats = 'Y' AND recyclable = 'Y';