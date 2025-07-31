# Write your MySQL query statement below
WITH dedup AS (
    SELECT DISTINCT departmentId, salary
    FROM Employee
),
top_3 AS (
    SELECT 
        departmentId, 
        salary, 
        ROW_NUMBER() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS rn 
    FROM dedup
)

select d.name    as Department  ,  e.name as Employee   , e.salary  as Salary  from Employee as e 
join Department as d
on e.departmentId =d.id 
where (e.departmentId,e.salary) in ( select departmentId,  Salary from top_3  where rn<=3 );
