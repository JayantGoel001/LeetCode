select
    a.name,
    sum(b.amount) balance
from
    Users a
join
    Transactions b
on
    a.account = b.account
group by
    a.account
having
    balance > 10000;