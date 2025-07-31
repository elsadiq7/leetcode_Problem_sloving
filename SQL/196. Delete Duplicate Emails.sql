# Write your MySQL query statement below
DELETE P
from Person p 
Join (
     SELECT id
    FROM (
        SELECT 
            id,
            ROW_NUMBER() OVER (PARTITION BY email ORDER BY id ASC) AS rn
        FROM Person
    ) AS ranked
    WHERE rn != 1
)as to_delete  on p.id=to_delete.id;





--sol 2
DELETE p1 from Person p1 
Join Person p2  
on p1.email = p2.email AND p1.id > p2.id;  