# Write your MySQL query statement below
# link: https://leetcode.com/problems/employee-bonus/
select  emp.name , bon.bonus from Employee as emp
left join Bonus  as bon
on emp.empId=bon.empId 
where bon.bonus <1000 or bon.bonus is Null;