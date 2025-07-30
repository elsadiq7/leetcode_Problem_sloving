# Write your MySQL query statement below

with UniqueLocations as ( 
   SELECT  lat, lon
    FROM Insurance
    GROUP BY lat, lon
    HAVING COUNT(*) = 1
),
 Uniquetiv_2015  as ( 
   SELECT  tiv_2015
    FROM Insurance
    GROUP BY tiv_2015
    HAVING COUNT(*) > 1
)

select round(sum(tiv_2016),2) as tiv_2016 from Insurance 
where (lat,lan) in (SELECT lat, lon FROM UniqueLocations)    and tiv_2015 in (select tiv_2015  from Uniquetiv_2015 );


