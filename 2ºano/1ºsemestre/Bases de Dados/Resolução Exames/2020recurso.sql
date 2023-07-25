PRAGMA foreign_keys=ON;
.mode columns
.headers on
.nullvalue NULL

-- 16.
/*
select Name,Title,Country
from Speaker,Talk where Speaker.id = Talk.speaker
order by Country;
*/

-- 17.
/*
select Name
from Speaker,Talk where Speaker.id = Talk.speaker
group by speaker
having count(*) > 1
order by Name;
*/

-- 18.
/*
select Name
from Topic where Topic.Id
not in (select topic from Talk)
order by Name;
*/

-- 19.
/*
select Name,count(Day) as "#days"
from (select distinct Day,Name from Topic,Talk where Topic.Id = Talk.topic or Day is null)
group by Name
order by Name;
*/




















--
