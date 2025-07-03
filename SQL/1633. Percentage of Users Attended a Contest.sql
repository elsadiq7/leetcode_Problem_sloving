# Write your MySQL query statement below
select r.contest_id ,round ( 100*count(u.user_id ) / (SELECT COUNT(*) FROM Users
),2) as percentage  from register as r 
left join Users as u 
on  r.user_id=u.user_id
group by r.contest_id
order by percentage DESC ,r.contest_id ASC ;

--link:https://leetcode.com/problems/percentage-of-users-attended-a-contest/