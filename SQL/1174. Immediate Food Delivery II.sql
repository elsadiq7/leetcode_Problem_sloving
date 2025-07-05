SELECT 
    ROUND(
        100.0 * SUM(CASE WHEN order_date = customer_pref_delivery_date THEN 1 ELSE 0 END) 
        / COUNT(order_date),
    2) AS immediate_percentage
FROM (
    SELECT *
    FROM (
        SELECT *, ROW_NUMBER() OVER (PARTITION BY customer_id ORDER BY order_date) AS rn
        FROM Delivery
    ) AS sub
    WHERE rn = 1
) AS first_orders;
