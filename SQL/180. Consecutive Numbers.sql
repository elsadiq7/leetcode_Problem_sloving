-- sol 1 
# Write your MySQL query statement below
select  DISTINCT  num1 as ConsecutiveNums  from (select l1.id as id1 ,l1.num as num1 , l2.id as id2 , l2.num as num2 , l3.id as id3, l3.num as num3  from Logs  as l1
join Logs as l2  
on  l1.id=l2.id-1
join Logs as l3
on  l1.id=l3.id-2) as cons 
where cons.num1=cons.num2 and cons.num1=cons.num3;

-- sol 2 
# Write your MySQL query statement below
select  DISTINCT  num as ConsecutiveNums
from (
    select 
    num,
    lag(num,1) Over (order by id ) AS prev1,
    lag(num,2)  Over (order by id ) AS prev2
    from Logs  
) as cons 

where cons.num=cons.prev1 and cons.num=cons.prev2;