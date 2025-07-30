SELECT 
  visited_on,
  (
    SELECT SUM(b.amount)
    FROM Customer b
    WHERE b.visited_on BETWEEN DATE_SUB( c.visited_on , INTERVAL 6 DAY) AND c.visited_on
  ) AS amount,
   (
    SELECT round(SUM(b.amount)/7,2)
    FROM Customer b
    WHERE b.visited_on BETWEEN DATE_SUB( c.visited_on,  INTERVAL 6 DAY) AND c.visited_on 
  ) AS average_amount
FROM Customer c
where visited_on >=
   (select DATE_ADD(min(visited_on), INTERVAL 6 DAY) from customer)
group  BY c.visited_on;
