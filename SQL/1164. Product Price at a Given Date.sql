# Write your MySQL query statement below

SELECT product_id,
  CASE 
    WHEN change_date <= '2019-08-16' THEN new_price
    ELSE COALESCE((
      SELECT new_price
      FROM Products AS p2
      WHERE p2.product_id = p1.product_id
        AND p2.change_date <= '2019-08-16'
      ORDER BY change_date DESC
      LIMIT 1
    ),10)
  END AS price
FROM (
  SELECT *, 
         ROW_NUMBER() OVER (PARTITION BY product_id ORDER BY change_date DESC) AS rn
  FROM Products
) AS p1
WHERE rn = 1;
