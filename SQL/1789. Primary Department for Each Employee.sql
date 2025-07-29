# Write your MySQL query statement below
SELECT e.employee_id, e.department_id
FROM Employee AS e
JOIN (
    SELECT employee_id, COUNT(*) AS dept_count
    FROM Employee
    GROUP BY employee_id
) AS emp_counts
ON e.employee_id = emp_counts.employee_id
WHERE e.primary_flag = 'Y' 
   OR (e.primary_flag = 'N' AND emp_counts.dept_count = 1);
