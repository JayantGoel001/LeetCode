SELECT customer_number FROM ORDERS GROUP BY customer_number HAVING COUNT(*) = (SELECT COUNT(*) FROM ORDERS GROUP BY customer_number ORDER BY COUNT(*) DESC LIMIT 1); 