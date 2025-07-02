# Write your MySQL query statement below
# link: https://leetcode.com/problems/students-and-examinations/
select s.student_id ,s.student_name  ,sub.subject_name , COUNT(e.subject_name) AS attended_exams from Students as s 
CROSS JOIN Subjects as sub 
Left join  Examinations as e 
on s.student_id=e.student_id and sub.subject_name=e.subject_name
group by  s.student_id,sub.subject_name
order by s.student_id,sub.subject_name;


