# Write your MySQL query statement below
SELECT prev.name  
FROM Employee AS prev
JOIN Employee AS curr
  ON prev.id = curr.managerId 
GROUP BY prev.id
HAVING COUNT(prev.id) >= 5;

-- #link:https://leetcode.com/problems/managers-with-at-least-5-direct-reports/