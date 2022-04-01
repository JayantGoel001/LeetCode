SELECT S.name FROM SalesPerson AS S WHERE S.SALES_ID NOT IN (SELECT O.SALES_ID FROM ORDERS AS O LEFT JOIN COMPANY C ON O.COM_ID = C.COM_ID WHERE C.NAME = 'RED');