PRAGMA foreign_keys=ON;
.mode columns
.headers on
.nullvalue NULL

/*
--8.1
select caption from Photo,User
where Photo.user = User.id
   and User.name = "Daniel Ramos"
   and julianday(uploadDate) - julianday(creationDate) = 2;
*/
/*
--8.2
select name from User where id not in (select user from Photo);
*/
/*
--8.3
select avg(num) as Média from (
  select count(user) as num from AppearsIn
  where photo in (
    select photo from (select photo from Likes group by photo having count(user) > 3)
  ) group by photo
);
*/
/*
--8.4
select caption from Photo where id in (
  select photo from AppearsIn
  where user in (
    select id from User where name
  )
)
*/
