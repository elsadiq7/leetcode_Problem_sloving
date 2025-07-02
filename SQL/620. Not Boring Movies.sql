# Write your MySQL query statement below
select id,movie ,description  ,rating  from Cinema
where description !='boring' and id%2=1
order by rating desc;
-- #link:https://leetcode.com/problems/not-boring-movies/
-- #id:620