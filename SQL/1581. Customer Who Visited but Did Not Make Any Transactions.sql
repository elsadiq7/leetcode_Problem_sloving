# Write your MySQL query statement below
#link:https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/?envType=study-plan-v2&envId=top-sql-50
select customer_id ,count(Visits.visit_id ) as count_no_trans  from Visits
left join Transactions 
on  Visits.visit_id =Transactions.visit_id
where transaction_id  is NULL
GROUP BY Visits.customer_id;
