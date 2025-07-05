# Write your MySQL query statement below
select product_id ,year  as first_year  , quantity  ,price 
from 
(
    select *,RANK() Over (PARTITION BY product_id  order by year  ) as rn from Sales 
) as sales_first_year

where rn =1;