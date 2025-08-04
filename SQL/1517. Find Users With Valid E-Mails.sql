# Write your MySQL query statement below
select * from Users 
where   mail COLLATE utf8mb3_bin   regexp  "^[a-zA-Z][a-zA-Z0-9._-]*@leetcode\\.com$" ;