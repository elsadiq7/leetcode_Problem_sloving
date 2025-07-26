# Write your MySQL query statement below
-- Find the maximum number that appears only once in the MyNumbers table
SELECT MAX(num) AS num
FROM (
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(*) = 1
) AS unique_numbers;
