Pragma Foreign_Keys = on;
.mode columns
.headers on
drop table if exists T;
create table T (A text, B text);
insert into T values ('Hello,', 'world!');
select * from T;
