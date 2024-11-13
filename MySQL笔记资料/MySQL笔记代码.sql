create table player(
id int,
name varchar(100),
level int,
exp int,
gold decimal(10,2)
);
insert into player(id,name,level,exp,gold) values(1,'张三',1,1,1);
insert into player values(2,'李四',2,2,2);
insert into player(id,name) values(3,'赵六');

select * from player;

insert into player(id,name) values(4,'王五'),(5,'李二');

alter table player modify level int default 1;
insert into player(id,name) values(6,'曹操');

update player set level=1 where name='赵六';
update player set level=1 where name='王五';
update player set level=1 where name='李二';
update player set exp=0,gold=0;

delete from player where gold=0;
select * from player;