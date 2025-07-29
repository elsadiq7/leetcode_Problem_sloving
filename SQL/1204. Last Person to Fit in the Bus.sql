# Write your MySQL query statement below
select person_name  from (select *  ,sum(weight ) over (order by turn) as RunningTotal
from Queue) as total
where total.RunningTotal <=1000
order by RunningTotal DESC
limit 1 ;