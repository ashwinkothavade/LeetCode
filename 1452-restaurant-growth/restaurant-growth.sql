# Write your MySQL query statement below
select a.visited_on as visited_on,sum(b.amount) as amount,round(avg(b.amount),2) as average_amount
from (select visited_on,sum(amount) as amount from Customer group by visited_on) a 
join (select visited_on,sum(amount) as amount from customer group by visited_on) b
on datediff(a.visited_on,b.visited_on)between 0 and 6
group by a.visited_on
having count(a.visited_on)=7;