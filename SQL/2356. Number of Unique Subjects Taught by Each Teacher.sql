# Write your MySQL query statement below
select teacher_id ,count( Distinct subject_id ) as cnt from Teacher
group by teacher_id;
-- #link:https://leetcode.com/problems/number-of-unique-subjects-taught-by-each-teacher/
-- #id:2356