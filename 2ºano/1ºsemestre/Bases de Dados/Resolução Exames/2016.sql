PRAGMA foreign_keys=ON;
.mode columns
.headers on
.nullvalue NULL

--epoca normal
/*
--5.1
select Estudante.nome,Curso.nome from Estudante,Curso
where Curso.ID = curso and anoCurricular = 3;
*/
/*
--5.2
select nome,anoCurricular
 from Estudante,(select ID1,count(*) as numAmigos from Amizade group by ID1) as T1
 where Estudante.ID = T1.ID1 and
  numAmigos in (select max(amigos) from (select ID1,count(ID1) as amigos from Amizade group by ID1))
group by ID1;
*/
/*
--5.3
create trigger if not exists insercaoEstudantes
after insert on Estudante
for each row
begin
 insert into Amizade(ID1,ID2)
 select e1.ID as ID1, e2.ID as ID2
  from Estudante as e1, Estudante as e2
  where (e1.ID = NEW.ID or e2.Estudante = New.ID) and e1.curso = e2.curso and e1.ID <> e1.ID2;
end;
*/
/*
--5.4
select nome,anoCurricular from Estudante
where ID not in
(select distinct ID from Estudante as e, Amizade as a
  where e.ID = a.ID1 and a.ID2 in
  (select ID from Estudante where anoCurricular <> e.anoCurricular))
 and ID in(select ID1 from Amizade)
group by nome
order by anoCurricular,nome;
*/
/*
--5.5
select nome from Estudante,Amizade
where Estudante.ID = Amizade.ID1
group by nome
having count(ID1) > 3;
*/
/*
--5.6
select distinct ID2 as ID from Amizade where ID1 in(
 select distinct ID2 from Amizade where ID1 in(
  select distinct ID2 from Amizade where ID1 in(
   select ID from Estudante
    where nome = "Miguel Sampaio"
  )
 )
);
*/

--recurso
/*
--9
select nome from Estudante,Amizade
where Estudante.ID = Amizade.ID1
and ID2 in (select ID from Estudante where nome like "Gabriel%");
*/
/*
--11
select nome from (
  select distinct nome,count(anoCurricular) as num from (
    select distinct e1.nome,e2.anoCurricular from Estudante e1, Estudante e2, Amizade
    where ID1 = e1.ID and ID2 = e2.ID
  ) group by nome
) where num = 5;
*/
/*
--13
select e1.nome,e2.nome from Estudante e1, Estudante e2, Amizade
 where e1.ID = Amizade.ID1 and e2.ID = Amizade.ID2 and e1.curso <> e2.curso
 and ((ID1 < ID2) or ((ID1,ID2) in (
   select e1.nome,e2.nome from Estudante e1, Estudante e2, Amizade
   where e1.ID = Amizade.ID1 and e2.ID = Amizade.ID2 and e1.curso <> e2.curso))
 );
*/
