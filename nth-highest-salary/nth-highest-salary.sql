CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      SELECT max(salary) from (select salary,dense_rank() over(order by salary desc) as rk from employee) t
      where t.rk = N
      
  );
END