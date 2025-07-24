-- Get classes with at least 5 students
SELECT class
FROM (
    SELECT class, COUNT(student) AS student_count
    FROM Courses
    GROUP BY class
    HAVING COUNT(student) >= 5
) AS class_counts;
