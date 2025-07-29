# Write your MySQL query statement below
select (s.id -1) as id ,student  from Seat as s 
where  s.id%2=0
union all 

select  case 
        when  ss.id!= (select count(*) from Seat )      then (ss.id+1) 
        else  ss.id 
        end as id ,student  from Seat as ss
where  ss.id%2!=0  
order by id; 
 



# Write your MySQL query statement below

select  case 
        when  ss.id%2!=0 and ss.id <(select count(*) from Seat )      then (ss.id+1) 
        when  ss.id%2=0  then (ss.id -1)
        else ss.id 

        end as id ,student  from Seat as ss
order by id; 
 

 
