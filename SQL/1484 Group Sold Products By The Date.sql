
# Write your MySQL query statement below


SELECT 
   sell_date, 
  COUNT(*) AS num_sold, 
  GROUP_CONCAT(product ORDER BY product ASC SEPARATOR ',') AS products
FROM (select Distinct *  from  Activities) as dist_act
GROUP BY sell_date;
