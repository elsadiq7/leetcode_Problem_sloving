# Write your MySQL query statement below
select activity_date as day  ,count(Distinct user_id ) as active_users  from Activity 
group by activity_date
having DATEDIFF("2019-07-27",activity_date)<=29 and DATEDIFF("2019-07-27",activity_date)>=0 and active_users >0;

-- #link:https://leetcode.com/problems/user-activity-for-the-past-30-days-i/
-- #id:1141