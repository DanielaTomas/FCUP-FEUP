create table T1 (
Id NUMBER PRIMARY KEY,
Id2 NUMBER REFERENCES T2(Id));
create table T2 (
Id NUMBER PRIMARY KEY);
insert into T2 values (111);
insert into T2 values (222);
insert into T1 values (1,111);
insert into T1 values (2,333);
