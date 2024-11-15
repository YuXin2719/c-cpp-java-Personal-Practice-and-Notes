create database db1;
use db1;
create table account(
id int,
name varchar(100),
money int
);
insert into account values(1,'张三',1000);
insert into account values(2,'李四',1000);

select * from account;

update account set money=1000 where id=1;
update account set money=1000 where id=2;