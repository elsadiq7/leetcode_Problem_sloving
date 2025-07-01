-- Calculate the average processing time per machine
--link:https://leetcode.com/problems/average-time-of-process-per-machine/?envType=study-plan-v2&envId=top-sql-50
SELECT 
    prev.machine_id,
    ROUND(AVG(curr.timestamp - prev.timestamp), 3) AS processing_time
FROM 
    (SELECT * FROM Activity WHERE activity_type = 'start') AS prev
JOIN 
    (SELECT * FROM Activity WHERE activity_type = 'end') AS curr
ON 
    prev.machine_id = curr.machine_id 
    AND prev.process_id = curr.process_id
GROUP BY 
    prev.machine_id;
