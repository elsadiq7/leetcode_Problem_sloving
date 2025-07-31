# Write your MySQL query statement below
SELECT *
FROM Patients
WHERE
  conditions LIKE 'DIAB1%'         -- starts with DIAB1
  OR conditions LIKE '% DIAB1%'    -- middle word
  OR conditions LIKE '% DIAB1'     -- ends with DIAB1
