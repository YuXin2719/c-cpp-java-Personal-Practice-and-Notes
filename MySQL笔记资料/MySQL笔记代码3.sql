select avg(level) from player;
select * from player where level > (select avg(level) from player);
select level,(select avg(level) from player) from player;
select level,round((select avg(level) from player)) from player;
select level,round((select avg(level) from player)) as average,level-round((select avg(level) from player)) as diff from player;
select * from player where level<5;
create table new_player1 select * from player where level<5;
show tables;
select * from new_player1;
select * from player where level between 6 and 10;
insert into new_player1 select * from player where level between 6 and 10;
select exists(select * from player where level>100);

desc player;
desc equip;
select * from player p,equip e
where p.id = e.player_id;
select * from player p,equip e；