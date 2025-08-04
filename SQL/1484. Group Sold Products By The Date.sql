# Write your MySQL query statement below
select p.product_name ,  sum(o.unit) as unit     from Products as p 
join Orders o 
on p.product_id  =o.product_id
where  DATE_FORMAT(o.order_date , '%M %Y')='February 2020'
group by product_name 
having unit>=100 ;         
