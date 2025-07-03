# Write your MySQL query statement below
select query_name, 
       round (sum(rating /position )/count(rating ),2) as quality,
       round (100*sum(case when rating <3 then 1 else 0 end )/count(rating),2) as poor_query_percentage 
from Queries
group by query_name ;

--link:https://leetcode.com/problems/queries-quality-and-percentage/