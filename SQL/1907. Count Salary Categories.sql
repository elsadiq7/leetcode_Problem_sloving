
SELECT 'High Salary' AS category, sum(CASE WHEN income > 50000 THEN 1 ELSE 0 END) AS accounts_count
FROM Accounts
UNION ALL

SELECT 'Low Salary' AS category,  sum(CASE WHEN income <20000 THEN 1 ELSE 0 END) AS accounts_count
FROM Accounts

UNION ALL

SELECT 'Average Salary' AS category,  sum(CASE WHEN income >=20000 and income <=50000 THEN 1 ELSE 0 END) AS accounts_count
FROM Accounts
