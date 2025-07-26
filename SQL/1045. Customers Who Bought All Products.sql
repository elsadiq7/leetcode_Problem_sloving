-- Get customers who purchased all products
SELECT customer_id
FROM (
    SELECT 
        c.customer_id,
        COUNT(DISTINCT c.product_key) AS product_count
    FROM Customer AS c
    JOIN Product AS p 
        ON c.product_key = p.product_key
    GROUP BY c.customer_id
    HAVING product_count = (
        SELECT COUNT(DISTINCT product_key) 
        FROM Product
    )
) AS final;
