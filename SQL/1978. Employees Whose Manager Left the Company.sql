# Write your MySQL query statement below
select e.employee_id   from Employees  as e 
left join Employees  as ee
on e.manager_id=ee.employee_id 
WHERE ee.employee_id IS NULL and  e.manager_id >0  and e.salary <30000
ORDER by e.employee_id;