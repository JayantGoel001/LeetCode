# Write your MySQL query statement below
SELECT eun.unique_id, e.name FROM Employees as e LEFT JOIN EmployeeUNI as eun ON e.id=eun.id