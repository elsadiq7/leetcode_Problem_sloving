# Write your MySQL query statement below
select p.product_id, IFNULL(round(sum(u.units*p.price)/sum(u.units),2),0)  as average_price  from Prices as p 
left join  (select DISTINCT * from  UnitsSold ) as u
on p.product_id=u.product_id and u.purchase_date >=p.start_date and   u.purchase_date <=p.end_date     
group by p.product_id ;

--link:https://leetcode.com/problems/average-selling-price/?envType=study-plan-v2&envId=top-sql-50