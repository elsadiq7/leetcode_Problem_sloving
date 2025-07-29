-- # Write your MySQL query statement below
SELECT 
    emp.employee_id, 
    emp.name,  
    report_age.count_ AS reports_count,
    ROUND(report_age.age / report_age.count_) AS average_age
FROM 
    Employees AS emp
JOIN (
    SELECT 
        reports_to, 
        COUNT(reports_to) AS count_, 
        SUM(age) AS age 
    FROM  
        Employees 
    GROUP BY     
        reports_to
) AS report_age
ON  
    emp.employee_id = report_age.reports_to
ORDER BY 
    emp.employee_id;
