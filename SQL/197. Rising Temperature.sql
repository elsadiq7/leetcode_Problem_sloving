# Write your MySQL query statement below
#link:https://leetcode.com/problems/rising-temperature/?envType=study-plan-v2&envId=top-sql-50
SELECT curr.id AS Id
FROM Weather prev
JOIN Weather curr
  ON curr.recordDate = DATE_ADD(prev.recordDate, INTERVAL 1 DAY)
WHERE curr.temperature > prev.temperature;
